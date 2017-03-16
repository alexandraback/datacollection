#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

int t,id,n,m;
int i,j,a,b;
int zip[60][2],map[60][60];
int state[60],visit[60];

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

void out()
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            if (state[i]==zip[j][1])
            {
 //               printf(",%d ",state[i]);
                printf("%d",zip[j][0]);
                break;
            }
    }
    printf("\n");
    return ;
}

int check()
{
    int i,j;
    int que[60];
    int now;
//if (state[0]==4 && state[1]==3 && state[2]==0 && state[3]==1 && state[4]==2)printf(".ok1.");

//if (state[0]==4 && state[1]==1 && state[2]==2 && state[3]==3 && state[4]==0)printf(".ok.");
    now=0;que[0]=state[0];
    for (i=1;i<n;i++)
    {
        while (now>=0 && map[que[now]][state[i]]==0)
            now--;
        if (now<0)return 0;
        now++;
        que[now]=state[i];
    }
    return 1;
}

int dfs(int now,int id)
{
    int i,j;
//    printf("->%d %d,",now+1,id);
    if (id>=n-1)
    {
        state[id]=now;
        if (check()==1)
        {
            out();
            return 1;
        }
        else
            return 0;
    }
    visit[now]=1;state[id]=now;
    for (i=0;i<n;i++)
    if (visit[zip[i][1]]==0)
    {
        if (dfs(zip[i][1],id+1)==1)return 1;
    }
    visit[now]=0;
    return 0;
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);freopen("c.out","w",stdout);
    scanf("%d",&t);
    for (id=1;id<=t;id++)
    {
        memset(map,0,sizeof(map));
        memset(state,0,sizeof(state));
        memset(visit,0,sizeof(visit));
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++)
        {
            scanf("%d",&zip[i][0]);
            zip[i][1]=i;
        }
        qsort(zip,n,sizeof(zip[0]),cmp);
//for (i=0;i<n;i++)printf("%d %d,",zip[i][0],zip[i][1]);
        for (i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            map[a-1][b-1]=1;map[b-1][a-1]=1;
        }
        printf("Case #%d: ",id);
        for (i=0;i<n;i++)
        {
            if (dfs(zip[i][1],0)==1)break;
        }
    }
    return 0;
}
