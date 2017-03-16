#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <set>
#include <map>

#define REP(a,b) for (int a=0; a<b; a++)
#define FOR(a,b,c) for (int a=b; a<=c; a++)
#define FORD(a,b,c) for (int a=b; a>=c; a--)
#define RESET(a,b) memset(a, b, sizeof a)

#define INF 2123123123
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PII pair<int,int> 

#define __ puts("")
using namespace std;

int T;
int C,D,V;
int coin[105];
int dp[105];

int main(){
	scanf("%d", &T);
	REP(jt,T){
		scanf("%d%d%d", &C, &D, &V);
		REP(i,D){
			scanf("%d", &coin[i]);
		}

		int added = 0;
		while (1){
			RESET(dp,0);
			dp[0] = 1;
			REP(i,D){
				for (int j = V; j >= coin[i]; j--){
					dp[j] = dp[j] | dp[j - coin[i]];
				}
			}

			bool ok = 1;
			FOR(i,0,V){
				ok = ok && dp[i];
			}
			if (ok) break;

			FOR(i,0,V){
				if (dp[i] == 0){
					coin[D++] = i;
					added++;
					break;
				}
			}
		}

		printf("Case #%d: %d\n", 1+jt, added);
	}

	return 0;
}
