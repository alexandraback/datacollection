#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t
{
    long long num;
    int type;
}line1[2000], line2[2000];
int N,M;

long long min(long long x, long long y)
{
    return x<y?x:y;
}

long long max(long long x, long long y)
{
    return x>y?x:y;
}

void update(long long *x, long long y)
{
    if(*x<y) *x=y;
}

int compare_long(const void *a, const void *b)
{
    if(*(long long*)a<*(long long*)b) return -1;
    if(*(long long*)a>*(long long*)b) return 1;
    return 0;
}

int split(struct node_t *line1, struct node_t *line2, int N, int M)
{
    static long long typelist[110][110];
    static int typecnt[110];
    static struct node_t newline1[2000];
    int i, newcnt=0;
    memset(typecnt, 0, sizeof(typecnt));
    for(i=1; i<=N; i++)
    {
        typelist[line2[i].type][typecnt[line2[i].type]++]=line2[i].num;
    }
    for(i=1; i<=100; i++)
    {
        if(typecnt[i]==0) continue;
        qsort(typelist[i], typecnt[i], sizeof(long long), compare_long);
    }

    newcnt=0;
    memset(newline1, 0, sizeof(newline1));
    for(i=1; i<=N; i++)
    {
        int j;
        for(j=0; j<typecnt[line1[i].type]; j++)
        {
            newcnt++;
            newline1[newcnt].type=line1[i].type;
            newline1[newcnt].num=min(typelist[line1[i].type][j], line1[i].num);
            line1[i].num-=min(typelist[line1[i].type][j], line1[i].num);
            if(line1[i].num==0) break;
        }
        if(line1[i].num)
        {
            newcnt++;
            newline1[newcnt].type=line1[i].type;
            newline1[newcnt].num=line1[i].num;
        }
    }
    memcpy(line1, newline1, sizeof(newline1));
    return newcnt;
}

int main()
{
    int T, Tcnt=0;
    for(scanf("%d", &T); T; T--,Tcnt++)
    {
        int i;
        long long  ans=0;
        static long long  dp[2000][2000];
        scanf("%d%d", &N, &M);
        for(i=1; i<=N; i++)
        {
            scanf("%lld%d", &line1[i].num, &line1[i].type);
        }
        for(i=1; i<=M; i++)
        {
            scanf("%lld%d", &line2[i].num, &line2[i].type);
        }

        N=split(line1, line2, N, M);
        M=split(line2, line1, M, N);

        memset(dp, 0, sizeof(dp));
        for(i=1; i<=N; i++)
        {
            int j;
            for(j=1; j<=M; j++)
            {
                int k, l;
                for(k=1; i-k>=0; k++)
                {
                    for(l=1; j-l>=0; l++)
                    {
                        update(dp[i]+j, dp[i-k][j]);
                        update(dp[i]+j, dp[i][j-l]);
                        if(line1[i].type==line2[j].type)
                            update(dp[i]+j, dp[i-k][j-l]+min(line1[i].num, line2[j].num));
                    }
                }
                if(ans<dp[i][j]) ans=dp[i][j];
            }
        }
        printf("Case #%d: %lld\n", Tcnt+1, ans);
    }
    return 0;
}
