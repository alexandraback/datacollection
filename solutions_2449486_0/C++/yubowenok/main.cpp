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
#include <Windows.h>

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
#define ERREQ(X,Y) (fabs((X)-(Y))<EPS)
#define DBGL cout << "here" << endl;
#define SZ(X) sizeof(X)
const double PI = acos(-1.0);
const double EPS = 1E-9;
const int INF = (int)1E9;
using namespace std;

#define MAXN 105
int N, M;
int ln[MAXN][MAXN];
int cnt[MAXN];

int main(){
	int cs;

	FILE_W("output");

	cin>>cs;
	for(int csn=1;csn<=cs;csn++){
		printf("Case #%d: ", csn);
		cin >> N >> M;
		FILL(cnt, 0);
		FOR(i, N) FOR(j, M){
			int a;
			cin >> a;
			ln[i][j] = a;
			cnt[a]++;
		}

		int h=1;
		bool ans =  1;
		while(h<=100){
			if(cnt[h]==0){
				h++;
				continue;
			}
			
			bool wholesuc = 0;
			FOR(i, N){
				bool suc = 1;
				int tcnt = 0;
				FOR(j, M){
					if(!(ln[i][j]==h || ln[i][j]==0)){
						suc = 0;
						break;
					}else{
						if(ln[i][j]==h) tcnt++;
					}
				}
				if(suc && tcnt){
					wholesuc = 1;
					FOR(j, M){
						ln[i][j] = 0;
					}
					cnt[h] -= tcnt;
					break;
				}
			}
			if(wholesuc){
				if(cnt[h]==0) h++;
				continue;
			}

			FOR(j, M){
				bool suc = 1;
				int tcnt = 0;
				FOR(i, N){
					if(!(ln[i][j]==h || ln[i][j]==0)){
						suc = 0;
						break;
					}else{
						if(ln[i][j]==h) tcnt++;
					}
				}
				if(suc && tcnt){
					wholesuc = 1;
					FOR(i, N){
						ln[i][j] = 0;
					}
					cnt[h] -= tcnt;
					break;
				}
			}

			if(!wholesuc)
			{
				ans = 0;
				break;
			}

			if(cnt[h]==0) h++;
		}
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;


	}
	return 0;
}