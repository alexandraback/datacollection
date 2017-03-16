#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <list>

#define FORST(X,S,T) for(int X=S; X<=T; X++)  
#define RFORST(X,S,T) for(int X=S; X>=T; X--)  
#define FOR(X,XB) for(int X=0; X<XB; X++)
#define RFOR(X,XB) for(int X=(XB)-1; X>=0; X--)
#define FORSTL(X,C) for(X=C.begin();X!=C.end();X++)
#define SQR(X) ((X)*(X))
#define MID(X,Y) (((X)+(Y))/2)
#define FILL(X,V) memset(X,V,sizeof(X))
#define FILE_R(X) freopen(X, "r", stdin)  
#define FILE_W(X) freopen(X, "w", stdout)  
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define ERREQ(X,Y) (fabs((X)-(Y))<EPS)
#define DBGL cout << "here" << endl;
#define SZ(X) sizeof(X)
const double PI = acos(-1.0);
const double EPS = 1E-9;
const int INF = (int)1E9;
typedef long long INT;
using namespace std;

#define MAXN 50005
INT E, R, N;
INT val[MAXN];
INT ans;

void solve(int a, int b, int prev, int next, int nextU){
	if(a>b) return;
	int maxi = -1;
	int maxv = 0;
	FORST(i, a, b){
		if(val[i]>=maxv){
			maxi = i;
			maxv = val[i];
		}
	}
	INT usable = E;
	INT mustleft = 0;
	if(prev!=-1){
		usable = MIN(usable, R*(INT)(maxi-prev));
	}
	if(next!=-1){
		mustleft = MAX(mustleft, MAX(0, nextU-R*(INT)(next-maxi)));
	}
	if(usable>=mustleft){
		INT use = usable - mustleft;
		ans += use*val[maxi];
		//cout << maxi << " " << use << endl;
		solve(a, maxi-1, prev, maxi, E);
		solve(maxi+1, b, maxi, next, nextU);
	}
	
}

int main(){
	int cs;

	FILE_W("output");

	cin>>cs;

	for(int csn=1;csn<=cs;csn++){
		printf("Case #%d: ", csn);
		cin >> E >> R >> N;
		FOR(i, N){
			cin >> val[i];
		}
		ans = 0;
		solve(0, N-1, -1, -1, -1);
		cout << ans << endl;

	}
	return 0;
}