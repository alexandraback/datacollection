#include <cstdlib>
#include <cstdio>
using namespace std;
#define rep(i,n) for (int i=0;i<n;++i)

const int Smax = 1123;
int n;
char s[Smax];

int main(int argc, const char *argv[])
{
    int _tn; scanf("%d", &_tn);
    rep(_ti, _tn)
    {
        scanf("%d%s", &n, s);
        int re = 0, np = 0;
        rep(i, n+1)
        {
            if (np < i) { re += i - np; np = i; }
            np += s[i] - '0';
        }
        printf("Case #%d: %d\n", _ti+1, re);
    }
    return 0;
}

