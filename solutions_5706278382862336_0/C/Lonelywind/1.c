#include <stdio.h>
#include <string.h>
#include <math.h>

int p,q,tt,ti;

int check(int x)
{
    if (x==1) return 1;
    if (x%2==1) return 0; 
    return check(x/2);   
}

int plus(int x){
    
    int t=0;
    while (x>0){
          t++;
          x=x/2;      
    }    
    return t;
}

int gcd(int a,int b){
    if (b==0) return a;
    return gcd(b,a % b);    
}

int main(void)
{
	/*freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);*/

	int i,j,x;

	scanf("%d",&tt);
	for (ti=1;ti<=tt;ti++){
        printf("Case #%d: ",ti);
        scanf("%d/%d",&p,&q);
        x=gcd(p,q);
        p=p/x; q=q/x;
        if ((check(q)==1) ){
           printf("%d\n",plus(q)-plus(p));
        }
        else printf("impossible\n");      
    }

	return 0;
}
