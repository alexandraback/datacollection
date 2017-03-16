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
typedef pair<int,int> pii;
const int N=11111;
int L;ll X;
int v[5][5]={
	{0,0,0,0,0},
	{0,1,2,3,4},
	{0,2,-1,4,-3},
	{0,3,-4,-1,2},
	{0,4,3,-2,-1}
};
int a[N],pre[N],suf[N];
int mul(int x,int y){
	bool fu=0;
	if(x<0)fu^=1;
	if(y<0)fu^=1;
	if(fu)return -v[abs(x)][abs(y)];
	else return v[abs(x)][abs(y)];
}
int pw(int x,ll y){
	int an=1;
	for(;y;y>>=1){
		if(y&1)an=mul(an,x);
		x=mul(x,x);
	}
	return an;
}
int main() {
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	int T;read(T);rep(_,1,T){
		read(L);read(X);
		rep(i,1,L){
			char ch;
			for(ch=getchar();ch<=32;ch=getchar());
			if(ch=='i')a[i]=2;
			else if(ch=='j')a[i]=3;
			else if(ch=='k')a[i]=4;
		}
		pre[0]=1;rep(i,1,L)pre[i]=mul(pre[i-1],a[i]);
		suf[L+1]=1;dep(i,L,1)suf[i]=mul(a[i],suf[i+1]);
		int la=pw(pre[L],X);
		printf("Case #%d: ",_);
		if(la!=-1){
			puts("NO");
		} else {
			ll m1=X*L+1,m2=0;
			rep(i,1,L){
				ll k=i;int now=1;
				rep(j,0,3){
					if(mul(now,pre[i])==2)m1=min(m1,k);
					k+=L;
					now=mul(now,pre[L]);
				}
			}
			dep(i,L,1){
				ll k=(X-1)*L+i;int now=1;
				rep(j,0,3){
					if(mul(suf[i],now)==4)m2=max(m2,k);
					k-=L;
					now=mul(now,suf[1]);
				}
			}
			m1+1<m2?puts("YES"):puts("NO");
		}
	}
	return 0;
}
