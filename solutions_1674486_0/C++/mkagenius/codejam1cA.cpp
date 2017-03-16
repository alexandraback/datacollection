/*
ID: mkagenius1
LANG: C++
TASK:
*/

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<queue>

using namespace std;

bool ans;
bool mark[1010];
vector<int> vec[1010];
int dfs(int v){
    for(int i= 0; i < vec[v].size(); i++){
        if(!mark[vec[v][i]]){
            mark[vec[v][i]] = 1;
            dfs(vec[v][i]);
        }else ans = true; // diamond
    }
    return 0;
}
/* Main Code goes Here-after */
int main()
{
    int t; cin >> t;
    int kase = 0;
    while(t--){
        kase++;
        int n; cin >> n;
        for(int i = 0 ; i < n ; i ++){
            vec[i].clear();
        }
        
        for(int i = 0 ; i < n ; i ++){
            int m; cin >> m;
            for(int j = 0 ; j < m ; j++){
                int v;cin >> v;
                v--;
                vec[i].push_back(v);
            }
        }
        ans = 0;
        for(int i = 0 ; i < n; i ++){
            memset(mark, 0, sizeof mark);
            dfs(i);
        }
        if(ans) cout << "Case #"<<kase << ": Yes\n";  
        else cout << "Case #"<<kase << ": No\n";
    }
    return 0;
}
        
