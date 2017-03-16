// by ¦Î
// program sky  :)

#include <stdio.h>
#include <string.h>
#include <algorithm>

#define Rin register int
#define oo (c=getchar())
#define For(i,l,r) for(int _r=r,i=l;i<=_r;++i)
#define rep(i,l,r) for(int _r=r,i=l;i<_r;++i)
#define dto(i,r,l) for(int _l=l,i=r;i>=_l;--i)

using namespace std;


inline int IN(){
	char c;Rin x=0;
	for(;oo<48 && c^'-' || c>57;);bool f=c=='-';if(f)oo;
	for(;c>47 && c<58;oo)x=(x<<3)+(x<<1)+c-48;if(f)x=-x;return x;
}

int n,g[55],cnt[2555];

inline void hello(){
	freopen("ha.in","r",stdin);
	freopen("ha.out","w",stdout);
}

int main(){
// say hello
	hello();
	For(tc,1,IN()){
		n=IN();
		memset(cnt,0,sizeof cnt);
		memset(g,0,sizeof g);
		For(i,1,2*n-1){
			For(j,1,n){
				int x=IN();
				++cnt[x];
			}
		}
		For(x,1,2500)if(cnt[x]&1)g[++*g]=x;
		sort(g+1,g+*g+1);
		printf("Case #%d: ",tc);
		For(i,1,n)printf("%d%c",g[i]," \n"[i==n]);
	}
// never say goodbye
}