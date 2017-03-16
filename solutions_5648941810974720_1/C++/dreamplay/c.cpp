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


int c[30];
void inline sub(string  ch) {
	for(int i = 0; i < ch.length(); i++)
		c[ch[i] - 'A']--;
}
int main(){
	fileio;
	int i, j, t, tt = 0;
	cin >> t;
	while(t--) {
		tt++;
		cout << "Case #"<<tt<<": ";
		for(i = 0; i < 26; i++)
			c[i] = 0;
		string s;
		cin >> s;
		for(i = 0; i < s.length(); i++)
			c[s[i] - 'A']++;
		vector<int> ans;
		while(c['X' - 'A']) {
			ans.PB(6);
			sub("SIX");
		}
		while(c['Z' - 'A']) {
			ans.PB(0);
			sub("ZERO");
		}
		while(c['G' - 'A']) {
			ans.PB(8);
			sub("EIGHT");
		}
		while(c['W' - 'A']) {
			ans.PB(2);
			sub("TWO");
		}
		while(c['H' - 'A']) {
			ans.PB(3);
			sub("THREE");
		}
		while(c['R' - 'A']) {
			ans.PB(4);
			sub("FOUR");
		}
		while(c['O' - 'A']) {
			ans.PB(1);
			sub("ONE");
		}
		while(c['S' - 'A']) {
			ans.PB(7);
			sub("SEVEN");
		}
		
		while(c['F' - 'A']) {
			ans.PB(5);
			sub("FIVE");
		}
		while(c['I' - 'A']) {
			ans.PB(9);
			sub("NINE");
  		}
  		sort(ans.begin(), ans.end());
  		for(i = 0; i < ans.size(); i++)
			cout << ans[i];
		cout << endl;
  	}
  	return 0;
  }
