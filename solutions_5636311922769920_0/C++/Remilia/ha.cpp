// by ¦Î
// program sky  :)

#include <stdio.h>
#include <algorithm>

#define For(i,l,r) for(int _r=r,i=l;i<=_r;++i)
#define rep(i,l,r) for(int _r=r,i=l;i<_r;++i)
#define dto(i,r,l) for(int _l=l,i=r;i>=_l;--i)

using namespace std;

typedef long long LL;

inline void hello(){
	freopen("ha.in","r",stdin);
	freopen("ha.out","w",stdout);
}

int Tc,K,C,S;

inline LL gao(int s){
	LL u=0;
	For(i,1,C){
		u=u*K+s;
		++s;
		if(s>K)s=1;
	}return u;
}

int main(){
// say hello
	hello();
	scanf("%d",&Tc);
	For(tc,1,Tc){
		scanf("%d%d%d",&K,&C,&S);
		printf("Case #%d: ",tc);
		if((K+C-1)/C>S){
			puts("IMPOSSIBLE");
			continue;
		}
		LL _=[](){
			LL res=0;
			rep(i,1,C)res=res*K+K;
			return res;
		}();
		For(i,1,(K+C-1)/C){
			printf("%lld%c",gao((i-1)*C+1)-_," \n"[i==(K+C-1)/C]);
		}
	}
// never say goodbye
}