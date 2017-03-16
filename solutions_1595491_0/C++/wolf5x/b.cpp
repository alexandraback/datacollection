#line 2 "GuessCard.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <assert.h>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).end()) i=(c).end(); i!=(c).begin(); --i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int dp[110][110];
int _, N, S, P, T;

int main()
{
    freopen("B-small-attempt0.in","r",stdin); freopen("b.out","w",stdout);
    cin >> _;
    FOR(CAS, 1, _){
        cin >> N >> S >> P;
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        REP(i,N){
            cin >> T;
            int ss = (T+1)/3+1, ns = (T+2)/3;
            REP(j,S+1){
                if(dp[i][j] < 0) continue;
                if(j < S && ss >= 2)
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+(ss>=P));
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]+(ns>=P));
            }
        }
        cout << "Case #" << CAS << ": " << dp[N][S] << "\n";
    }
    return 0;
}
