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
#define MP make_pair
#define PB push_back
#define PII pair<int,int> 

#define __ puts("")
#define MAXN 105
using namespace std;

bool available[256];
int T;
int K, L, S;
char target[MAXN], keyboard[MAXN];
double dp[MAXN][MAXN];
int faf[MAXN];

void build(){
	int i,j;
	
	i = 0;
	j = -1;
	faf[0] = -1;
	while (i < L){
		while ((j >= 0) && (target[i] != target[j])) j = faf[j];
				
		i++;
		j++;
		faf[i] = j;
	}
}

int maxOccurence(){
	if (S < L) return 0;
	REP(i,L){
		if (!available[target[i]]) return 0;
	}

	int saves = faf[L];

	int ret = 1;
	int len = L;
	while (len + L - saves <= S){
		len += L - saves;
		ret++;
	}
	return ret;
}

int teleport(int id, char c){
	while ((id >= 0) && (target[id] != c)){
		id = faf[id];
	}
	return id + 1;
}

double rek(int state, int taken){
	if (taken == S){
		if (state == L){
			return 1;
		}else{
			return 0; 
		}
	}else if (dp[state][taken] > -0.5){
		return dp[state][taken];
	}else{
		double &ret = dp[state][taken] = 0;

		if (state == L){
			ret += 1;
			state = faf[state];
		}
		double p = 1./K;
		REP(i,K){
			ret += p*rek(teleport(state, keyboard[i]), taken+1);
		}

		return ret;
	}
}

int main(){
	scanf("%d", &T);
	REP(jt,T){
		scanf("%d %d %d", &K, &L, &S);
		scanf("%s", keyboard);
		scanf("%s", target);

		RESET(available, 0);
		REP(i,K){
			available[keyboard[i]] = 1;
		}

		build();

		// REP(i,L+1){
		// 	printf("%c %d %d => %d\n", target[i], i, faf[i], teleport(i, 'A'));
		// }

		RESET(dp,-1);
		printf("Case #%d: %.12lf\n", jt+1, maxOccurence() - rek(0,0));
	}

	return 0;
}
