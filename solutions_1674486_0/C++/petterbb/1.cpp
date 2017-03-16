#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

bool vis[1010];
int indgree[1010];
vector<int> a[1010];

int main(){
    freopen("1.out", "w", stdout);
    int t;
    cin >> t;
    for(int testCases = 1; testCases <= t; testCases++){
        int n;
        cin >> n;
        memset(indgree, 0, sizeof(indgree));
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= n; i++){
            a[i].clear();
        }

        int num;
        for(int i = 1; i <= n; i++){
            cin >> num;
            for(int j = 0; j < num; j++){
                int tmp;
                cin >> tmp;
                a[i].push_back(tmp);
                indgree[tmp]++;
            }
        }

        queue<int> q;
        
        printf("Case #%d: ", testCases); 
        bool flag = false;
        for(int i = 1; i <= n && !flag; i++){
            while(!q.empty())
                q.pop();
            memset(vis, false, sizeof(vis));
            if(indgree[i] == 0){
                q.push(i);
                vis[i] = true;
                while(!q.empty() && !flag){
                    int top = q.front();
                    q.pop();
                    for(int i = 0; i < a[top].size(); i++){
                        if(vis[a[top][i]] == true){
                            flag = true;
                            cout << "Yes" << endl;
                            break;
                        }
                        q.push(a[top][i]);
                        vis[a[top][i]] = true;
                    }
                }
            }
        }
       
        if(!flag)
            cout << "No" << endl;
    }

    return 0;
}
