#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[22];
int dp[2100000];
int n,T;
int sum;

int calc(int x)
{
    int ret=0;
    for(int i=0;i<n;i++)
    {
        if(x&(1<<i)) ret+=a[i];
    }
    return ret;
}
void print(int x)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(x&(1<<i))
        {
            if(flag) putchar(' ');
            printf("%d",a[i]);
            flag=1;
        }
    }
    putchar('\n');

}



int main()
{
   // freopen("out.txt","w",stdout);
    cin>>T;
    int casno=1;
    while(T--)
    {
        sum=0;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=sum;j>=a[i];j--) dp[j]+=dp[j-a[i]];
        }
        printf("Case #%d:\n",casno++);
        bool haveans=0;
        int val;
        for(int i=0;i<=sum;i++) if(dp[i]>1) {haveans=1;val=i;break;}
        if(haveans)
        {
            int cnt=0;
            for(int i=1;i<1<<n;i++) if(calc(i)==val)
            {
                print(i);
                cnt++;
                if(cnt==2) break;
            }
        }
        else printf("Impossible\n");
    }
}
