#include<bits/stdc++.h>
using namespace std;
char a[1009];
int extra()
{
    int i=0,ans,sum;

    ans=0;sum=0;
    while(a[i])
    {
        if(sum<i)
        {
            ans+=(i-sum);
            sum=i;
        }
        sum+=a[i]-'0';

        i++;
    }

    return ans;

}
int main()
{
    int T,i,smax;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&smax);
        scanf("%s",a);

        printf("Case #%d: %d\n",i,extra());
    }
    return 0;
}
