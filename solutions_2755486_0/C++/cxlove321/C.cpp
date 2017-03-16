#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<list>

#define MAXX 11111
#define MAX 1000111
#define MAXT (MAX<<3)

short T,t;
int N,i,j,k,m;
int a,b,ans,c;
long long d,n,w,e,s,dd,dp,ds;

struct Query
{
    long long l,r,s;
    Query(){}
    Query(long long a,long long b,long long c):l(a),r(b),s(c){}
};

std::list<Query>::const_iterator lit;
std::map<long long,std::list<Query> >map;
std::map<long long,std::list<Query> >::const_iterator it;
std::vector<long long>vt(MAX<<1);

#define lson (id<<1)
#define rson (id<<1|1)
#define lc lson,l,mid[id]
#define rc rson,mid[id]+1,r

int mid[MAXT];
long long set[MAXT],min[MAXT];

void make(int id,int l,int r)
{
    set[id]=min[id]=0;
    if(l!=r)
    {
        mid[id]=l+r>>1;
        make(lc);
        make(rc);
    }
}

inline void down(int id)
{
    if(set[id])
    {
        min[lson]=set[lson]=set[id];
        min[rson]=set[rson]=set[id];
        set[id]=0;
    }
}

inline void up(int id)
{
    min[id]=std::min(min[lson],min[rson]);
}

void update(int id,int l,int r)
{
    if(a<=l && r<=b)
    {
        if(min[id]<c)
            min[id]=set[id]=c;
        return;
    }
    down(id);
    if(a<=mid[id])
        update(lc);
    if(b>mid[id])
        update(rc);
    up(id);
}

long long query(int id,int l,int r)
{
    if(a<=l && r<=b)
        return min[id];
    down(id);
    long long re(0x3f3f3f3f3f3f3f3f);
    if(a<=mid[id])
        re=std::min(re,query(lc));
    if(b>mid[id])
        re=std::min(re,query(rc));
    return re;
}

int main()
{
    scanf("%hd",&T);
    for(t=1;t<=T;++t)
    {
        scanf("%d",&N);
        vt.resize(0);
        map.clear();
        while(N--)
        {
            scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&d,&n,&w,&e,&s,&dd,&dp,&ds);
            for(i=0;i<n;++i)
            {
                map[d].push_back(Query(w,e,s));
                vt.push_back(w);
                vt.push_back(e);
                d+=dd;
                w+=dp;
                e+=dp;
                s+=ds;
            }
        }
        std::sort(vt.begin(),vt.end());
        vt.resize(std::unique(vt.begin(),vt.end())-vt.begin());
        m=vt.size()*2;
        make(1,1,m);
        ans=0;
        for(it=map.begin();it!=map.end();++it)
        {
//            printf("%lld: \n",it->first);
            for(lit=it->second.begin();lit!=it->second.end();++lit)
            {
                a=std::lower_bound(vt.begin(),vt.end(),lit->l)-vt.begin();
                a=a*2+1;
                b=std::lower_bound(vt.begin(),vt.end(),lit->r)-vt.begin();
                if(vt[b]!=lit->r)
                    --b;
                b=b*2+1;
                if(a<=b && query(1,1,m)<lit->s)
                    ++ans;
            }
            for(lit=it->second.begin();lit!=it->second.end();++lit)
            {
                a=std::lower_bound(vt.begin(),vt.end(),lit->l)-vt.begin();
                a=a*2+1;
                b=std::lower_bound(vt.begin(),vt.end(),lit->r)-vt.begin();
                if(vt[b]!=lit->r)
                    --b;
                b=b*2+1;
                if(a<=b)
                {
                    c=lit->s;
                    update(1,1,m);
                }
            }
            for(lit=it->second.begin();lit!=it->second.end();++lit)
            {
//                printf("%lld %lld %lld ",lit->l,lit->r,lit->s);
                a=std::lower_bound(vt.begin(),vt.end(),lit->l)-vt.begin();
                a=a*2+1;
                b=std::lower_bound(vt.begin(),vt.end(),lit->r)-vt.begin();
                if(vt[b]!=lit->r)
                    --b;
                b=b*2+1;
//                printf("%d %d\n",a,b);
            }
        }
        printf("Case #%hd: %d\n",t,ans);
    }
    return 0;
}
