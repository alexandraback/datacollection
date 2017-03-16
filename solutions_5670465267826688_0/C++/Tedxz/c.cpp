#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int MAX_P = 1007;

int abs(int x) {
    if (x < 0) return -x;
    return x;
}

int code(char c)  {
    if (c == 'i')
        return 2;
    if (c == 'j')
        return 3;
    if (c == 'k')
        return 4;
    while (1);
    return 0;
}

int trans[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4},
    {0, 2, -1, 4, -3},
    {0, 3, -4, -1, 2},
    {0, 4, 3, -2, -1},
};

long long T, ans;
long long l, x;
string s;

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("c.txt", "w", stdout);
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        cin >> l >> x;
        cin >> s;
        if (x > 12)
            x = (x - 12) % 4 + 12;

        int ch = 1, sgn = 1;
        //find i
        int ipos = -1;
        for (int i = 0; i < x * l; ++i) {
            int idx = i % l;
            ch = trans[abs(ch)][code(s[idx])];
            if (ch < 0) {
                sgn = -sgn;
                ch = -ch;
            }
            if (ch == 2 && sgn == 1) {
                ipos = i;
                break;
            }
        }
        
        
        //find j
        int jpos = -1;
        ch = 1, sgn = 1;
        for (int i = ipos + 1; i < x * l; ++i) {
            int idx = i % l;
            ch = trans[abs(ch)][code(s[idx])];
            if (ch < 0) {
                sgn = -sgn;
                ch = -ch;
            }
            if (ch == 3 && sgn == 1) {
                jpos = i;
                break;
            }
        }
        
        //find k
        ch = 1, sgn = 1;
        for (int i = jpos + 1; i < x * l; ++i) {
            int idx = i % l;
            ch = trans[abs(ch)][code(s[idx])];
            if (ch < 0) {
                sgn = -sgn;
                ch = -ch;
            }
        }

        cout << "Case #" << cs << ": ";
        if (jpos > 0 &&  ch == 4 && sgn == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
