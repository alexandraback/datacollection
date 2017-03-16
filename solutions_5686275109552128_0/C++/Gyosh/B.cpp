#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>

#define REP(a,b) for (int a = 0; a < b; a++)
#define FOR(a,b,c) for (int a = b; a <= c; a++)
#define RESET(a,b) memset(a,b,sizeof a)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define PII pair<int,int>
#define INF 10000

#define LL long long
using namespace std;

int T;
int N;
int ar[1005];
int temp[1005];
int maxt;

int neededFlip(int tleft){
	int flip = 0;
	REP(i,N){
		flip += ar[i] / tleft;
		if (ar[i] % tleft == 0){
			flip--;
		}
	}
	return flip;
}

int withMaxFlip(int maxFlip){
	int ret = maxt;
	int ki = 1;
	int ka = maxt;
	while (ki <= ka){
		int tgh = (ki + ka) >> 1;

		int h = neededFlip(tgh);
		if (h <= maxFlip){
			ret = maxFlip + tgh;
			ka = tgh - 1;
		}else{
			ki = tgh + 1;
		}
	}
	return ret;
}

int main(){		
	scanf("%d", &T);
	REP(jt,T){
		scanf("%d", &N);
		
		maxt = 0;
		REP(i,N){
			scanf("%d", &ar[i]);
			maxt = max(maxt, ar[i]);
		}

		int ans = maxt;
		FOR(i,0,maxt){
			ans = min(ans, withMaxFlip(i));
		}

		printf("Case #%d: %d\n", jt+1, ans);
	}
	return 0;
}
