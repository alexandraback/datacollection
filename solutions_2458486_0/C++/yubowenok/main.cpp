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
#define ERREQ(X,Y) (fabs((X)-(Y))<EPS)
#define DBGL cout << "here" << endl;
#define SZ(X) sizeof(X)
const double PI = acos(-1.0);
const double EPS = 1E-9;
const int INF = (int)1E9;
using namespace std;

#define MAXN 12
#define MD 12

int N;

bool f[1050000];
int key[205];
int kt[25][205];
int szkt[25];
int tp[25];
int L;
int ord[25];

bool solve(int state){
	if(state==(1<<N)-1) return 1;
	if(f[state]) return 0;
	
	FOR(i, N){
		if(!(state & (1<<i)) && key[tp[i]]){
			key[tp[i]]--;
			
			FOR(j, szkt[i]){
				key[kt[i][j]]++;
			}

			ord[L++] = i;
			bool suc = solve(state | (1<<i));
			if(suc){
				return 1;
			}else{
				L--;
				key[tp[i]]++;
				FOR(j, szkt[i]){
					key[kt[i][j]]--;
				}
			}
		}
	}
	// fail
	f[state] = 1;
	return 0;
}


int main(){
	int cs;

	FILE_W("output");

	cin>>cs;

	
	for(int csn=1;csn<=cs;csn++){
		printf("Case #%d: ", csn);
		
		int K;
		cin >> K >> N;
		FILL(key, 0);
		FOR(i, K){
			int a;
			cin >> a;
			key[a] ++;
		}
		FILL(kt, 0);
		FOR(i, N){
			cin >> tp[i] >> szkt[i];
			FOR(j, szkt[i]){
				int a;
				cin >> a;
				kt[i][j] = a;
			}
		}
		FILL(f, 0);
		
		L = 0;
		bool suc = solve(0);
		if(suc){
			FOR(i, N) cout << ord[i]+1 << " ";
			cout << endl;
		}else{
			cout << "IMPOSSIBLE" << endl;
		}

		
	}
	return 0;
}