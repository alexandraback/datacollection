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

inline LL mul(LL x,LL y,LL mo){
    LL z=0;
    for(;y;y>>=1,x=(x+x)%mo)if(y&1)z=(z+x)%mo;
    return z;
}

inline LL Pow(LL x,LL y,LL mo){
    LL z=1;
    for(;y;y>>=1,x=mul(x,x,mo))if(y&1)z=mul(z,x,mo);
    return z;
}

inline bool test(LL a,LL n){
    if(a==n)return 1;
    if(a<=1)return 0;
    LL m=n-1,k=0;
    for(;m%2==0;m>>=1,++k);
    a=Pow(a,m,n);
    for(;k--;){
        LL b=mul(a,a,n);
        if(b==1 && a^1 && a^n-1)return 0;
        a=b;
    }
    return a==1;
}

inline bool ispr(LL n){
    for(int x:{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41})if(!test(x,n))return 0;
    return 1;
} 

inline LL ran2(){
	return (rand()<<15)+rand();
}

inline LL ran1(){
	return (ran2()<<30)+ran2();
}

inline LL ran(){
	return (ran1()<<60)+ran1();
}

LL rho(LL n){
    for(;;){
        LL x=ran()%n,c=ran()%(n-1)+1,y=x,k=2,i=1;
        for(;;){
            ++i;
            LL g=__gcd(n+y-x,n);
            if(g>1 && g<n)return g;
            if(i==k)k<<=1,y=x;
            x=(mul(x,x,n)+c)%n;
            if(x==y)break;
        }
    }
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