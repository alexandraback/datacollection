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
		int c,d,v;
		cin>>c>>d>>v;
		vi in(d);
		int i;
		map<int, int> hs;
		map<int, int>::iterator it;
		rep (i, d) {
			cin>>in[i];
			int d2[101]={0};
			for (int j = 1; j <= v; j++)
				if (hs[j] == 1 && j + in[i] <= v)
					d2[j + in[i]] = 1;
			for (int j = 1; j <=v; j++) if (d2[j]==1)hs[j]=1;
			hs[in[i]] = 1;
		}
		int res = 0;
		for (i = 1; i <= v; i++) {
			if (hs[i] == 0) {
				int d2[101]={0};
				for (int j = 1; j <=v; j++) {
					if (hs[j] == 1 && j + i<= v)
						d2[j + i] = 1;
				}
				for (int j = 1; j <=v; j++) if (d2[j]==1)hs[j]=1;
				hs[i]=1;
				res++;
			}
		}
		cout<<"Case #"<<T-t<<": "<<res<<"\n";
	}
	return 0;
}
