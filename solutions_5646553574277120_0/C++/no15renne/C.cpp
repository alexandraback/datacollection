
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <climits>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define RREP(i,n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef vector<int> vi;

const int INF = 1e9;
const int MOD = 1e9+7;

int dp[1000];

int main(void){	
	int t;
    cin >> t;
    REP(tt, t){
        int c, d, v;
        cin >> c >> d >> v;
        vi x(d);
        REP(i, d) cin >> x[i];
        REP(i, 100) dp[i] = 0;
        dp[0] = 1; 
        REP(i, d){
            RREP(j, 50){
                dp[j+x[i]] = max(dp[j+x[i]], dp[j]);
            }
        }
        int f = 1;
        int ans = 0;
        while(f){
            f = 0;
            int k = 0;
            REP(i, v+1){
                if(!dp[i]){
                    f = 1;
                    ans++;
                    int y = i;
                    RREP(j, 50){
                        dp[j+y] = max(dp[j+y], dp[j]);
                    }
                }
            }
        }
        cout << "Case #" << tt + 1 << ": ";
        cout << ans << endl;
    }
    

	return 0;
}

