/*******************
    D Rupinder
***********************/


#include<bits/stdc++.h>

#define lld long long int
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define all(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz size()
#define pii pair<int, int>
#define pll pair <lld ,lld>
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define scan(v,n) vector<int> v(n);rep(i,n)cin>>v[i];
#define vi vector<int>
#define MOD 1e9 + 7

using namespace std;
lld modpow(lld a,lld n,lld temp){lld res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 

int main()
{
	int t;
	cin>>t;
	int T=t;
	while (t--) {
		lld c,d,v, i;
		cin>>c>>d>>v;
		vi in(d);
		lld x = 1;
		lld res = 0;
		rep (i, d) {
			cin>>in[i];
			while (in[i] > x) {
				res++;
				x = (c+1)*x;
			}
			if (in[i] == x) x = (c+1)*x;
			else x = c*(x + in[i]);
		}
		while (x <= v) {
			res++;
			x *=(c+1);
		}
		cout<<"Case #"<<T-t<<": "<<res<<"\n";
	}
	return 0;
}
