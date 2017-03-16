#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=10005;
struct val{
	int sign,p;
	inline val(int _sign=0,int _p=0){sign=_sign;p=_p;}
}pre[10005],suf[10005];
inline bool operator ==(const val &a,const val &b){
	return a.sign==b.sign&&a.p==b.p;
}
inline val operator *(const val &a,const val &b){
	val u;
	u.sign=a.sign*b.sign;
	if(a.p==1){
		u.p=b.p;
	}
	else if(b.p==1){
		u.p=a.p;
	}
	else if(a.p==b.p){
		u.p=1;
		u.sign*=-1;
	}
	else{
	 	u.p=9-a.p-b.p;
	 	if(a.p==2&&b.p==4)u.sign*=-1;
	 	else if(a.p==3&&b.p==2)u.sign*=-1;
	 	else if(a.p==4&&b.p==3)u.sign*=-1;
	}
	return u;
}
inline val Q(char u){
	val a;
	a.sign=1;
	if(u=='i')a.p=2;
	else if(u=='j')a.p=3;
	else a.p=4;
	return a;
}
int T;
char str[N];
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&T);
	rep(Cas,1,T){
		int n;LL X;
		scanf("%d%I64d",&n,&X);
		scanf("%s",str+1);
		pre[0]=val(1,1);
		rep(i,1,n)pre[i]=pre[i-1]*Q(str[i]);
		suf[n+1]=val(1,1);
		per(i,n,1)suf[i]=Q(str[i])*suf[i+1];
		
		val Std=Q('i')*Q('j')*Q('k');
		val now=val(1,1);
		rep(u,1,(int(X%4ll)))now=now*suf[1];
		
		if(!(now==Std)){
			printf("Case #%d: NO\n",Cas);
			continue;
		}
		
		LL m1,m2;
		m1=-1;m2=-1;
		
		rep(u,0,3){
			if(m1!=-1)break;
			rep(i,1,n){
				val tmp=pre[i];
				rep(v,1,u)tmp=pre[n]*tmp;
				if(tmp==Q('i')){
					m1=u*1ll*n+i*1ll;
					break;
				}
			}
		}
		
		rep(u,0,3){
			if(m2!=-1)break;
			per(i,n,1){
				val tmp=suf[i];
				rep(v,1,u)tmp=tmp*suf[1];
				if(tmp==Q('k')){
					m2=u*1ll*n+n-i+1;
					break;
				}
			}
		}
		if(m1+m2>X*1ll*n||m1==-1||m2==-1){
			printf("Case #%d: NO\n",Cas);
			continue;
		}
		printf("Case #%d: YES\n",Cas);
	}
	return 0;
}


