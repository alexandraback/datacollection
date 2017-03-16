#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct GRID{
    int x, y, hei;
};

GRID grid[10000];
int lawn[100][100];

bool cmp(GRID a, GRID b){
    if( a.hei < b.hei ) return true;
    else                return false;
}

int main(void){
    
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int cas, c=0, n, m, size, org;
    int vmax[100], hmax[100];
    
    scanf("%d", &cas);
    while( cas-- ){
        scanf("%d %d", &n, &m);
        for(int i=0, a=0; i<n; ++i)for(int j=0; j<m; ++j){
            scanf("%d", &lawn[i][j]);
            grid[a].x = i;  grid[a].y = j;
            grid[a++].hei = lawn[i][j];
        }
        size = m * n;
        sort(grid, grid+size, cmp);
        org = grid[size-1].hei;
        
        memset(vmax,0,sizeof(vmax));
        memset(hmax,0,sizeof(hmax));
        for(int i=0; i<n; ++i)for(int j=0; j<m; ++j)
        if( vmax[i] < lawn[i][j] )  vmax[i] = lawn[i][j];
        for(int i=0; i<m; ++i)for(int j=0; j<n; ++j)
        if( hmax[i] < lawn[j][i] )  hmax[i] = lawn[j][i];
        
        bool ans = true;
        for(int i=0; grid[i].hei<org && ans; ++i)
        if( grid[i].hei<vmax[grid[i].x] && grid[i].hei<hmax[grid[i].y] )
            ans = false;
        
        printf("Case #%d: ", ++c);
        if( ans )   puts("YES");
        else        puts("NO");
    }
    
    return 0;
}
