#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#define PB push_back
#define MP make_pair
#define clr(a,b)	(memset(a,b,sizeof(a)))
#define rep(i,a)	for(int i=0; i<(int)a.size(); i++)

const int INF = 0x3f3f3f3f;
const int eps = 1E-8;


struct cpoint
{
    double x,y;
    cpoint(int a=0,int b=0)
    {
        x=a,y=b;
    }

    cpoint operator-(const cpoint &u) const
    {
        return cpoint(x-u.x, y-u.y);
    }

    int operator*(const cpoint &u) const
    {
        return x*u.y - y*u.x;
    }

    int operator^(const cpoint &u) const
    {
        return x*u.x + y*u.y;
    }
};

int dcmp(int x)
{
    if (x < -eps) return -1;
    else return x > eps;
}

int dis(cpoint p, cpoint q)   // 两点距离
{
    return sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
}

int cross(cpoint o, cpoint p, cpoint q)   // 叉积
{
    return (p-o) * (q-o);
}

int dot(cpoint o, cpoint p, cpoint q)   // 点积
{
    return (p-o) ^ (q-o);
}

bool PointOnLine(cpoint p0, cpoint p1, cpoint  p2)   // 判点p0在直线上p1p2
{
    return dcmp(cross(p0, p1, p2)) == 0;
}

int PointToLine(cpoint p0, cpoint p1, cpoint p2, cpoint &cp)   // 点到直线的距离，cp为点p0在直线上的射影
{
    int d = dis(p1, p2);
    int s = cross(p1, p2, p0) / d ;
    cp.x = p0.x + s * (p2.y - p1.y) / d;
    cp.y = p0.y - s * (p2.x - p1.x) / d;
    return fabs(s);  // s为有向距离
}

bool  PointOnSegment(cpoint p0, cpoint p1, cpoint p2)  //判点p0在线段上p1p2
{
    return dcmp(cross(p0, p1, p2)) == 0 && dcmp(dot(p0, p1, p2)) <= 0;
}

int PointToSeg(cpoint p0, cpoint p1, cpoint p2)   	//点到线段最短距离
{
    cpoint cp;
    int d = PointToLine(p0, p1, p2, cp);
    if (PointOnSegment(cp, p1, p2)) return d;
    else return min(dis(p0, p1), dis(p0, p2));
}

int DisPallSeg(cpoint p0,cpoint p1,cpoint p2, cpoint p3)  	//两平行线段距离
{
    return min( min(PointToSeg(p0, p2, p3),PointToSeg(p1, p2, p3)),
                min(PointToSeg (p2, p0, p1), PointToSeg(p3, p0, p1)) );
}

//下标0开始
bool cmp(const cpoint &a,const cpoint &b)
{
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

int graham(int n,cpoint p[],cpoint res[])	//<=不共线
{
    sort(p,p+n,cmp);
    if(n == 0)  return 0;
    res[0] = p[0];
    if(n == 1)  return 1;
    res[1] = p[1];
    if(n == 2)  return 2;

    int top = 1,len;
    for(int i=2; i<n; i++)
    {
        while(top && dcmp(cross(res[top-1],res[top],p[i])) <= 0)
            top--;
        res[++top] = p[i];
    }

    len = top;
    res[++top] = p[n-2];
    for(int i=n-3; i>=0; i--)
    {
        while(top != len && dcmp(cross(res[top-1],res[top],p[i])) <= 0)
            top--;
        res[++top] = p[i];
    }
    return top;
}


cpoint inp[30], out[30];


int nextN(int n)
{
    int x = n&(-n);
    int t = n+x;
    return ((n^t)/x)>>2|t;
}



int T;
int n,m,k;

bool g[30][30];

int main()
{
//    freopen("D:\\in.txt","r",stdin);
	freopen("D:\\C-small-attempt1.in","r",stdin);
	freopen("D:\\out.txt","w",stdout);

    int cas = 1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);

        int tot = n*m;
        int cnt1 = k;
        int cnt0 = tot - cnt1;

        int st = (1<<k) - 1;
        int ed = (1<<tot ) - (1<<cnt0);

        int ans = n*m;

        for(int state = st; state <=ed; state = nextN(state))
        {

            int tot_point = 0;
            for(int j=0; j<n*m; j++)
            {
                if( ((1<<j) &  state) != 0 )
                {
                    int h = j / m;
                    int l = j % m;

                    inp[tot_point++] = cpoint(h, l);
                }
            }

            int cnt = graham(tot_point, inp, out);

            if(cnt == 1)
            {
                ans = 1;
                continue;
            }
            else if(cnt == 2)
            {
                ans = max(abs(out[1].x - out[0].x)    , abs(out[1].y - out[0].y)) + 1;
                continue;
            }
            else
            {
                int res = 0;
                for(int i=0; i<cnt - 1; i++)
                {
                    int x = abs(out[i].x - out[i+1].x);
                    int y = abs(out[i].y - out[i+1].y);

                    res += max(x, y) + 1;
                }
                res +=  max(abs(out[cnt-1].x - out[0].x)    , abs(out[cnt-1].y - out[0].y)) + 1;
                res -= cnt;
                ans = min(res, ans);
            }
        }
        printf("Case #%d: %d\n",cas++, ans);
    }

    return 0;
}
