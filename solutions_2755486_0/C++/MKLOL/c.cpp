#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <iostream>
#include <cstring>

#define pb push_back
#define fs first
#define sc second
#define mp make_pair


#define addK 250

using namespace std;

int T,N,M;
int ind;

int nr;
struct attack{
int d,w,e,s;
} ls[101010];

int wall[1010];
int ret;
void reset()
{
ret=0;
nr=0;
    for(int i=0;i<=1000;++i){
        wall[i]=0;
    }

}

void add(int d,int n,int w,int e,int s,int dd,int dp,int ds)
{

attack ret;
ret.d = d;
ret.w=w;
ret.e=e;
ret.s=s;
ls[++nr] = ret;
for(int i=1;i<=n-1;++i){
    w += dp;
    e += dp;
    d += dd;
    s += ds;
    ret.d = d;
    ret.w=w;
    ret.e=e;
    ret.s=s;
    ls[++nr] = ret;
}
}
int cmp(attack a,attack b)
{
    return a.d<b.d;
}
int check(int x,int y,int p)
{
    x+=addK;
    y+=addK;
    --y;
    for(int i=x;i<=y;++i)
        if(wall[i] < p)
            return 1;
    return 0;
}
void make_up(int x,int y,int p)
{
    x+=addK;
    y+=addK;
    --y;
    for(int i=x;i<=y;++i)
        wall[i] = max(wall[i],p);
}
void make_update(vector<attack> up)
{
    for(int i=0;i<up.size();++i)
        make_up(up[i].w,up[i].e,up[i].s);
}
void make()
{

vector<attack> update;
    sort(ls+1,ls+nr+1,cmp);
    for(int i=1;i<=nr;++i){
    //   printf("%d %d %d %d ",ls[i].d,ls[i].w,ls[i].e,ls[i].s);
    if(check(ls[i].w,ls[i].e,ls[i].s)){
        ++ret;
      //  printf("ok\n");
        }
        else{
         //printf("not ok\n");
         1;
         }
    update.pb(ls[i]);
        if(ls[i].d != ls[i+1].d){
            make_update(update);
        update.clear();
        }

    }
}
int main()
{
freopen("c.in","r",stdin);
freopen("c1.out","w",stdout);
    scanf("%d",&T);
    while(T--){
    reset();
    ++ind;
    scanf("%d",&N);
    int d,n,w,e,s,dd,dp,ds;
        for(int i=1;i<=N;++i){
            scanf("%d%d%d%d%d%d%d%d\n",&d,&n,&w,&e,&s,&dd,&dp,&ds);
        add(d,n,w,e,s,dd,dp,ds);
        }
        make();
        printf("Case #%d: %d\n",ind,ret);
    }

return 0;
}
