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



string s1, s2;
ll p[20];
ll x, y, minix, miniy, minid, bx, by;
int main(){
	fileio;
	int i, j, t, k, z1, z2, f1, f2;
	p[0] = 1;
	for(i = 1; i <= 19; i++)
		p[i] = p[i - 1] * 10;
	cin >> t;
	int tt = 0;
	while(t--) {
		tt++;
		cout << "Case #"<<tt<<": ";
		minid = 1e18;
		cin >> s1;
		cin >> s2;
		int len = 0;
		 bx = 0, by = 0;
		for(i = 0; i < s1.length(); i++)
			 len += (s1[i] == '?' ? 1 :0) + (s2[i] == '?' ? 1 : 0 );
		for(i = 0; i < s1.length(); i++)
			if(s1[i] != '?')
				bx += (s1[i] - '0') * p[s1.length() - 1 - i];
		for(i = 0; i < s2.length(); i++)
			if(s2[i] != '?')
				by += (s2[i] - '0') * p[s2.length() - 1 - i];
				
		//trace3(len, bx, by);
		
		for(i = 0; i < p[len]; i++) {
			j = 1;
			x = bx;
			y = by;
			for(k = 0; k < s1.length(); k++) {
				if(s1[k] == '?') {
					x += p[s1.length() - 1 - k] * ( (i / p[j - 1] ) % 10 );
					j++;
				}
			}
			for(k = 0; k < s2.length(); k++) {
				if(s2[k] == '?') {
					y += p[s2.length() - 1 - k] * ( (i / p[j - 1] ) % 10 ) ;
					j++;
				}
			}
			if( abs( x - y) < minid) {
				minid = abs(x - y);
				minix = x;
				miniy = y;
			}
			else if(abs( x - y) == minid) {
				if(minix > x) {
					minix = x;
					miniy = y;
				}
				else if(minix == x)
					miniy = min(y, miniy);
				
			}
		}
		z1 = 0;
		ll temp;
		if(minix == 0) f1 = 1;
		else {
			f1 = 0;
			temp = minix;
			while(temp) {
				temp /= 10;
				f1++;
			}
		}
		if(miniy == 0) f2 = 1;
		else {
			f2 = 0;
			temp = miniy;
			while(temp) {
				temp /= 10;
				f2++;
			}
		}
		
		while(s1.length() != z1 + f1) {
			cout << 0 ;
			z1++;
		}
		cout << minix << " " ;
		z2 = 0;
		while(s2.length() != z2 + f2 ) {
			cout << 0 ;
			z2++;
		}
		cout <<  miniy << endl;
	}
	return 0 ;
}
