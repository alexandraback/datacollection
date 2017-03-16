#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define rep(i,n) for (int i=0;i<n;++i)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)

const int side[] = {0,1,1,2,3,4,4};
int X,R,C;

int main(int argc, const char *argv[])
{
    int _tn; scanf("%d", &_tn);
    rep(_ti, _tn)
    {
        scanf("%d%d%d", &X, &R, &C);
        if (R<C) { int t = R; R = C; C = t; }
        bool re;
        if (X > 6) re = false;
        else if (C*R % X) re = false;
        else if (R < X) re = false;
        else if (C < side[X]) re = false;
        else re = true;
        printf("Case #%d: %s\n", _ti+1, (re?"GABRIEL":"RICHARD"));
    }
    return 0;
}
