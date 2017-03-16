#include<bits/stdc++.h>
using namespace std;

//#pragma comment (linker, "/STACK:256000000")

typedef long long ll ;

#define endl '\n'
#define  MP make_pair
#define PB push_back
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define fileio freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
#define boost  ios_base::sync_with_stdio(false);
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
int mod = 1e9 + 7 ;
ll powmod(ll a,ll b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}
/*---------------------------------------------------------------------------------------------------------------------*/



bool mat[55][55];
ll ans[55] , v[55];
int main(){
	fileio;
	ans[0] = 1;
	for(int i = 1; i <= 53; i++)
		ans[i] = 2 * ans[i - 1];
		
	int i, j, t, tt;
	ll b, m;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		for(i = 1; i <= 50; i++)
			for(j = 1; j <= 50; j++)
				mat[i][j] = 0;
				
		cin >> b >> m;
		if( ans[b - 2] < m) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		else cout << "POSSIBLE\n";
		v[b] = 1;
		for(i = b - 1;i;i--) {
			v[i] = 0;
			for(j = i  + 1; j <= b; j++)
				if(v[i] + v[j] <= m) {
					v[i] += v[j];
					mat[i][j] = 1;
				}
		}
		for(i = 1; i <= b; i++) {
			for(j = 1; j <= b; j++)
				cout << mat[i][j];
			cout << endl;
		}
		
	}


	return 0 ;
}



