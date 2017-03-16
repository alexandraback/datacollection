#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
//bool f[2000010];
int main()
{
    freopen("a.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cas = 0;
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int ans = 0;

        for(int i=a; i<=b; i++)
        {
            int x = i;
            int cnt = 0;
            int l = 1;
            while(x)
            {
                x/=10;
                cnt++;
                l*=10;
            }
            l/=10;
            x = i;
           // memset(f,0,sizeof(f));
            set<int>ss;
            for(int j=0; j<cnt; j++)
            {
                x = x%10*l+x/10;
                if(x>i&&x<=b&&ss.find(x)==ss.end())
                {
                    ans++;
                    ss.insert(x);
                }
            }
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
