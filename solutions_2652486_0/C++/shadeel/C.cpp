#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int num[8000][12];

int main(void){
    
    freopen("C-small-1-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int cas, c=0, r, n, m, k;
    
    scanf("%d", &cas);
    while( cas-- ){
        scanf("%d %d %d %d", &r, &n, &m, &k);
        for(int i=0; i<r; ++i)for(int j=0; j<k; ++j)
            scanf("%d", &num[i][j]);
        
        printf("Case #%d:\n", ++c);
        for(int i=2; i<=m; ++i)for(int j=2; j<=m; ++j)for(int k=2; k<=m; ++k)
        printf("%d%d%d\n", i ,j, k);
        
    }
    
    return 0;
}
