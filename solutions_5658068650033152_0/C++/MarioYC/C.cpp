#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

int N,M,K;
bool grid[20][20],visited[20][20];
int dr[] = {-1,0,1,0},dc[] = {0,-1,0,1};

int dfs(int r, int c){
    if(visited[r][c]) return 0;
    visited[r][c] = true;
    
    int ret = 1;
    
    for(int i = 0;i < 4;++i){
        int r2 = r + dr[i],c2 = c + dc[i];
        
        if(r2 >= 0 && r2 < N && c2 >= 0 && c2 < M && grid[r2][c2])
            ret += dfs(r2,c2);
    }
    
    return ret;
}

int main(){
    //ios::sync_with_stdio(0);
    
    int TC;
    
    cin >> TC;
    
    for(int tc = 1;tc <= TC;++tc){
        cin >> N >> M >> K;
        int total = N * M;
        
        int ans = total;
        
        for(int mask = 0;mask < (1 << total);++mask){
            memset(grid,true,sizeof grid);
            
            for(int i = 0;i < N;++i){
                for(int j = 0;j < M;++j){
                    if(mask & (1 << (M * i + j)))
                        grid[i][j] = false;
                    //if(mask == 0) cout << grid[i][j] << " ";
                }
                //if(mask == 0) cout << endl;
            }
            
            int out = 0;
            
            memset(visited,false,sizeof visited);
            
            for(int i = 0;i < M;++i){
                if(grid[0][i]) out += dfs(0,i);
                if(grid[N - 1][i]) out += dfs(N - 1,i);
            }
            
            for(int i = 0;i < N;++i){
                if(grid[i][0]) out += dfs(i,0);
                if(grid[i][M - 1]) out += dfs(i,M - 1);
            }
            
            //if(mask == 0) cout << out << endl;
            if(total - out >= K) ans = min(ans,__builtin_popcount(mask));
        }
        
        cout << "Case #" << tc << ": " << ans << endl;
    }
    
    return 0;
}
