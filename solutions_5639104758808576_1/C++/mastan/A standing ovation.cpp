#include <cstdio>
#include <algorithm>

using namespace std;

char base[1005];
int tc;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&tc);
    for (int it=1; it<=tc; it++)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",base);
        int cnt,ret;
        cnt=0;
        ret=0;
        for (int pl=0; pl<=n; pl++)
        {
            if (cnt<pl)
            {
                cnt++;
                ret++;
            }
            cnt+=base[pl]-'0';
        }
        printf("Case #%d: %d\n",it,ret);
    }
}
