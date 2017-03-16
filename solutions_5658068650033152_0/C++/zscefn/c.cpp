#include <iostream>
#include <cstring>
using namespace std;

int grid[30][30];
int dp[30][30];
int n,m;
void f(int x, int y) {
    dp[x][y] = 1;
    for(int i = 0; i < 4; ++i) {
        int ux = x;
        int uy = y;
        if(i == 0) ++ux;
        if(i == 1) --ux;
        if(i == 2) ++uy;
        if(i == 3) --uy;
        if(ux >= 0 && ux < n && uy >= 0 && uy < m) {
            if(!dp[ux][uy] && !grid[ux][uy]) {
                f(ux, uy);
            }
        }
    }
}
int main() {
    int t;
    cin>>t;
    for(int i = 0; i < t; ++i) {
        int k;
        cin>>n>>m>>k;
        int best = 1e9;
        for(int qq = 0; qq < (1<<20); ++qq) {
            int bcount = 0;
            for(int i= 0; i < n*m; ++i) {
                if(qq & (1<<i)) {
                    grid[i/m][i%m] = 1;
                    ++bcount;
                }
                else grid[i/m][i%m] = 0;
            }
            memset(dp, 0, sizeof(dp));
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if((i == 0 || i == n-1 || j == 0 || j == m-1) && !dp[i][j] && grid[i][j] == 0) {
                        f(i, j);
                    }
                }
            }
            int cute = 0;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if(dp[i][j] == 1) ++cute;
                }
            }
            if(n*m - cute >= k) {
                best = min(best, bcount);
            }
        }
        cout<<"Case #"<<i+1<<": "<<best<<'\n';
    }

}
