#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
struct nod
{
    int fst,snd;
    bool one;
    bool finish;
}node[1005];
int cmp(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    return b->snd - a->snd;
}
int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    int t,tt=0,n,i,star,cnt,old,num;
    scanf("%d",&t);
    while(t--)
    {
        num=0;
        cnt=0;
        star=0;
        old=0;
        tt++;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&node[i].fst,&node[i].snd);
            node[i].one=node[i].finish=0;
        }
        qsort(node,n,sizeof(node[0]),cmp);
        while(cnt<n)
        {
            for(i=0;i<n;i++)
            {
                if(node[i].snd<=star && !node[i].finish)
                {
                    if(node[i].one)star++;
                    else star+=2;
                    node[i].one=1;
                    node[i].finish=1;
                    cnt++;
                    num++;
                }
            }
            if(old==star)
            {
                for(i=0;i<n;i++)
                    if(node[i].fst<=star && !node[i].one && !node[i].finish)
                    {
                        star++;
                        node[i].one=1;
                        num++;
                        break;
                    }
                if(i==n)
                {
                    printf("Case #%d: Too Bad\n",tt);
                    goto label;
                }
            }
            old=star;
        }
        printf("Case #%d: %d\n",tt,num);
        label:;
    }
    return 0;
}
