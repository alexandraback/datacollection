#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define NODE 2000001
#define C 26
int dp[5000][6];
char s[5000];
struct node
{
    int end;
    node *next[C];
}pool[NODE],*topp;

void init()
{
    topp=pool;
    pool[0].end=0;
    memset(pool[0].next,0,sizeof(pool[0].next));
}

void insert(char *str)
{
    node *p=pool;
    for(int i=0;str[i];i++)
    {
        if(!p->next[str[i]-'a'])
        {
            p->next[str[i]-'a']=++topp;
            p=topp;
            p->end=0;
            memset(p->next,0,sizeof(p->next));
        }
        else
        {
            p=p->next[str[i]-'a'];
        }
    }
    p->end++;
}

void dfs(int i,int j,int c,node *p)
{

    if(p->end)
        if(dp[i][j]>c)
        {
            dp[i][j]=c;
           // printf("%d %d %d\n",i,j,c);
        }
    if(!s[i]) return;
    if(!j)
    {
        for(int k=0;k<26;k++)
            if(p->next[k])
                dfs(i+1,4,c+1,p->next[k]);
        if(p->next[s[i]-'a'])
            dfs(i+1,0,c,p->next[s[i]-'a']);
    }
    else
    {
        if(p->next[s[i]-'a'])
            dfs(i+1,j-1,c,p->next[s[i]-'a']);
    }
}


int main()
{
    freopen("garbled_email_dictionary.txt","r",stdin);
    freopen("c.out","w",stdout);
    char ts[1111];
    init();
    for(int i=0;i<521196;i++)
    {
        scanf("%s",ts);
        insert(ts);
    }
    freopen("c.in","r",stdin);

    int t;
    scanf("%d",&t);


    for(int c=1;c<=t;c++)
    {

        scanf("%s",s);
        int l=strlen(s);

        memset(dp,0x1f,sizeof(dp));
        dp[0][0]=0;
        for(int i=0;i<l;i++)
            for(int j=0;j<5;j++)
                if(dp[i][j]<=l)
                {
                    dfs(i,j,dp[i][j],pool);
                }
        int ans=dp[l][0];
        for(int j=0;j<5;j++)
            if(ans>dp[l][j])
                ans=dp[l][j];
        printf("Case #%d: %d\n",c,ans);
    }
    return 0;
}
