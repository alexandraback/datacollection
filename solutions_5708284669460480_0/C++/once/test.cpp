#include<bits/stdc++.h>
using namespace std;
const int N =107;
double dp[N][N][N];
char str[N],ss[N];
int num[26];
int cas,run=0,n,l,s;
double ans,ma;
void dfs(int d,double p)
{
    if (d==s)
    {
        int cnt=0;
        for (int i=0;i+l-1<s;++i)
        {
            bool ok=true;
            for (int j=0;j<l;++j)
                if (ss[i+j]!=str[j])
                    ok=false;
            if (ok) ++cnt;
        }
        ans+=cnt*p;
//        if (p>0)
//        {
//            ss[d]='\0';
//            printf("%f %d ",p,cnt);
//            puts(ss);
//        }
        if (p>0&&cnt>ma) ma=cnt;
        return;
    }
    for (int i=0;i<26;++i)
        if (num[i]!=0)
        {
            ss[d]=i+'A';
            dfs(d+1,p*num[i]/n);
        }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&cas);
    while (cas--)
    {
        memset(dp,0,sizeof dp);
        memset(num,0,sizeof num);
        dp[0][0][0]=1;
        scanf("%d%d%d",&n,&l,&s);
        scanf("%s",str);
        for (int i=0;i<n;++i) ++num[str[i]-'A'];
        scanf("%s",str);
        ans=0;ma=0;
        dfs(0,1);
        printf("Case #%d: %.10f\n",++run,ma-ans);
    }
    return 0;
}
