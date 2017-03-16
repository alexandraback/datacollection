#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int counts[30];
void subtract(char c, int x)
{
    counts[c-'A'] -= x;
}

int main()
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; ++z) {
        memset(counts,0,sizeof(counts));
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); ++i) {
            counts[s[i]- 'A']++;
        }
        int outp[10];
        memset(outp,0,sizeof(outp));
        outp[0] = counts['Z'-'A'];
        subtract('E', outp[0]);
        subtract('R',outp[0]);
        subtract('O',outp[0]);
        subtract('Z',outp[0]);
        outp[2] = counts['W'-'A'];
        subtract('T', outp[2]);
        subtract('W', outp[2]);
        subtract('O', outp[2]);
        outp[6] = counts['X'-'A'];
        subtract('S',outp[6]);
        subtract('I',outp[6]);
        subtract('X',outp[6]);
        outp[4] = counts['U'-'A'];
        subtract('F',outp[4]);
        subtract('O',outp[4]);
        subtract('U',outp[4]);
        subtract('R',outp[4]);
        outp[5] = counts['F'-'A'];
        subtract('F',outp[5]);
        subtract('I',outp[5]);
        subtract('V',outp[5]);
        subtract('E',outp[5]);
        outp[3] = counts['R'-'A'];
        subtract('T',outp[3]);
        subtract('H',outp[3]);
        subtract('R',outp[3]);
        subtract('E',outp[3]);
        subtract('E',outp[3]);
        outp[8] = counts['T'-'A'];
        subtract('E',outp[8]);
        subtract('I',outp[8]);
        subtract('G',outp[8]);
        subtract('H',outp[8]);
        subtract('T',outp[8]);
        outp[1] = counts['O'-'A'];
        subtract('O',outp[1]);
        subtract('N',outp[1]);
        subtract('E',outp[1]);
        outp[7] = counts['V'-'A'];
        subtract('S',outp[7]);
        subtract('E',outp[7]);
        subtract('V',outp[7]);
        subtract('E',outp[7]);
        subtract('N',outp[7]);
        outp[9] = counts['I'-'A'];
        subtract('N',outp[9]);
        subtract('I',outp[9]);
        subtract('N',outp[9]);
        subtract('E',outp[9]);
        cout << "Case #" << z << ": ";
        for (int i = 0; i <= 9; ++i) {
            for (int j = 0; j < outp[i]; ++j)
                cout << i;
        }
        cout << endl;
    }
}
