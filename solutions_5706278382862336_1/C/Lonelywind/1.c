#include <stdio.h>
#include <string.h>
#include <math.h>

int tt,ti;
long long p,q;

int check(long long x)
{
    if (x==1) return 1;
    if (x%2==1) return 0; 
    return check(x/2);   
}

int plus(long long x){
    
    int t=0;
    while (x>0){
          t++;
          x=x/2;      
    }    
    return t;
}

long long gcd(long long a,long long b){
    if (b==0) return a;
    return gcd(b,a % b);    
}

int main(void)
{
	/*freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);*/

	int i,j;
	long long x;

	scanf("%d",&tt);
	for (ti=1;ti<=tt;ti++){
        printf("Case #%d: ",ti);
        scanf("%lld/%lld",&p,&q);
        x=gcd(p,q);
        p=p/x; q=q/x;
        if ((check(q)==1) &&(plus(q)<=41) ){
           printf("%d\n",plus(q)-plus(p));
        }
        else printf("impossible\n");      
    }

	return 0;
}
