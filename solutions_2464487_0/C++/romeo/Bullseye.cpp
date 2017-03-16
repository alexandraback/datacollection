using namespace std;
#include<iostream>

int main()
{
freopen("A-small-attempt0.in","r",stdin);
freopen("A-small-attempt0_out.in","w",stdout);
long long int r,p,fp,ring,j;
int test;
scanf("%d",&test);
j=1;
while(test--)
{
ring=0;
fp=0;
scanf("%lld %lld",&r,&p);
while(p>=fp)
{
fp+=(r+1)*(r+1)-(r*r);
if(fp<=p)
ring++;
r=r+2;
}
printf("Case #%lld: %lld\n",j,ring);
j++;
}
return 0;
}
