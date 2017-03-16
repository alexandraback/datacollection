#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <memory.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define forv(i, a) forn(i, (int)(a).size())

typedef long long lng;

int op[4][4] = 
{
    {1, 2, 3, 4},
    {2, 1, 4, 3},
    {3, 4, 1, 2},
    {4, 3, 2, 1}
};
int sign[4][4] =
{
    {1, 1, 1, 1},
    {1, -1, 1, -1},
    {1, -1, -1, 1},
    {1, 1, -1, -1}
};

int mult[8][8];
int code[128];

void fill_tables() {
    code['i'] = 1;
    code['j'] = 2;
    code['k'] = 3;

    forn(i, 8) {
        forn(j, 8) {
            int to = op[i%4][j%4] - 1;
            int s = sign[i%4][j%4];

            s *= (i > 3) ? -1 : 1;
            s *= (j > 3) ? -1 : 1;

            if(s < 0) {
                to += 4;
            }

            mult[i][j] = to;
        }
    }
}

char str[200500];
int pref[200500];
int suf[200500];
long long len, x;

void read_input() {
    cin >> len >> x;

    if (x >= 20) {
        x = 16 + x%4;
    }

    cin >> str;
    forn(i, x-1) {
        memcpy(str + len * (i + 1), str, len);
    }
    len *= x;
}

bool solve() {
    read_input();

    pref[0] = code[str[0]];
    for(int i = 1; i < len; ++i) {
        pref[i] = mult[pref[i-1]][code[str[i]]];
    }

    suf[len-1] = code[str[len-1]];
    for(int i = len-2; i >= 0; --i) {
        suf[i] = mult[code[str[i]]][suf[i+1]];
    }

    int left = -1;
    forn(i, len-1) {
        if(pref[i] == 1 && suf[i+1] == 1) {
            left = i;
            break;
        }
    }

    int right = -1;
    for(int i = len-1; i >= 1; --i) {
        if(suf[i] == 3 && pref[i-1] == 3) {
            right = i;
            break;
        }
    }

    return (pref[len-1] == 4 &&
            left != -1 &&
            right != -1 &&
            left < right);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    fill_tables();

    int T;
    cin >> T;
    forn(tc, T) {
        std::cout << "Case #" << tc + 1 << ": ";
        if(solve()) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }

        cout << endl;
    }
    
    return 0;
}
