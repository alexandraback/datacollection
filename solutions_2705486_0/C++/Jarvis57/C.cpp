#include <ctime>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <deque>
#include <complex>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
using namespace std;

int f[55][55];
char a[55];
string s;

string words[600111];
int nWord;

void init() {
    fstream f ("dict.txt", fstream :: in);
    while (f >> words[nWord+1]) ++nWord;
}

int main() {
    int ntest; scanf("%d\n", &ntest);
    init();
    FOR(test,1,ntest) {
        gets(a); s = ' ' + string(a);
        memset(f, -1, sizeof f);
        int n = strlen(a);

        f[0][0] = 0;
        bool can; int now, cnt;
        FOR(i,0,n-1) FOR(tmplast,0,i) if (f[i][tmplast] >= 0) {
            int last = tmplast; if (!last) last = -100;

            FOR(w,1,nWord) {
                int l = words[w].length();
                if (i+l <= n+1) {
                    can = true;
                    now = last; cnt = 0;

                    for(int x = i+1, y = 0; y < l; x++, y++) {
                        if (words[w][y] != s[x]) {
                            ++cnt;
                            if (x - now < 5) {
                                can = false;
                                break;
                            }
                            else now = x;
                        }
                    }
                    if (can) {
                        if (now < 0) now = 0;
                        if (f[i+l][now] < 0) f[i+l][now] = f[i][tmplast] + cnt;
                        else f[i+l][now] = min(f[i+l][now], f[i][tmplast] + cnt);
                    }
                }
            }
        }

        int res = 1000111000;
        FOR(last,0,n)
        if (f[n][last] >= 0)
            res = min(res, f[n][last]);

        printf("Case #%d: %d\n", test, res);
        cerr << test << endl;
    }
    cerr << clock() << endl;
    return 0;
}
