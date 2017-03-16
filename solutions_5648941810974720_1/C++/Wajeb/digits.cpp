#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        string s;
        cin >> s;
        int digits[30];

        for(int i = 0; i < 30; i++) digits[i] = 0;

        int n = s.length();
        for(int i = 0; i < n; i++) digits[s[i] - 'A']++;

        int num0 = digits['Z' - 'A'];
        digits['Z' - 'A'] -= num0;
        digits['E' - 'A'] -= num0;
        digits['R' - 'A'] -= num0;
        digits['O' - 'A'] -= num0;
        
        int num2 = digits['W' - 'A'];
        digits['T' - 'A'] -= num2;
        digits['W' - 'A'] -= num2;
        digits['O' - 'A'] -= num2;

        int num = digits['U' - 'A'];
        int num4 = num;
        digits['F' - 'A'] -= num;
        digits['O' - 'A'] -= num;
        digits['U' - 'A'] -= num;
        digits['R' - 'A'] -= num;

        num = digits['X' - 'A'];
        int num6 = num;
        digits['S' - 'A'] -= num;
        digits['I' - 'A'] -= num;
        digits['X' - 'A'] -= num;

        num = digits['G' - 'A'];
        int num8 = num;
        digits['E' - 'A'] -= num;
        digits['I' - 'A'] -= num;
        digits['G' - 'A'] -= num;
        digits['H' - 'A'] -= num;
        digits['T' - 'A'] -= num;

        num = digits['S' - 'A'];
        int num7 = num;
        digits['S' - 'A'] -= num;
        digits['E' - 'A'] -= num;
        digits['V' - 'A'] -= num;
        digits['E' - 'A'] -= num;
        digits['N' - 'A'] -= num;

        num = digits['V' - 'A'];
        int num5 = num;
        digits['F' - 'A'] -= num;
        digits['I' - 'A'] -= num;
        digits['V' - 'A'] -= num;
        digits['E' - 'A'] -= num;

        num = digits['O' - 'A'];
        int num1 = num;
        digits['O' - 'A'] -= num;
        digits['N' - 'A'] -= num;
        digits['E' - 'A'] -= num;

        num = digits['H' - 'A'];
        int num3 = num;
        digits['T' - 'A'] -= num;
        digits['H' - 'A'] -= num;
        digits['R' - 'A'] -= num;
        digits['E' - 'A'] -= num;
        digits['E' - 'A'] -= num;

        num = digits['I' - 'A'];
        int num9 = num;
        digits['N' - 'A'] -= num;
        digits['I' - 'A'] -= num;
        digits['N' - 'A'] -= num;
        digits['E' - 'A'] -= num;

        string res = "";
        for(int i = 0; i < num0; i++) res = res + "0";
        for(int i = 0; i < num1; i++) res = res + "1";
        for(int i = 0; i < num2; i++) res = res + "2";
        for(int i = 0; i < num3; i++) res = res + "3";
        for(int i = 0; i < num4; i++) res = res + "4";
        for(int i = 0; i < num5; i++) res = res + "5";
        for(int i = 0; i < num6; i++) res = res + "6";
        for(int i = 0; i < num7; i++) res = res + "7";
        for(int i = 0; i < num8; i++) res = res + "8";
        for(int i = 0; i < num9; i++) res = res + "9";

        cout << "Case #" << t << ": " << res << endl;
    }


    return 0;
}
