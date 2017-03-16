#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>

#define REP(i,n) for(int i=0;i<(n);i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define SIZE(x) (int)(x).size()

#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int MOD = 1e9+7;

int n;
string s[110];
int in[200], out[200];
LL f[110];
bool can[200];

bool Check() {
    bool have[110][200];
    CLEAR(have);
    REP(i, n) {
        TR(it, s[i]) {
            have[i][*it] = true;
        }
    }
    REP(i, n) {
        for (int j = 1; j < s[i].length() - 1; ++j) {
            REP(k, n) {
                if (k != i && have[k][s[i][j]]) {
                    return false;
                } 
            }
        }
    }
    CLEAR(in);
    CLEAR(out);
    CLEAR(can);
    REP(i, n) {
        int l = s[i].length();
        can[s[i][0]] = can[s[i][l - 1]] = true;
        if (l > 1) {
            out[s[i][0]]++;
            in[s[i][l - 1]]++;
        }
    }
    for (int i = 'a'; i <= 'z'; ++i) if (in[i] > 1 || out[i] > 1) return false;
    return true;
}

bool Gao(string &str) {
    int p[200];
    FILL(p, 0xff);
    string x = "";
    REP(i, str.length()) {
        if (p[str[i]] == -1) {
            p[str[i]] = i;
            x += str[i];
        } else {
            if (p[str[i]] + 1 != i) {
                return false;
            } else {
                p[str[i]] = i;
            }
        }
    }
    str = x;
    return true;
}

void Solve() {
    cin >> n;
    bool flag = true;
    REP(i, n) {
        cin >> s[i];
        flag = Gao(s[i]);
    }
    if (!flag || !Check()) {
        cout << 0 << endl;
        return;
    }
//    cout << "s:" << endl;
//    REP(i, n) cout << s[i] << endl;
    LL ans = 1;
    int m = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
        if (can[i]) {
            int cnt = 0;
            REP(j, n) if (s[j].length() == 1 && s[j][0] == i) {
                ++cnt;
            }
            ans = ans * f[cnt] % MOD;
            if (in[i] == 0) {
                ++m;
            }
        }
    }
//    cout << "m = " << m << endl;
    ans = ans * f[m] % MOD;
    cout << ans << endl;
}

int main() {
//    freopen("B.in", "r", stdin);
    //	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
    //	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
    //	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
    	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
    int cas;
    f[0] = 1;
    for (int i = 1; i <= 100; ++i) f[i] = f[i - 1] * i % MOD;
    cin >> cas;
    for (int T = 1; T <= cas; ++T) {
        printf("Case #%d: ", T);
        Solve();
    }
    return 0;
}

