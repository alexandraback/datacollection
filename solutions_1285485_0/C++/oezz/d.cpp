#include <cstdio>
#include <cstring>
#include <set>

#define MP make_pair

using namespace std;

set <pair<int,int> > mk;

int dx[4]={1,1,-1,-1};
int dy[4]={1,-1,1,-1};

int gcd(int a, int b)
{
    while (a)
    {
        int t=b%a;
        b=a, a=t;
    }
    return b;
}

int ABS(int x) {return x>0?x:-x;}

int solve(int x, int y, int h, int w, int d)
{
    int ret=0;
    mk.clear();
    for (int i=0; i*2*h-x*2<=d; ++i)
        for (int j=0; j*2*w-y*2<=d; ++j)
            for (int k=0; k<4; ++k)
                for (int u=0; u<4; ++u)
                {
                    int xx=i*2*h*dx[k]+x*dx[u]-x, yy=j*2*w*dy[k]+y*dy[u]-y;
                    if ((xx||yy)&& xx*xx+yy*yy<=d*d)
                    {
                        int t=gcd(ABS(xx),ABS(yy));
                        xx/=t, yy/=t;
                        if (mk.find(MP(xx,yy))==mk.end()) {mk.insert(MP(xx,yy)); ++ret;}
                    }
                }
    return ret;
}

int main()
{
    int cas,h,w,d,x,y;
    char str[200];
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    scanf("%d", &cas);
    for (int T=1; T<=cas; ++T)
    {
        scanf("%d%d%d", &h,&w,&d);
        for (int i=0; i<h; ++i)
        {
            scanf("%s", str);
            for (int j=0; str[j]; ++j)
                if(str[j]=='X') {x=i, y=j;}
        }
        int ans=solve(x*2-1, y*2-1, h*2-4, w*2-4, d*2);
        printf("Case #%d: %d\n", T, ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
