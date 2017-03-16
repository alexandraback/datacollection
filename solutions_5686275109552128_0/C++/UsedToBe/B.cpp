#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,u) for(int i=H[u];i;i=nxt[i])
#define re(i,a,b) for (int i=a;i<b;++i)
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
const int N=1111;
int a[N];
int main() {
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	int cas=0;
	int T;read(T);while(T--){
		int n;read(n);int mx=0;
		rep(i,1,n)read(a[i]),mx=max(a[i],mx);
		int ans=mx;
		rep(now,1,1000){
			int tmp=0;
			rep(i,1,n)tmp+=a[i]%now==0?a[i]/now-1:a[i]/now;
			ans=min(ans,tmp+now);
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}
