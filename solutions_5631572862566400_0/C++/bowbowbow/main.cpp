#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;

#define MAXN 1100
int N, graph[MAXN], inverse[MAXN], ans, len;

vector<int> inv[MAXN];
vector<bool> ck;

int root= 1, depth =1;

void dfs(int now){
    depth++;
    ck[now] = true;
    
    int next = graph[now];
    
    if(next == root){
        ans = max(ans, depth);
        return;
    }
    
    if(!ck[next]){
        dfs(next);
    }
}

void bfs(int now, int depth){
    ck[now] = true;
    
    int cnt = 0;
    for(int i = 0; i < inv[now].size() ; i++){
        int next = inv[now][i];
        if(!ck[next]){
            cnt++;
            bfs(next, depth +1);
        }
    }
    if(cnt==0){
        len = max(len, depth);
    }
}

int main(){
    int T;
    ifstream ifp("/Users/clsrn1581/Desktop/codejam/C/C-small-attempt0.in");
    ofstream ofp("/Users/clsrn1581/Desktop/codejam/C/C-small-attempt0.out");
    
    ifp >> T;
    
    for(int t = 1; t <=T; t++){
        ifp >> N;
        
        for(int i = 0; i <= N ; i++)
            inv[i].clear();
        
        for(int i = 1 ; i<= N ; i++){
            int tmp;
            ifp >> tmp;
            graph[i] = tmp;
            inv[tmp].push_back(i);
        }
        
        ans = 0;
        for(int i =1 ; i<= N ; i++){
            ck = vector<bool>(N+1, false);
            root = i, depth = 0;
            dfs(root);
        }
        
        for(int i =1 ; i<= N ; i++){
            int a = 0, b = 0;
            int next = graph[i];
            if(graph[next] == i){
                len = 0;
                ck = vector<bool>(N+1, false);
                ck[i] = 1, ck[next] = 1;
                bfs(i, 0);
                a = len;
                
                len = 0;
                ck = vector<bool>(N+1, false);
                ck[i] = 1, ck[next] = 1;
                bfs(next, 0);
                b = len;
                
                ans = max(ans, a + b +2);
            }
        }
        ofp << "Case #"<< t << ": " << ans << endl;
        
    }
    return 0;
}