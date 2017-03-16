#include <cstdio>
#include <algorithm>

using namespace std;
char s[2000];
int T,N;

int main()
{
    freopen("stand.in","r",stdin);
    freopen("stand.out","w",stdout);

    scanf("%d",&T);
    for(int tst = 1; tst <= T; ++tst)
    {
        scanf("%d %s\n",&N,&s);
        int crt = 0,ans = 0;
        for(int i = 0; i <= N; ++i)
        {
            if(crt < i)
            {
                ans += (i - crt);
                crt = i;
            }
            crt += (s[i] - 48);
        }
        printf("Case #%d: %d\n",tst,ans);
    }

    return 0;
}
