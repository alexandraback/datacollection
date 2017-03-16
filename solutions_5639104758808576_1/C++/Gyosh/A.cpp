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
#define INF 2123123123

#define LL long long
using namespace std;

int T;
int N;
char sc[1005];

int main(){		
	scanf("%d", &T);
	REP(jt,T){
		scanf("%d %s", &N, sc);

		int added = 0;
		int now = 0;
		REP(i,N+1){
			if (now < i){
				added += (i - now);
				now += (i - now);
			}
			now += (sc[i] - '0');
		}

		printf("Case #%d: %d\n", jt+1, added);
	}
	return 0;
}
