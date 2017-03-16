#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int n,m,a[200][200],lower[400],upper[400];
int col[400],row[400];
int main(){
    freopen("B-large.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d", &T);
    for(int cs=1;cs<=T;++cs){
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                scanf("%d",&a[i][j]);
        for(int i=0; i<400; ++i){
            col[i] = row[i] = lower[i]=0;
            upper[i] = 400;
        }
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j){
                col[j] = max(col[j], a[i][j]);
                row[i] = max(row[i], a[i][j]);
            }
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j){
                lower[i] = max(lower[i], a[i][j]);
                lower[j+n] = max(lower[j+n], a[i][j]);
                if(a[i][j]!=col[j])
                    upper[i] = min(upper[i], a[i][j]);
                if(a[i][j]!=row[i])
                    upper[j+n] = min(upper[j+n], a[i][j]);
            }
        int fg = 1;
        for(int i=0; i<400; ++i)
            if(lower[i]>upper[i]) fg = 0;
        printf("Case #%d: ", cs);
        if (fg) puts("YES");
            else puts("NO");
    }
}
