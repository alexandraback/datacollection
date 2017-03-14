#include<cstdio>
#include<iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
#define Maxn 35
char map[Maxn][Maxn];
int n,m;
double d,x[2],y[2];
int ans;
int eps(double x,double y)
{
    if(fabs(x-y)<1e-10)return 0;
    return x<y?-1:1;
}
int xx[4]={-1,-1,1,1};
int yy[4]={-1,1,-1,1};
int sx[4]={0,0,1,1};
int sy[4]={0,1,0,1};
struct hh
{
    double x,y;
    bool s;
    hh(){s=0;}
    hh(double _x,double _y):x(_x),y(_y){s=0;}
    double operator *(const hh &a)const
    {
        return x*a.x+y*a.y;
    }
    double operator ^(const hh &a)const
    {
        return x*a.y-y*a.x;
    }
};

vector<hh>vec;
void init()
{
     for(int i=0;i<n;++i)
        {
            scanf("%s",map[i]);
            for(int j=0;j<m;++j)
            {
                if(map[i][j]=='X')
                {
                    x[0]=2*j-1;
                    x[1]=2*(m-1-j)-1;
                    y[0]=2*i-1;
                    y[1]=2*(n-1-i)-1;
                }
            }
        }

}
void solve()
{
    if(eps(x[0],d)<=0)ans++;
        if(eps(x[1],d)<=0)ans++;
        if(eps(y[0],d)<=0)ans++;
        if(eps(y[1],d)<=0)ans++;
        vec.clear();
        for(int k=0;k<4;++k)
        {
            double xxx=0;

            for(int i=sx[k];;i++)
            {
                xxx+=xx[k]*x[i&1];
                if(eps(xxx*xxx,d*d)>0)break;
                double yyy=0;
                for(int j=sy[k];;++j)
                {
                    yyy+=yy[k]*y[j&1];
                    if(eps(xxx*xxx+yyy*yyy,d*d)>0)break;
                    vec.push_back(hh(xxx,yyy));
                }
            }
        }

        for(vector <hh>::iterator it=vec.begin();it!=vec.end();it++)
        {
            if(it->s==1)continue;
            ans++;
            for(vector <hh>::iterator it2=it;it2!=vec.end();it2++)
            {
                if(it==it2)continue;
                if(eps((*it2)^(*it),0)==0&&eps((*it2)*(*it),0)>0)
                it2->s=1;
            }
        }
}
int main()
{
    freopen("in4.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;++cas)
    {
        scanf("%d%d%lf",&n,&m,&d);
       init();
        ans=0;
        solve();
        printf("Case #%d: %d\n",cas,ans);
    }
}

