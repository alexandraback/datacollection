#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int n,m,a[200], ans;

int main(){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d", &T);
    for(int cs=1;cs<=T;++cs){
        printf("Case #%d: ",cs);
        scanf("%d%d", &m,&n);
        for(int i=0; i<n; ++i)
            scanf("%d", a+i);

        ans = n;
        sort(a,a+n);
        int cnt = 0;
        int p=0;;
        for(p=0;m<=a[n-1]; ++p){
            for(;cnt<n && m>a[cnt];++cnt)
                m += a[cnt];
            ans = min(ans, n-cnt+p);
            m += m-1;
            if(m==1)break;
        }
        if(m>a[n-1])ans = min(ans, p);
        printf("%d\n", ans);
    }
}
