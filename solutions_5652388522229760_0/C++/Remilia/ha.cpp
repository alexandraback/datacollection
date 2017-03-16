// by ¦Î
// program sky  :)

#include <stdio.h>
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

inline void hello(){
	freopen("ha.in","r",stdin);
	freopen("ha.out","w",stdout);
}

bool bo[10];

inline void gao(int n){
	for(;n;n/=10)bo[n%10]=1;
}
inline bool done(){
	For(i,0,9)if(!bo[i])return 0;
	return 1;
}

inline void test(int n){
	if(n==0)return (void)(puts("INSOMNIA"));
	For(i,0,9)bo[i]=0;
	for(int i=1;i;++i){
		gao(n*i);
		if(done())return (void)(printf("%d\n",n*i));
	}
}

int main(){
// say hello
	hello();
	For(tc,1,IN()){
		printf("Case #%d: ",tc);
		test(IN());
	}
// never say goodbye
}