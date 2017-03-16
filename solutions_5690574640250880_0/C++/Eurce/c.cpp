#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

#define M 1000000

int t,r,c,m,rc,el;
char b[50][51];

struct E
{
    int ri,mc,ml,p;
}e[M];

void adde(int ri,int mc,int ml,int p)
{
    e[el].ri=ri; e[el].mc=mc; e[el].ml=ml; e[el].p=p; el++;
}

int mk()
{
    el=0;
    int i,j,k,l;
    int ri,mc,ml;
    queue<int>Q;
    for(j=min(c,m);j;j--)
    {
        if(r*j<m||j==c-1)
            continue;
        Q.push(el);
        adde(0,j,m-j,-1);
    }
    while(!Q.empty())
    {
        i=Q.front(); Q.pop();
        ri=e[i].ri; mc=e[i].mc; ml=e[i].ml;
        if(!ml)
            return i;
        if(ri==r-3)
        {
            if(ml<=(c-2)*2&&ml%2==0&&ml/2<=mc)
            {
                adde(ri+1,ml/2,ml/2,i);
                adde(ri+2,ml/2,0,el-1);
                return el-1;
            }
        }
        else
        {
            k=min(min(c,mc),ml);
            for(j=k;j;j--)
            {
                if((r-ri)*j<ml||j==c-1)
                    continue;
                Q.push(el);
                adde(ri+1,j,ml-j,i);
            }
        }
    }
    return -1;
}

void solve()
{
    int i,j,k,l;
    rc=r*c;
    memset(b,0,sizeof b);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            b[i][j]='.';
    b[r-1][c-1]='c';
    printf("Case #%d: \n",++t);
    if(!m)
    {
        for(i=0;i<r;i++)
            puts(b[i]);
        return;
    }
    if(r==1)
    {
        for(j=0;j<c-1&&m;j++)
        {
            m--;
            b[0][j]='*';
        }
        puts(b[0]);
        return;
    }
    if(c==1)
    {
        for(i=0;i<r-1&&m;i++)
        {
            m--;
            b[i][0]='*';
        }
        for(i=0;i<r;i++)
            puts(b[i]);
        return;
    }
    if(m==rc-1)
    {
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                b[i][j]='*';
        b[r-1][c-1]='c';
        for(i=0;i<r;i++)
            puts(b[i]);
        return;
    }
    if(m>rc-4)
    {
        puts("Impossible");
        return;
    }
    if(r==2)
    {
        if(m&1)
            puts("Impossible");
        else
        {
            for(j=0;m;j++)
            {
                b[0][j]='*';
                b[1][j]='*';
                m-=2;
            }
            puts(b[0]);
            puts(b[1]);
        }
        return;
    }
    if(c==2)
    {
        if(m&1)
            puts("Impossible");
        else
        {
            for(i=0;m;i++)
            {
                b[i][0]='*';
                b[i][1]='*';
                m-=2;
            }
            for(i=0;i<r;i++)
                puts(b[i]);
        }
        return;
    }
    l=mk();
    if(l==-1)
    {
        puts("Impossible");
        return;
    }
    while(l!=-1)
    {
        for(i=e[l].ri,j=0;e[l].mc--;j++)
            b[i][j]='*';
        l=e[l].p;
    }
    for(i=0;i<r;i++)
        puts(b[i]);
}

int main()
{
    scanf("%*d");
    while(~scanf("%d%d%d",&r,&c,&m))
        solve();
    return 0;
}
