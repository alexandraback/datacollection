#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[1000003];
int n,k;
long long dp[1000003][2];
bool a[1000003];
bool convert(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return 0;
    return 1;
}

int mainx(int I)
{
    scanf("%s",s);
    scanf("%d",&k);
    n=strlen(s);
    for(int i=0;i<n;i++)
    {
        a[i]=convert(s[i]);
        dp[i][0]=0ll;
        dp[i][1]=0ll;
    }
    int last = -1;
    if(a[0])
    {
        dp[0][1]=1ll;
        if(k==1)
        {
            dp[0][0]=1ll;
            last=0;
        }
    }
    for(int i=1;i<n;i++){

        if(a[i])dp[i][1]=dp[i-1][1]+1ll;
        else dp[i][1]=0;

        if(dp[i][1]>=k){
            last=i-k+1;
        }

        dp[i][0]=dp[i-1][0];

        dp[i][0]+=(long long)last+1;

    }
    printf("Case #%d: %lld\n",I,dp[n-1][0]);
}
int main2(int I)
{
    scanf("%s",s);
    scanf("%d",&k);
    n=strlen(s);
    for(int i=0;i<n;i++)
    {
        a[i]=convert(s[i]);
        dp[i][0]=0ll;
        dp[i][1]=0ll;
    }
    int count = 0;
    for(int i=k;i<=n;i++)
    {
        for(int j=0;j<=n-i;j++)
        {
            int c=0;
            for(int e=j;e<j+i;e++)
            {
                if(a[e])c++;
                else c=0;
                if(c>=k){
                    count++;
                    break;
                }
            }
        }
    }
    printf("Case #%d: %d\n",I,count);
}
int main(){
    freopen("name1.in","r",stdin);
    freopen("name4.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        mainx(i);
    }
}
