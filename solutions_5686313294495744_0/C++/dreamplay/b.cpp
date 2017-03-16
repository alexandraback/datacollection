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



int x[1000 + 5], y[1000 + 5];
string s1, s2;

int ans[ 1 << 17 + 5];
bool f1, f2;
int main(){
	fileio;
	int i, j, t, tt = 0, a, b, c, n, k;
	cin >> t;
	while(t--) {
		tt++;
		cout << "Case #" << tt << ": ";
		cin >> n;
		map<string, int> m1, m2;
		for(i = 0; i < n; i++) {
			cin >> s1;
			cin >> s2;
			if(m1[s1] == 0) {
				m1[s1] = m1.size();
			}
			if(m2[s2] == 0) {
				m2[s2] = m2.size();
			}
			x[i] = m1[s1];
			y[i] = m2[s2];
		}
		ans[0] = 0;
		for(i = 1; i < (1LL << n); i++) {
			ans[i] = 0;
			for(j = 0; j < n; j++) {
				if( (i & (1LL << j)) ) {
					f1 = f2 = 0;
					for(k = 0; k < n; k++)
						if( (i & (1LL << k))  && k != j){
							if(x[j] == x[k]) f1 = true;
							if(y[j] == y[k]) f2 = true;
						}
					if(f1 && f2)
						ans[i] = max(ans[i], 1 + ans[i ^ (1LL << j)]);
					else ans[i] = max(ans[i], 0 + ans[i ^ (1LL << j)]);
				}
			}
		}
		cout << ans[i-1] << endl;
		
	}




	return 0 ;
}



