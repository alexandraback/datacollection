// by ¦Î
// program sky  :)

#include <stdio.h>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

#define Rin register int
#define oo (c=getchar())
#define For(i,l,r) for(int _r=r,i=l;i<=_r;++i)
#define rep(i,l,r) for(int _r=r,i=l;i<_r;++i)
#define dto(i,r,l) for(int _l=l,i=r;i>=_l;--i)

using namespace std;

typedef __int128 LL;

int n,K;
LL v[15];

inline void hello(){
	freopen("ha.in","r",stdin);
	freopen("ha.out","w",stdout);
	srand(time(0));
}

inline bool ispr(LL x){
	For(i,2,1000)if(x%i==0)return 0;
	return 1;
}
inline LL rho(LL x){
	For(i,2,1000)if(x%i==0)return i;
	return 1;
}

void print(LL x){
	if(x>9)print(x/10);
	putchar(x%10+48);
}

inline void pri(LL x){
	if(x>1)pri(x/2);
	putchar(x%2+48);
}

inline void gao(){
	For(i,2,10)if(ispr(v[i]))return;
	pri(v[2]);putchar(' ');
	For(i,2,9)print(rho(v[i])),putchar(' ');
	print(rho(v[10]));puts("");
	if(!--K)exit(0);
	fprintf(stderr,"%d\n",K);
}

void dfs(int s){
	if(s==n){
		For(i,2,10)v[i]=v[i]*i+1;
		gao();
		For(i,2,10)v[i]=(v[i]-1)/i;
		return ;
	}
	For(i,2,10)v[i]=v[i]*i;
	dfs(s+1);
	For(i,2,10)++v[i];
	dfs(s+1);
	For(i,2,10)v[i]=(v[i]-1)/i;
}

int main(){
// say hello
	hello();
	scanf("%*d");printf("Case #1:\n");
	scanf("%d%d",&n,&K);
	For(i,2,10)v[i]=1;
	dfs(2);
// never say goodbye
}