#include<cstdio>
#include<iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int Maxn=33;
char map[Maxn][Maxn];
int n,m;
double d,x[2],y[2];
int eps(double x,double y)
{
    if(fabs(x-y)<1e-10)return 0;
    return x<y?-1:1;
}
int dirx[]={-1,-1,1,1};
int diry[]={-1,1,-1,1};
int sx[]={0,0,1,1};
int sy[]={0,1,0,1};
struct Seg
{
    double x,y;
    bool s;
    Seg(){s=0;}
    Seg(double _x,double _y):x(_x),y(_y){s=0;}
    double operator *(const Seg &a)const
    {
        return x*a.x+y*a.y;
    }
    double operator ^(const Seg &a)const
    {
        return x*a.y-y*a.x;
    }
};
vector<Seg>vec;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;++cas)
    {
        scanf("%d%d%lf",&n,&m,&d);
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

        int cnt=0;
        if(eps(x[0],d)<=0)cnt++;
        if(eps(x[1],d)<=0)cnt++;
        if(eps(y[0],d)<=0)cnt++;
        if(eps(y[1],d)<=0)cnt++;
        vec.clear();
        for(int k=0;k<4;++k)
        {
            double xx=0;

            for(int i=sx[k];;i++)
            {
                xx+=dirx[k]*x[i&1];
                if(eps(xx*xx,d*d)>0)break;
                double yy=0;
                for(int j=sy[k];;++j)
                {
                    yy+=diry[k]*y[j&1];
                    if(eps(xx*xx+yy*yy,d*d)>0)break;
                    vec.push_back(Seg(xx,yy));
                }
            }
        }

        for(vector <Seg>::iterator it=vec.begin();it!=vec.end();it++)
        {
            if(it->s==1)continue;
            cnt++;
            for(vector <Seg>::iterator it2=it;it2!=vec.end();it2++)
            {
                if(it==it2)continue;
                if(eps((*it2)^(*it),0)==0&&eps((*it2)*(*it),0)>0)
                it2->s=1;
            }
        }
        printf("Case #%d: %d\n",cas,cnt);
    }
}
