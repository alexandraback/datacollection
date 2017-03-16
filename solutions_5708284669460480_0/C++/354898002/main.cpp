#include <iostream>
#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<map>
#include<vector>
#include <algorithm>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

int T,icase = 1;

char key[110];
char tar[110];
char tmp[10];
double sum,ans,Max;
int Cal()
{
    int i,j,ans = 0;

    for(i = 0;i+strlen(tar) <= strlen(tmp); ++i)
    {
        for(j = 0;tar[j] != '\0'; ++j)
            if(tar[j] != tmp[i+j])
                break;
        if(tar[j] == '\0')
            ans++;
    }
    Max = max(Max,(double)ans);
    return ans;
}

void dfs(int site,int L)
{
    if(site == L)
    {
        tmp[site] = '\0';
        sum += Cal();
        ans++;
        return ;
    }

    for(int i = 0;key[i] != '\0'; ++i)
    {
        tmp[site] = key[i];
        dfs(site+1,L);
    }
}

int main()
{
    freopen("B-small-attempt3.in","r",stdin);
    freopen("data1.out","w",stdout);

    scanf("%d",&T);

    bool mark[30];

    while(T--)
    {
        int K,L,S;

        scanf("%d %d %d",&K,&L,&S);

        scanf("%s",key);
        scanf("%s",tar);
        memset(mark,false,sizeof(mark));

        int i,j,k;

        for(i = 0;key[i] != '\0'; ++i)
            mark[key[i]-'A'] = true;

        for(i = 0;tar[i] != '\0'; ++i)
            if(mark[tar[i]-'A'] == false)
                break;
        if(tar[i] != '\0')
        {
            printf("Case #%d: 0.0\n",icase++);
            continue;
        }
        sum = 0,ans = 0,Max = 0;
        dfs(0,S);
        printf("Case #%d: %.7lf\n",icase++,Max-sum/ans);
    }

    return 0;
}

/*

int dp[1<<21];

int dfs(int sta,int m,int w)
{
    if(dp[sta] != -1)
        return dp[sta];

    for(i = 0;i < m; ++i)
    {
        if((sta&(1<<i)) == 0)
    }
}

int main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
    //freopen("data1.out","w",stdout);
    int n,m,w;

    int ans = 0;

    int T,icase = 1;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d %d",&n,&m,&w);
        memset(dp,-1,sizeof(dp));
        printf("Case #%d: %d\n",n*dfs(0,m,w));
    }


    return 0;
}
*/





