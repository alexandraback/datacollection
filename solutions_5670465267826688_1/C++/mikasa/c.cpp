#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

const int maxn = 10005;
typedef long long ll;
int mat[5][5]={0,0,0,0,0,
               0,1,2,3,4,
               0,2,-1,4,-3,
               0,3,-4,-1,2,
               0,4,3,-2,-1};


char s[maxn];int le;ll x;

int pre[maxn],tail[maxn];

int f(char c)
{
    if(c=='1')
        return 1;
    if(c=='i')
        return 2;
    if(c=='j')
        return 3;
    return 4;
}

int g(int a,int b)
{
    int fu = 1;
    if(a<0)
    {
        a=-a;
        fu = -fu;
    }
    if(b<0)
    {
        b = -b;
        fu = -fu;
    }
    return fu*mat[a][b];
}

int quick(int x,ll k)
{
    int b = 1;
    while(k)
    {
        if(k&1)
            b = g(b,x);
        x = g(x,x);
        k>>=1;
    }
    return b;
}

map<int,int> fp,gp;
map<int,int> :: iterator it;
int main()
{
    int t,cs=0;scanf("%d",&t);
    while(t--)
    {
        fp.clear();gp.clear();
        printf("Case #%d: ",++cs);
        scanf("%d%lld%s",&le,&x,s);
        int st = 1,bf,bg;
        for(int i=1;i<=4;i++)
            fp[i] = gp[i] = fp[-i] = gp[-i] = -1;
        for(int i=0;i<le;i++)
        {
            st = g(st,f(s[i]));
            pre[i] = st;
            if(fp[st]==-1)
                fp[st] = i;
        }
        int res = quick(st,x);
        //printf("res=%d\n",res);
        if(res!=-1)
        {
            puts("NO");
            continue;
        }
        bf = st;st = 1;
        for(int i=le-1;i>=0;i--)
        {
            st = g(f(s[i]),st);
            tail[i] = st;
            if(gp[st]==-1)
                gp[st] = i;
            //printf("i=%d,st=%d\n",i,st);
        }
        bg = st;st = 1;
        int fi=-1,fk = -1;
        for(int i=0;i<4;i++)
        {
            for(it=fp.begin();it!=fp.end();it++)
            {
                if(it->second!=-1&&g(st,it->first)==2)
                {
                    if(fi==-1)
                        fi = i*le + it->second;
                }
            }
            st = g(st,bf);
        }
        st = 1;
        for(int i=0;i<4;i++)
        {
            //printf("i=%d\n",i);
            for(it=gp.begin();it!=gp.end();it++)
            {
                if(it->second!=-1&&g(it->first,st)==4)
                {
                    //printf("fi=%d,se=%d\n",it->first,it->second);
                    if(fk==-1)
                        fk = i*le + le-1-it->second;
                }
            }
            st = g(bg,st);
        }
        //printf("fi=%d,fk=%d\n",fi,fk);
        if(fi==-1||fk==-1)
        {
            puts("NO");
            continue;
        }
        if(fi+fk+2<x*le)
            puts("YES");
        else
            puts("NO");
    }
}
