#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define MAXN 22
#define MAXK 202
using namespace std;
int K,N;
int KT[MAXK];//鑰匙型態數量
int C[MAXN];//打開寶箱的鑰匙型態
int M[MAXN];//寶箱裡的鑰匙數量
int IN[MAXN][MAXK];//寶箱裡的鑰匙型態
bool v[MAXN];
int cnt[MAXK],tmp[MAXK];
int Cnt;
struct NODE
{
    bool v[MAXN];
    int KT[MAXK];
    char path[MAXN];
    int len;
    bool operator<(const NODE& t)const
    {
        return strcmp(path,t.path)>0;
    }
}qtmp,Q;
bool process()
{
    Cnt=0;
    priority_queue<NODE>q;
    for(int i=0;i<MAXK;++i)
        qtmp.KT[i]=KT[i];
    memset(qtmp.v,0,sizeof(qtmp.v));
    memset(qtmp.path,0,sizeof(qtmp.path));
    qtmp.len=0;
    q.push(qtmp);
    while(!q.empty())
    {
        qtmp=q.top();

        q.pop();
        int c=0;
        for(int i=1;i<=N;++i)
            if(qtmp.v[i]) c++;
            Cnt++;
            if(Cnt>10000) return false;
        if(c==N)
        {
            for(int i=0;i<qtmp.len;++i)
                printf(" %d",int(qtmp.path[i]));
            putchar('\n');
            return true;
        }
        for(int i=1;i<=N;++i)
        {
            Q=qtmp;
            if(qtmp.KT[C[i]]&&!qtmp.v[i])
            {
                qtmp.KT[C[i]]--;
                qtmp.path[qtmp.len]=char(i);
                qtmp.len++;
                qtmp.v[i]=true;
                for(int j=0;j<M[i];++j)
                    qtmp.KT[IN[i][j]]++;
                q.push(qtmp);
            }
            qtmp=Q;
        }
    }
    return false;
}
bool ini()
{
    memset(cnt,0,sizeof(cnt));
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<MAXK;++i)
        cnt[i]+=KT[i];
    for(int i=1;i<=N;++i)
        for(int j=0;j<M[i];++j)
            cnt[IN[i][j]]++;
    for(int i=1;i<=N;++i)
        tmp[C[i]]++;
    for(int i=0;i<MAXK;++i)
        if(tmp[i]>cnt[i])
            return false;
    memset(v,0,sizeof(v));
    if(!process()) return false;
    else return true;
}
int main()
{
    freopen("D-small-attempt1.in","r",stdin);
    freopen("D-small-attempt1.out","w",stdout);
    int t,T,x;
    scanf("%d",&t);
    T=t;
    while(t--)
    {
        scanf("%d%d",&K,&N);
        memset(KT,0,sizeof(KT));
        memset(IN,0,sizeof(IN));
        for(int i=0;i<K;++i)
        {
            scanf("%d",&x);
            KT[x]++;
        }
        for(int i=1;i<=N;++i)
        {
            scanf("%d",&x);
            C[i]=x;
            scanf("%d",&x);
            M[i]=x;
            for(int j=0;j<M[i];++j)
            {
                scanf("%d",&x);
                IN[i][j]=x;
            }
        }
        printf("Case #%d:",T-t);
        if(!ini()) printf(" IMPOSSIBLE\n");
    }
    return 0;
}
