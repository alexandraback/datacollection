#include<iostream>
#include<stdio.h>
#include <vector>
#include <string.h>
#include <math.h>
#define MAX 35
using namespace std;
char Map[MAX][MAX];
int n,m;
double d,x[2],y[2];
int eps(double x,double y)
{
    if(fabs(x-y)<1e-10)return 0;
    return x>y?1:-1;
}
int dirx[]= {-1,-1,1,1};
int diry[]= {-1,1,-1,1};
int sx[]= {0,0,1,1};
int sy[]= {0,1,0,1};
struct SD
{
    double x,y;
    bool s;
    SD()
    {
        s=0;
    }
    SD(double xx,double xy):x(xx),y(xy)
    {
        s=0;
    }
    double operator *(const SD &a)const
    {
        return x*a.x+y*a.y;
    }
    double operator ^(const SD &a)const
    {
        return x*a.y-y*a.x;
    }
};
vector<SD>V;
int main()
{
    //freopen("D-small-attempt0.in","r",stdin);
    //freopen("out","w",stdout);
    int Cases;
    scanf("%d",&Cases);
    for(int cas=1; cas<=Cases; ++cas)
    {
        scanf("%d%d%lf",&n,&m,&d);
        for(int i=0; i<n; ++i)
        {
            scanf("%s",Map[i]);
            for(int j=0; j<m; ++j)
            {
                if(Map[i][j]=='X')
                {
                    x[1]=2*(m-1-j)-1;
                    x[0]=2*j-1;
                    y[1]=2*(n-1-i)-1;
                    y[0]=2*i-1;
                }
            }
        }

        int Cnt=0;
        for(int i=0; i<=1; ++i)
        {
            if(eps(x[i],d)<=0)Cnt++;
            if(eps(y[i],d)<=0)Cnt++;
        }
        V.clear();
        for(int k=0; k<4; ++k)
        {
            double xx=0;
            for(int i=sx[k];; i++)
            {
                xx+=dirx[k]*x[i&1];
                if(eps(xx*xx,d*d)>0)break;
                double yy=0;
                for(int j=sy[k];; ++j)
                {
                    yy+=diry[k]*y[j&1];
                    if(eps(xx*xx+yy*yy,d*d)>0)break;
                    V.push_back(SD(xx,yy));
                }
            }
        }

        for(vector <SD>::iterator i=V.begin(); i!=V.end(); i++)
        {
            if(i->s!=1)
            {
                Cnt++;
                for(vector <SD>::iterator j=i; j!=V.end(); j++)
                {
                    if(i!=j)
                    {
                        if(eps((*j)^(*i),0)==0&&eps((*j)*(*i),0)>0)
                            j->s=1;
                    }
                    else continue;
                }
            }
            else continue;
        }
        printf("Case #%d: %d\n",cas,Cnt);
    }
}
