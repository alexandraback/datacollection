#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
static const int MAXN = 33;
static const double eps = 1e-10;
static const int dirx[] = {-1,-1,1,1};
static const int diry[] = {-1,1,-1,1};
static const int sx[] = {0,0,1,1};
static const int sy[] = {0,1,0,1};

int n,m;
char map[MAXN][MAXN];
double d,x[2],y[2];

inline int dblcmp(double x)
{
    if(fabs(x) < eps)
    {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

inline int compare(double x,double y)
{
    return dblcmp(x - y);
}

struct Segment
{
    bool s;
    double x,y;
    Segment()
    {
        s = false;
    }
    Segment(double x0, double y0)
    {
        x = x0, y = y0;
        s = false;
    }
    double operator *(const Segment &seg)const
    {
        return x * seg.x + y * seg.y;
    }
    double operator ^(const Segment &seg)const
    {
        return x * seg.y - y * seg.x;
    }
};
vector<Segment>vec;

int main()
{
    //freopen("D-small-attempt0.in", "r", stdin);
    //freopen("D-small-attempt0.out", "w", stdout);
    int t;
    double tempX, tempY, tempD;
    scanf("%d",&t);
    for(int cas=1;cas<=t;++cas)
    {
        scanf("%d%d%lf",&n,&m,&d);
        for(int i=0;i<n;++i)
        {
            scanf("%s",map[i]);
            for(int j=0;j<m;++j)
            {
                if('X' == map[i][j])
                {
                    x[0]=(j<<1)-1;
                    x[1]=((m-1-j)<<1)-1;
                    y[0]=(i<<1)-1;
                    y[1]=((n-1-i)<<1)-1;
                }
            }
        }
        vec.clear();
        int cnt = (compare(x[0],d)<=0) + (compare(x[1],d)<=0) + (compare(y[0],d)<=0) + (compare(y[1],d)<=0);
        for(int k=0;k<4;++k)
        {
            tempX=0;
            for(int i=sx[k];;i++)
            {
                tempX += dirx[k] * x[i&1];
                tempD = d * d;
                if(compare(tempX * tempX, tempD) > 0)
                {
                    break;
                }
                tempY = 0;
                for(int j=sy[k];;++j)
                {
                    tempY += diry[k] * y[j&1];
                    if(compare(tempX * tempX + tempY * tempY, tempD) > 0)
                    {
                        break;
                    }
                    vec.push_back(Segment(tempX,tempY));
                }
            }
        }
        for(int i=0;i<vec.size();++i)
        {
            if(vec[i].s)
            {
                continue;
            }
            cnt++;
            for(int j=0;j<vec.size();++j)
            {
                if(i == j)
                {
                    continue;
                }
                if(dblcmp(vec[j]^vec[i])==0)
                {
                    if(dblcmp(vec[j]*vec[i])>0)
                    {
                        vec[j].s = true;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",cas,cnt);
    }
}
