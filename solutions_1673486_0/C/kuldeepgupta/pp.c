#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define f(i,n) for(i=1;i<=n;i++)
#define fa(i,a,n) for(i=a;i<n;i++)
#define in(n) scanf("%d",&n)
#define MOD  1000000009ll
int main()
{
 freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
int t1,a,b,i,j,k,n;
double t,d;
j=1;
in(t1);
    while(j<=t1){
  double m[100005],p[100005];
	in(a);in(b);
m[0]=1.0f;
      for(i=1;i<=a;i++){scanf("%lf",&p[i]);m[i]=m[i-1]*p[i];}
d=m[(int)a]*(double)(b-a+1)+(1.0f-m[(int)a])*(double)(b-a+1+b+1);
t=(double)(b+2);if(t<d)d=t;
for(i=1;i<=a;i++){t=m[a-i]*(double)(b-a+1+2*i)+(1-m[a-i])*(double)(b-a+1+2*i+b+1);if(t<d)d=t;}
printf("Case #%d: %lf\n",j,d); j++;   
	}
    
    return 0;}
