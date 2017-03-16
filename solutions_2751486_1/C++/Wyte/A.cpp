#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int fen[1000005];
int l;
void update(int x)
{
    while(x<=l)
    {
        fen[x]++;
        x+=x&-x;
    }
}
int find(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+=fen[x];
        x-=x&-x;
    }
    return sum;
}
long long dp[1000005];
long long jum[1000005];
main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    //long long ans=0;
    int t;
    int n;
    int i;
    char ch[1000005];
    scanf("%d",&t);
    int tcase=1;
    while(t--)
    {
        scanf("%s %d",ch,&n);
        memset(dp,0,sizeof dp);
        l=strlen(ch);
        //printf("L%d\n",l);

        for(i=1;i<=l;i++) fen[i]=0;

        for(i=0;i<l;i++)
        {
            //printf("%c",ch[i]);
            if(ch[i]=='a' || ch[i]=='e' || ch[i]=='i' || ch[i]=='o' || ch[i]=='u')
            {
                update(i+1);
            }
        }
        //printf("\n");
        for(i=n;i<=l;i++)
        {
            if(find(i)-find(i-n)==0)
            {
                dp[i]=(long long)(i-n+1);
            }
            else
            {
                dp[i]=dp[i-1];
            }
            //printf("%d : %lld\n",i,dp[i]);
        }
        long long ans=0;
        for(i=n;i<=l;i++) ans+=dp[i];
        printf("Case #%d: %lld\n",tcase++,ans);
    }
}
