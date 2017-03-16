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

int J, P, S, K;

void gen(int a , int b, int c) {
	for(int i = 1; i <= a; i++)
		for(int j = 1; j <= b; j++)
			for(int k = 1; k <= c; k++)
				cout << i << " " << j << " " << k << "\n";
}
int main(){
	fileio;
	int i, j, t;
	int J, P, S, K;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		map < pair<int,int>, int > store;
		vector< pair<int, pair<int, int> > > ans;
		cin >> J >> P >> S >> K;
		if(S > P && P > J) S--;
		if(S <= K) {
			cout << J * P * S << endl;
			gen(J, P, S);
			continue;
		}
		
		for(i = 1; i <= J; i++)
   			for(j = 1; j <= P; j++)
				for(int k = 1; k <= S; k++){
					if(store[MP(i, j * 10)] < K && store[MP(j * 10, k * 100)] < K && store[MP(i, k * 100)] < K) {
						ans.PB(MP(i, MP(j, k)));
						store[MP(i, j * 10)]++;
						store[MP(j * 10, k * 100)]++;
						store[MP(i, k * 100)]++;
					}
				}
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++)
			cout << ans[i].F << " " << ans[i].S.F << " " << ans[i].S.S << endl;
	}

	return 0 ;
}



