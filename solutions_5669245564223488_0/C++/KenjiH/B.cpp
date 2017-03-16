#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define MP(x,y) make_pair(x,y)
#define REP(i,n) for(int i=0; i<(int)(n); i++)

int N;
string s[10];
vector<int> vs[10];
int p[10];

void solve() {
    cin >> N;
    REP (i, N)
        cin >> s[i];

    REP (i, N) {
        vs[i].clear();

        REP (j, s[i].length()) {
            if (j == 0 || s[i][j-1] != s[i][j])
                vs[i].push_back(s[i][j] - 'a');
        }

        set<int> st;
        REP (j, vs[i].size())
            st.insert(vs[i][j]);
        if (st.size() != vs[i].size()) {
            cout << 0 << endl;
            return;
        }
    }

    REP (i, N) p[i] = i;
    int ret = 0;
    do {
        bool ck = true;

        int ll[26];
        REP (i, 26) ll[i] = -1;
        int pos = 0;
        REP (i, N) {
            REP (j, vs[p[i]].size()) {
                int x = vs[p[i]][j];
                if (ll[x] != -1 && ll[x] != pos-1) {
                    ck = false;
                    goto nxt;
                }
                ll[x] = pos;
                ++pos;
            }
        }

    nxt:
        if (ck)
            ++ret;

    } while (next_permutation(p, p+N));
    
    
    cout << ret << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    REP (i, T) {
        cerr << "Case #" << i+1 << ": " << endl;
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
