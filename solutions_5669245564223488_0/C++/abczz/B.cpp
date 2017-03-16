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

bool Check(int per[]) {
    string t = "";
    REP(i, n) t += s[per[i]];
    //cout << "t = " << t << endl;
    int p[200];
    FILL(p, 0xff);
    REP(i, t.length()) {
        if (p[t[i]] == -1) {
            p[t[i]] = i;
        } else {
            if (p[t[i]] + 1 != i) {
                return false;
            } else {
                p[t[i]] = i;
            }
        }
    }
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
    int cnt = 0;
    if (!flag) {
        cout << 0 << endl;
        return;
    }
    int p[100];
    REP(i, n) p[i] = i;
    do {
        if (Check(p)) {
            ++cnt;
        }
    } while (next_permutation(p, p + n));
    cout << cnt << endl;
}

int main() {
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
    int cas;
    cin >> cas;
    for (int T = 1; T <= cas; ++T) {
        printf("Case #%d: ", T);
        Solve();
    }
    return 0;
}

