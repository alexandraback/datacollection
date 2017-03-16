#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

char str[10100];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        scanf("%s",str);
        int ans=0,now=0;
        for(int i=0;i<=n;i++) {
            now+=str[i]-'0';
            if(now==0) {
                ans++;
                continue;
            }
            now--;
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}

