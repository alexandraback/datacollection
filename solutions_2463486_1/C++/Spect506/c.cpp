#include<cstdio>
const long long list[41]={1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002};
long long l,r,ans;
int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int test,tt,i;
	scanf("%d",&test);
	for(tt=1;tt<=test;tt++)
    {
      ans=0;
      scanf("%I64d%I64d",&l,&r);
      for(i=0;list[i]!=0;i++)
        if(list[i]*list[i]>=l&&list[i]*list[i]<=r)ans++;
      printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
