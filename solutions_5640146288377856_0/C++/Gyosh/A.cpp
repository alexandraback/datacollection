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
int W,R,C;
int dp[1<<20];

bool noEscape(int mas){
	int maxConsecutive = 0;
	int consecutive = 0;
	REP(i,C){
		if (!(mas & (1<<i))){
			consecutive++;
			maxConsecutive = max(maxConsecutive, consecutive);
		}else{
			consecutive = 0;
		}
	}

	return maxConsecutive < W;
}

int rek(int mas){
	if (dp[mas] != -1){
		return dp[mas];
	}else{
		int &ret = dp[mas] = INF;
		REP(i,C){
			if (!(mas & (1<<i))){
				if (noEscape(mas | (1<<i))){
					ret = min(ret, W);
				}else{
					ret = min(ret, 1 + rek(mas | (1<<i)));
				}
			}
		}

		return ret;
	}
}

int main(){
	scanf("%d", &T);
	REP(jt,T){
		scanf("%d%d%d", &R, &C, &W);

		RESET(dp,-1);
		printf("Case #%d: %d\n", 1+jt, R*rek(0));
	}

	return 0;
}
