#include<bits/stdc++.h>
using namespace std;

#define all(v)             v.begin(),v.end()
#define sz(v)            ((int)((v).size()))
#define psh(x)                  push_back(x)
#define sc(x)                 scanf("%d",&x)
#define sc2(x,y)         scanf("%d%d",&x,&y)
#define scl(x)              scanf("%lld",&x)
#define FOR(i,n)        for(int i=0;i<n;++i)


typedef string            stringx;
typedef long long         ll;
typedef pair <int, int>   ii;
typedef pair<stringx, int>     si;

#define begix {
    #define endx }
ll powerxxx(ll b, ll p)begix if (!p) return 1; ll sq = powerxxx(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; endx

void solvex();
int  k, l, s,cnt,temp,comulative,ctx;
stringx valx, fixs,x;
void solvex()
begix

	if (x.length() == s)
	begix
		temp = 0;
		FOR(i, s)
		begix
			if (x.substr(i, l) == fixs)++cnt,++temp;
		endx
		ctx = max(ctx, temp);
		return;
	endx
FOR(i, k)
	begix
		x += valx[i];
		solvex();
	//	x.pop_back();
	x.erase(x.end()-1);
	endx
endx
int main()
begix
	 freopen("ax.in","r",stdin);
    freopen("xn.out","w",stdout);
	 int t,p=0;
    cin>>t;
	while(t--)
	begix
		cin >> k >> l >> s>>valx>>fixs;
		cnt =0;
		ctx = 0;
		comulative = powerxxx(k,s);
		solvex();
		 printf("Case #%d: ",++p);
		cout <<fixed<<setprecision(7)<<ctx-double(cnt)/comulative<<endl;
	endx
	return 0;
endx
