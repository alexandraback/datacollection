#define _CRT_SECURE_NO_WARNINGS

#include <cctype>
#include <climits>
#include <cmath>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <ratio>
#include <regex>
#include <string>
#include <tuple>
#include <utility>
#include <valarray>

using namespace std;

#define INF ULLONG_MAX
#define MIN LLONG_MIN
#define pi 3.1415926535897932384626433832795

#define sz(v) v.size()
#define pb(x) push_back(x)
#define fill(v,n,x) for(int i=0;i<(int)n;i++) v.push_back(x)
#define FOR(i,n) for(i=0;i<n;i++)
#define re return
#define sum(v) accumulate(v.begin(),v.end(),0)
#define asrt(v) sort(v.begin(),v.end())
#define dsrt(v) sort(v.rbegin(),v.rend())
#define rev(v) reverse(v.begin(),v.end())
#define print(v) for (auto& i:v) cout<<i<<endl
#define print "Case #"+to_string(t1)+": "

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;



int main() {
    freopen("c.in", "r", stdin);
    freopen("c.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t1 = 1; t1 <= T; t1++) {
        int C, D, V;
        cin >> C >> D >> V;
        vi vv;
        for (int i = 0; i < D; i++) {
            int x;
            cin >> x;
            vv.push_back(x);
        }
        vvi CC;
        for (int m = 0; m <= V; m++) {
            vi t;
            for (int j = 0; j <= V; j++) {
                t.push_back(0);
            }
            CC.push_back(t);
        }
        CC[0][0] = 1;
        for (int i = 1; i <= D; i++) {
            int x = vv[i-1];
            for (int j = 0; j <= V; j++) {
                if (j>=x && CC[i-1][j - x]) {
                    CC[i][j] = 1;
                }
                else if (CC[i - 1][j]) CC[i][j] = 1;
            }
        }
        int pos = D+1,cc=0;
        for (int i = 1; i <= V; i++) {
            if (CC[pos-1][i]) continue;
            cc++;
            int x =i;
            for (int j = 0; j <= V; j++) {
                if (j >= x && CC[pos - 1][j - x]) {
                    CC[pos][j] = 1;
                }
                else if (CC[pos - 1][j]) CC[pos][j] = 1;
            }
            pos++;
        }
        cout << print << cc << endl;
    }
    getchar();
    return 0;
}

