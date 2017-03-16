#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
const int    INF = 100000000;
const double EPS = 1e-10;
const int    MOD = 1000000007;
using namespace std;
typedef pair<int,int> P;

int a[10][10], b[10][10], c[10][10];

void solve(){
	rep(i,10) rep(j,10){
		a[i][j] = 0;
		b[i][j] = 0;
		c[i][j] = 0;
	}
	int J, P, S, K;
	cin >> J >> P >> S >> K;
	int ans = 0;
	vector<int> out[3];
	rep(i,J){
		rep(j,P){
			rep(k,S){
				if(a[i][j] < K && b[j][k] < K && c[i][k] < K){
					ans++;
					out[0].push_back(i);
					out[1].push_back(j);
					out[2].push_back(k);
					a[i][j]++;
					b[j][k]++;
					c[i][k]++;
				}
			}
		}
	}
	cout << ans << endl;
	rep(i,ans){
		printf("%d %d %d\n",out[0][i]+1,out[1][i]+1,out[2][i]+1);
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