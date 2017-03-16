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

bool found[6][6][25];
string ans[6][6][25];
char M[5][6];

bool go[5][5];
int dr[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};
bool visited[5][5];

int R,C;

int dfs(int r, int c){
    if(visited[r][c] || M[r][c] == '*') return 0;
    visited[r][c] = true;
    
    if(!go[r][c]) return 1;
    
    int ret = 1;
    
    for(int k = 0;k < 8;++k){
        int r2 = r + dr[k],c2 = c + dc[k];
        
        if(r2 >= 0 && r2 < R && c2 >= 0 && c2 < C)
            ret += dfs(r2,c2);
    }
    
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    
    memset(found,false,sizeof found);
    
    for(R = 2;R <= 5;++R){
        for(C = 2;C <= 5;++C){
            for(int mask = 0;mask < (1 << (R * C)) - 1;++mask){
            //for(int mask = 0;mask <= 0;++mask){
                int mines = __builtin_popcount(mask);
                
                //cout << R << " " << C << " - " << mines << endl;
                if(found[R][C][mines] || mines == R*C - 1) continue;
                //cout << R << " " << C << " " << mines << endl;
                
                memset(M,0,sizeof M);
                
                for(int r = 0;r < R;++r)
                    for(int c = 0;c < C;++c)
                        if((mask & (1 << (r * C + c))) != 0)
                            M[r][c] = '*';
                        else
                            M[r][c] = '.';
                
                memset(go,true,sizeof go);
                
                //cout << "A" << endl;
                
                for(int r = 0;r < R;++r)
                    for(int c = 0;c < C;++c){
                        if(M[r][c] == '*')
                            go[r][c] = false;
                        
                        for(int k = 0;k < 8;++k){
                            int r2 = r + dr[k],c2 = c + dc[k];
                            
                            if(r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && M[r2][c2] == '*')
                                go[r][c] = false;
                        }
                        
                        //if(go[r][c]) cout << r << " - " << c << endl;
                    }
                
                //cout << "B" << endl;
                
                bool start = false;
                
                for(int r = 0;r < R && !start;++r){
                    //cout << "r = " << r << endl;
                    for(int c = 0;c < C && !start;++c){
                        //cout << "c = " << c << endl;
                        if(go[r][c]){
                            start = true;
                            memset(visited,false,sizeof visited);
                            
                            //cout << "dfs" << endl;
                            
                            if(dfs(r,c) == R * C - mines){
                                found[R][C][mines] = true;
                                M[r][c] = 'c';
                                
                                for(int i = 0;i < R;++i)
                                    for(int j = 0;j < C;++j)
                                        ans[R][C][mines] += M[i][j];
                            }
                        }
                    }
                }
                
                //cout << found[R][C][mines] << " " << ans[R][C][mines] << endl;
                //cout << "C" << endl;
            }
        }
    }
    
    int TC,M;
    
    cin >> TC;
    
    for(int tc = 1;tc <= TC;++tc){
        cin >> R >> C >> M;
        
        cout << "Case #" << tc << ":\n";
        
        if(R == 1){
            for(int i = 0;i < C;++i){
                if(i < M) cout << "*";
                else if(i == C - 1) cout << "c";
                else cout << ".";
            }
            cout << '\n';
        }else if(C == 1){
            for(int i = 0;i < R;++i){
                if(i < M) cout << "*\n";
                else if(i == R - 1) cout << "c\n";
                else cout << ".\n";
            }
        }else if(M == R * C - 1){
            for(int i = 0;i < R;++i){
                for(int j = 0;j < C;++j){
                    if(i == 0 && j == 0) cout << "c";
                    else cout << "*";
                }
                cout << '\n';
            }
        }else if(!found[R][C][M]){
            cout << "Impossible\n";
        }else{
            for(int i = 0;i < R;++i){
                for(int j = 0;j < C;++j)
                    cout << ans[R][C][M][i * C + j];
                cout << '\n';
            }
        }
    }
    
    return 0;
}
