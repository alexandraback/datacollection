#include<iostream>
#include<stdio.h>
#include <vector>
#include <string.h>
#include <math.h>
#define MAX 50
using namespace std;

int n,m;
double d,x[2],y[2];
int eps(double x,double y)
{
    double TMP=x-y;
    TMP=TMP>0?TMP:-TMP;
    if(TMP<1e-10)return 0;
    return x>y?1:-1;
}
char Room[MAX][MAX];
int Sx[5]= {0,0,1,1};
int sy[5]= {0,1,0,1};
class DOTS
{
    public:
    double x,y;
    bool flag;
    DOTS()
    {
        flag=0;
    }
    DOTS(double TMPX,double xy):x(TMPX),y(xy)
    {
        flag=0;
    }
    double operator *(const DOTS &a)const
    {
        return x*a.x+y*a.y;
    }
    double operator ^(const DOTS &a)const
    {
        return x*a.y-y*a.x;
    }
};

int Dx[5]= {-1,-1,1,1};
int Dy[5]= {-1,1,-1,1};
vector<DOTS>Vec;
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
            scanf("%s",Room[i]);
            for(int j=0; j<m; ++j)
            {
                if(Room[i][j]=='X')
                {
                    y[1]=2*(n-1-i)-1;
                    y[0]=2*i-1;
                    x[1]=2*(m-1-j)-1;
                    x[0]=2*j-1;
                }
            }
        }

        int Cnt=0;
        for(int i=0; i<=1; ++i)
        {
            if(eps(x[i],d)<=0)Cnt++;
            if(eps(y[i],d)<=0)Cnt++;
        }
        Vec.clear();
        for(int k=0; k<4; ++k)
        {
            double TMPX=0;
            for(int i=Sx[k];i<100000000; i++)
            {
                TMPX+=Dx[k]*x[i&1];
                if(eps(TMPX*TMPX,d*d)>0)break;
                double TMPY=0;
                for(int j=sy[k];j<100000000; ++j)
                {
                    TMPY+=Dy[k]*y[j&1];
                    if(eps(TMPX*TMPX+TMPY*TMPY,d*d)>0)break;
                    Vec.push_back(DOTS(TMPX,TMPY));
                }
            }
        }

        for(vector <DOTS>::iterator i=Vec.begin(); i!=Vec.end(); i++)
        {
            if(i->flag!=1)
            {
                Cnt++;
                for(vector <DOTS>::iterator j=i; j!=Vec.end(); j++)
                {
                    if(i!=j)
                    {
                        if(eps((*j)^(*i),0)==0&&eps((*j)*(*i),0)>0)
                            j->flag=1;
                    }
                    else continue;
                }
            }
            else continue;
        }
        printf("Case #%d: %d\n",cas,Cnt);
    }
}
