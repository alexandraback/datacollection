#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
set<int> S;
struct cel
{
    int x,ind;
} v[101010];
long long E,R,N,T;
int caz;
int cmp(cel a,cel b)
{
    if(a.x==b.x)
    {
        if(a.ind<b.ind)
            return 1;
        return 0;
    }
    if(a.x>b.x)
        return 1;
    return 0;
}
int nr[101010];

void init()
{
    for(int i=0;i<=N+2;++i)
        nr[i]=0;
}
void make()
{
    init();
    sort(v+1,v+N+1,cmp);
    S.clear();
    S.insert(N+2);
    S.insert(-1);
    set<int>::iterator it,it1,it2;
    long long ret=0,howmany,n1,n2,scad; //n1 dreapta n2 stanga
    for(int i=1;i<=N;++i)
    {
    //printf("%d\n",i);
        howmany = 0;
        scad =0;
        int x = v[i].ind;
        S.insert(v[i].ind);
        it = S.find(v[i].ind);
        it1 = it;
        --it1;
        it2 = it;
        ++it2;
        n1 = (*it2-*it)-1;
        n2 = (*it-*it1)-1;


        if(n2==x)
        {
            //printf("@");
            howmany += E;
            howmany += R*(n2-1);
        }
        else
        {
        howmany +=R*(n2+1);
        }
      //  printf("! %d !\n",howmany);
        howmany = min(E,howmany);
        if(n1==(N-x+1))
        {
            howmany=howmany;
            //printf("!");
        }
        else
        {
            howmany-=E-((n1+1) * R);
        }
        howmany = max(howmany,1LL*0);
        howmany = min(howmany,E);
      //  printf("%d %d %d %d %d %d\n",howmany,scad,v[i].x,x,n1,n2);
        ret = ret + v[i].x * howmany;
        nr[v[i].ind]=1;
    }
    printf("Case #%d: %lld\n",caz,ret);
}

int main()
{
freopen("b.in","r",stdin);
freopen("b.out","w",stdout);
    scanf("%lld",&T);
    while(T--)
    {
        ++caz;
        scanf("%lld%lld%lld",&E,&R,&N);
        for(int i=1;i<=N;++i)
        {
            scanf("%d",&v[i].x);
            v[i].ind=i;
        }
        make();
    }
}
