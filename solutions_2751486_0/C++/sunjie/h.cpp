#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=1000010;
char s[maxn];
long long dp[maxn];
int check(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        int n;
        scanf("%s%d",s,&n);
        int i,len=strlen(s);
        int k;
        if(check(s[0])==0)
        {
            if(n==1)
            {
                dp[0]=1;
            }
            else
            {
                dp[0]=0;
            }
            k=1;
        }
        else
        {
            dp[0]=0;
            k=0;
        }
        for(i=1;i<len;i++)
        {
            if(check(s[i]))
            {
                dp[i]=dp[i-1];
                k=0;
            }
            else
            {
                k++;
                if(k>=n)
                {
                    dp[i]=i-n+2;
                    //printf("%d**%d\n",i,n);
                }
                else
                {
                    dp[i]=dp[i-1];
                }
            }
        }
        long long sum=0;
        for(i=0;i<len;i++)
        {
            sum+=dp[i];
            //printf("%I64d**\n",dp[i]);
        }
        printf("Case #%d: %I64d\n",++cas,sum);
    }



    
    fclose(stdin);
    fclose(stdout);
    return 0;
}