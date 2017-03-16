#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int T;
int X,R,C;

int main(){
	freopen("15D.out","w",stdout);
	scanf("%d",&T);
	FOR(tt,1,T){
		scanf("%d%d%d",&X,&R,&C);
		printf("Case #%d: ",tt);
		if(R * C % X != 0){
			printf("RICHARD\n");
			continue;
		}
		if(X == 1 || (X == 2 && (R > 1 || C > 1))){
			printf("GABRIEL\n");
			continue;
		}
		if(X == 3 && R >= 2 && C >= 2){
			printf("GABRIEL\n");
			continue;
		}
		if(X == 4 && ((R >= 4 && C >= 3) || (R >= 3 && C >= 4))){
			printf("GABRIEL\n");
			continue;
		}
		printf("RICHARD\n");
	}
	return 0;
}

