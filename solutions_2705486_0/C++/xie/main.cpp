#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 100000
struct node
{
    int e[27];
    int vis;
    void init()
    {
        memset(e,-1,sizeof(e));
        vis=0;
    }
}t[1500000];
char s[100];
char S[1500000];
int MAX;
int dp[52][1500000][5];
int len;
int num=0;
void add(char ss[],int k,int rt)
{
    if(t[rt].e[ss[k]-'a']==-1)
    {
        t[rt].e[ss[k]-'a']=++num;
        t[num].init();
    }
    int h=t[rt].e[ss[k]-'a'];
    if(k+1==len)
        t[h].vis=1;
    else
        add(ss,k+1,h);
}
int main()
{
    FILE *f1,*f2;
    f1=fopen("1.txt","r");
    f2=fopen("2.txt","r");
    freopen("3.txt","w",stdout);
    t[0].init();
    num=0;
    while(fscanf(f1,"%s",S)>0)
    {
     //   scanf("%s",S);
       len=strlen(S);
       add(S,0,0);
    }
    int T;
    int cas=0;
    fscanf(f2,"%d",&T);
   // scanf("%d",&T);
    while(T--)
    {
        fscanf(f2,"%s",s+1);
    //    scanf("%s",s+1);
        len=strlen(s+1);
        memset(dp,63,sizeof(dp));
        MAX=dp[0][0][4];
        dp[0][0][4]=0;
        for(int i=1;i<=len;i++)
        {
            for(int j=0;j<=num;j++)
            {
                for(int l=0;l<=4;l++)
                {
                    if(dp[i-1][j][l]==MAX)
                        continue;
                    for(int k=0;k<26;k++)
                    {
                        if(k&&l!=4)
                            continue;
                        char na=s[i]-k;
                        if(na<'a')
                            na+=26;
                        if(na>'z')
                            na-=26;
                        int to=t[j].e[na-'a'];
                        if(j==0)
                        {
                            if(to!=-1)
                                dp[i][to][(k)?0:min(4,l+1)]=min(dp[i-1][j][l]+((k!=0)?1:0),dp[i][to][(k)?0:min(4,l+1)]);
                        }
                        else
                        {
                            if(to!=-1)
                                dp[i][to][(k)?0:min(4,l+1)]=min(dp[i-1][j][l]+((k!=0)?1:0),dp[i][to][(k)?0:min(4,l+1)]);
                            if(t[j].vis)
                            {
                                to=t[0].e[na-'a'];
                                if(to!=-1)
                                    dp[i][to][(k)?0:min(4,l+1)]=min(dp[i-1][j][l]+((k!=0)?1:0),dp[i][to][(k)?0:min(4,l+1)]);
                            }
                        }
                    }
                }
            }
        }
        int ans=100;
        for(int i=0;i<=num;i++)
            if(t[i].vis)
                for(int l=0;l<=4;l++)
                ans=min(dp[len][i][l],ans);
        printf("Case #%d: %d\n",++cas,ans);
    }
}
