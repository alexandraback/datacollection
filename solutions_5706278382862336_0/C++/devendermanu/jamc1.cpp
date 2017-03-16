#include<stdio.h>
long long gcd(long long a,long long b)
{ long long c;
while(b)
{ c=a%b;
a=b;
b=c;
}
return a;
}
int main()
{ int t,z,ans;
long long p,q,hcf;
scanf("%d",&t);
for(z=1;z<=t;z++)
{ printf("Case #%d: ",z);
scanf("%lld/%lld",&p,&q);
hcf=gcd(p,q);
p/=hcf;
q/=hcf;
if(q&(q-1)) { printf("impossible\n"); continue; }
for(ans=0;q>p;ans++)
q>>=1;
printf("%d\n",ans);
}
return 0;
}

