#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

int dp[10], dp2[10];

int main(){
    int caseNumber;
    scanf("%d", &caseNumber);
    //cin>>caseNumber;
    REP(caseN, caseNumber) {
    	memset(dp, 0, sizeof dp);
    	int E, R, N;
    	cin>>E>>R>>N;
    	int res = 0;
    	REP(i, N) {
    		memset(dp2, 0, sizeof dp2);
    		int v;
    		cin>>v;
    		REP(j, E + 1) {
    			REP(k, j + 1) {
    				int nxt = dp[j] + v * k;
    				int n2 = j - k + R;
    				if (n2 > E) {
    					n2 = E;
    				}
    				dp2[n2] = max(dp2[n2], nxt);
    			}
    		}
    		REP(j, E + 1) {
    			dp[j] = dp2[j];
    			res = max(res, dp[j]);
    		}
    	}
    	printf("Case #%d: %d\n", caseN + 1, res);
    }
    return 0;
}