#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

char upper[4] = {'E', 'I', 'J', 'K'};
char lower[4] = {'1', 'i', 'j', 'k'};

char flip(char a, bool& sign)
{
    for (int i = 0; i < 4; i++) {
        if (a == upper[i]) {
            sign = !sign;
            return lower[i];
        }
    }
    return a;
}

char mult(char a, char b)
{
    bool sign = false;
    a = flip(a, sign); b = flip(b, sign);
    char res;
    if (a == '1') res = b;
    else if (b == '1') res = a;
    else if (a == b) res = 'E';
    else if (a == 'i' && b == 'j') res = 'k';
    else if (a == 'j' && b == 'i') res = 'K';
    else if (a == 'i' && b == 'k') res = 'J';
    else if (a == 'k' && b == 'i') res = 'j';
    else if (a == 'j' && b == 'k') res = 'i';
    else if (a == 'k' && b == 'j') res = 'I';
    if (sign) {
        for (int i = 0; i < 4; i++) {
            if (res == lower[i])
                return upper[i];
            if (res == upper[i])
                return lower[i];
        }
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int L, X;
        string s, str, cum;
        cin >> L >> X >> s;
        for (int i = 0; i < X; i++)
            str += s;

        int lastk = -1, firsti = (str[0] == 'i' ? 0 : str.size());
        cum.push_back(str[0]);
        for (int i = 1; i < str.size(); i++) {
            cum.push_back(mult(cum[i-1], str[i]));
            if (cum[i] == 'k') lastk = i;
            else if (cum[i] == 'i' && i < firsti) firsti = i;
        }
//        cout << cum << endl;
        if (cum[str.size()-1] != 'E' || firsti > lastk)
            cout << "Case #" << c << ": NO" << endl;
        else
            cout << "Case #" << c << ": YES" << endl;
    }
    return 0;
}
