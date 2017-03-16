#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
const int    INF = 100000000;
const double EPS = 1e-10;
const int    MOD = 1000000007;
using namespace std;
typedef pair<int,int> P;
typedef long long ll;

void solve(){
	ll b, m;
	int edge[50][50];
	rep(i,50) rep(j,50) edge[i][j] = 0;
	cin >> b >> m;
	ll B = 1;
	rep(i,b-2) B *= 2;
	if(B < m){
		puts("IMPOSSIBLE");
		return;
	}
	puts("POSSIBLE");
	if(B == m){
		rep(i,b) for(int j = i+1; j < b; j++){
			edge[i][j] = 1;
		}
		rep(i,b){
			rep(j,b){
				printf("%d",edge[i][j]);
			}
			printf("\n");
		}
		return;
	}
	rep(i,b) for(int j = i+1; j < b-1; j++){
		edge[i][j] = 1;
	}
	int cnt = 1;
	while(m){
		if(m&1) edge[cnt][b-1] = 1;
		m >>= 1;
		cnt++;
	}
	rep(i,b){
		rep(j,b){
			printf("%d",edge[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int T;
	cin >> T;
	rep(i,T){
		printf("Case #%d: ",i+1);
		solve();
	}
	
}