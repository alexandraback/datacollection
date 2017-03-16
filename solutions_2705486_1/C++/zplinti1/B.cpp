#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=1125077+2;

int tr[maxn][26];
bool end[maxn];
int sumnode;

char s[4000+10];
int visit[maxn][5];
int dp[2][maxn][5];

struct node{
    int id,k;
} qu[2][maxn*6];
int cnt;
int num[2];
int now,nt;

void insert(char *s)
{
    int now=0;
    while(*s)
    {
        int t=(*s)-'a';
        if (tr[now][t]==0)
        {
            sumnode++;
            tr[now][t]=sumnode;
        }
        now=tr[now][t];
        s++;
    }
    end[now]=1;
}

void ck(int &x,int y)
{
    if (y<x) x=y;
}

void add(int id,int k,int need)
{
    if (visit[id][k]!=cnt)
    {
        visit[id][k]=cnt;
        dp[nt][id][k]=need;
        qu[nt][num[nt]].id=id;
        qu[nt][num[nt]].k=k;
        num[nt]++;
    } else
    {
        if (need<dp[nt][id][k])
            dp[nt][id][k]=need;
    }
}

int main()
{
    FILE *fppre,*fpin,*fpout;

    fppre=fopen("B.txt","r");
    sumnode=0;
    while(fscanf(fppre,"%s",s)==1)
    {
        insert(s);
    }
    fclose(fppre);

    fpin=fopen("B.in","r");
    fpout=fopen("B.out","w");
    int cas;
    fscanf(fpin,"%d",&cas);
    for(int ii=1;ii<=cas;ii++)
    {
        fscanf(fpin,"%s",s);
        int n=strlen(s);
        now=0;   nt=1;
        memset(visit,-1,sizeof(visit));
        memset(num,0,sizeof(num));
        memset(dp,0,sizeof(dp));
        nt=0;
        add(0,4,0);
        nt=1;
        for(cnt=0;cnt<n;cnt++)
        {
            num[nt]=0;
            int t=s[cnt]-'a';
            for(int j=0;j<num[now];j++)
            {
                int id=qu[now][j].id;
                int k=qu[now][j].k;
                int need=dp[now][id][k];
                if (tr[id][t])
                    add(tr[id][t],min(k+1,4),need);
                if (end[id])
                {
                    int tid=0;
                    if (tr[tid][t])
                        add(tr[tid][t],min(k+1,4),need);
                }
                if (k==4)
                for(int l=0;l<26;l++)
                {
                    if (tr[id][l])
                        add(tr[id][l],0,need+1);
                    if (end[id])
                    {
                        int tid=0;
                        if (tr[tid][l])
                            add(tr[tid][l],0,need+1);
                    }
                }
            }
            nt^=1;now^=1;
        }
        int ans=n;
        for(int i=0;i<num[now];i++)
            if (end[qu[now][i].id])
            ck(ans,dp[now][ qu[now][i].id][qu[now][i].k]);
        fprintf(fpout,"Case #%d: %d\n",ii,ans);
    }
    fclose(fpin);
    fclose(fpout);
    return 0;
}
