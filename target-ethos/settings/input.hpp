struct InputSettings : SettingsLayout {
  HorizontalLayout focusLayout;
    Label focusLabel;
    CheckLabel focusPause;
    CheckLabel focusAllow;
  HorizontalLayout selectionLayout;
    ComboButton systemList;
    ComboButton portList;
    ComboButton deviceList;
  ListView inputList;
  HorizontalLayout controlLayout;
    Button assign[3];
    Widget spacer;
    Button resetButton;
    Button eraseButton;

  void synchronize();

  Emulator::Interface& activeSystem();
  Emulator::Interface::Port& activePort();
  Emulator::Interface::Device& activeDevice();

  void systemChanged();
  void portChanged();
  void deviceChanged();
  void inputChanged();
  void resetInput();
  void eraseInput();
  void assignInput();
  void assignMouseInput(unsigned n);
  void inputEvent(HID::Device& device, unsigned group, unsigned input, int16_t oldValue, int16_t newValue, bool allowMouseInput = false);
  InputSettings();

private:
  AbstractInput* activeInput = nullptr;
};

extern InputSettings* inputSettings;
