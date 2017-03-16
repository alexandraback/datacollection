#include <iostream>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int h,w,d;
vector<string> data;
int x,y;
int ret;

set<PII> vectors;

int gcd(int a,int b)
{
    if(a<0) return gcd(-a,b);
    if(b<0) return gcd(a,-b);
    if(a<b) return gcd(b,a);
    if(b == 0) return a;
    return gcd(b, a%b);
}

bool move(int &xx, int &yy, int &dx, int &dy)
{
    int gg = gcd(dx,dy);
    if(gg != 1)
    {
        int ddx = dx/gg;
        int ddy = dy/gg;
        for(int i=0;i<gg;i++)
        {
            if(move(xx,yy,ddx,ddy)) return true;
        }
        return false;
    }

    xx += dx;
    yy += dy;
    
    while(true)
    {
        int pxx=xx, pyy = yy;
        if(xx < 2) { xx = 2 + (2 - xx); dx = -dx; }
        if(yy < 2) { yy = 2 + (2 - yy); dy = -dy; }
        if(xx > h*2-2) { xx = (h*2-2) - (xx - (h*2-2)); dx = -dx; }
        if(yy > w*2-2) { yy = (w*2-2) - (yy - (w*2-2)); dy = -dy; }
        if(pxx == xx && pyy == yy) break;
    }

    return xx == x && yy == y;
}

void process(void)
{
    cin >> h >> w >> d;
    data.resize(h);
    for(int i=0;i<h;i++)
    {
        cin >> data[i];
        for(int j=0;j<size(data[i]);j++)
        {
            if(data[i][j] == 'X')
            {
                x=i,y=j;
                break;
            }
        }
    }

    ret = 0;
    vectors.clear();

    if((x-1)*2+1 <= d) ret++;
    if((y-1)*2+1 <= d) ret++;
    if((h-2-x)*2+1 <= d) ret++;
    if((w-2-y)*2+1 <= d) ret++;
    
    x=x*2+1;
    y=y*2+1;

    for(int i=1;i<=50;i++)
    {
        for(int j=1;j<=50;j++)
        {
            if(i*i+j*j > d*d) break;

            int dx = i / gcd(i,j);
            int dy = j / gcd(i,j);
            int pow = dx*dx+dy*dy;

            if(vectors.count(mp(dx,dy))) continue;
            vectors.insert(mp(dx,dy));

            int k;
            for(k=1;;k++)
            {
                if(pow*k*k > d*d) break;
            }
            k--;
            dx *= k * 2;
            dy *= k * 2;

            int tret = ret;

            int xx = x, yy = y;
            int ddx = dx, ddy = dy;
            ret += move(xx,yy,ddx,ddy);
            xx=x,yy=y;
            ddx = dx, ddy = -dy;
            ret += move(xx,yy,ddx,ddy);
            xx=x,yy=y;
            ddx = -dx, ddy = dy;
            ret += move(xx,yy,ddx,ddy);
            xx=x,yy=y;
            ddx = -dx, ddy = -dy;
            ret += move(xx,yy,ddx,ddy);
        }
    }
    cout << ret << endl;
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        printf("Case #%d: ",i);
        process();
        cerr << i << endl;
    }
}
