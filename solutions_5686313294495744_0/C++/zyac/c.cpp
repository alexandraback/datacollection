#include<bits/stdc++.h>
using namespace std;
char str[20][2][30];
int dp[(1<<16)+10];
int n,ans=0;
int check(int x,int pos){
    int f1=0,f2=0;
    for(int i=0;i<n;i++)
    {
        if((1<<i)&x) {
            if(strcmp(str[i][0],str[pos][0])==0) f1=1;
            if(strcmp(str[i][1],str[pos][1])==0) f2=1;
        }
    }
    if(f1&&f2) return 1;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,Case=1;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof dp);
        printf("Case #%d: ",Case++);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s%s",str[i][0],str[i][1]);
        }
        for(int i=0;i<(1<<n);i++)
        {
            for(int j=0;j<n;j++)
            {
                if((1<<j)&i){
                    int tt=i&(~(1<<j));
                    dp[i]=max(dp[i],dp[tt]+check(tt,j));
                }
            }
        }
        cout<<dp[(1<<n)-1]<<endl;
    }
    return 0;
}
