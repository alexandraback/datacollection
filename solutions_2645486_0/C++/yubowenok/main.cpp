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
int E, R, N;
int val[MAXN];
int f[MAXN][10];

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
		FILL(f, 0);
		FORST(i, 0, N-1){
			FORST(j, 0, E){
				FORST(t, 0, j){
					int k  = MIN(j-t+R, E);
					f[i+1][k] = MAX( f[i+1][k], f[i][j]+val[i]*t );
				}
			}
		}
		int ans = 0;
		FORST(j, 0, E){
			ans = MAX(ans, f[N][j]);
		}
		cout << ans << endl;

	}
	return 0;
}