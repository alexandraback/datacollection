#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

#define mod 1000000007

using namespace std;

int arr[30][30], same[30], visited[30], b[30];

long long fact[108];

long long dfs(int u);

int main()
{
    int t, i, j, k, l, n, m, flag;
    int cases = 1;
//    freopen("inp.in","r",stdin);
//    freopen("out.txt","w",stdout);

    scanf("%d", &t);
    
    fact[0] = 1LL;
    
    for (i = 1; i <= 100; i++) {
        fact[i] = (fact[i-1]*1LL*i)%mod;
    }
    
    while(t--) {
        scanf("%d", &n);
        
        flag = 1;
        string s[105];
        
        memset(arr, 0, sizeof(arr));
        memset(same, 0, sizeof(same));
        memset(b, 0, sizeof(b));
        memset(visited, 0, sizeof(visited));
        
        for (i = 0; i < n; i++) {
            cin >> s[i];
            int u = s[i][0]-'a';
            int chk = 0;
            for (j = 1; j < s[i].length(); j++) {
                int v = s[i][j]-'a';
                if (v != u) {
                   chk = 1;
                
                   arr[u][v]++;
                   b[v]++;
                
                   if (arr[u][v] > 1) {
                      flag = 0;
                   }
                   u = v;
                }
            }
            if (!chk) {
               same[u]++;
            }
        }

        for (i = 0; i < 26; i++) {
            int cnt = 0;
            for (j = 0; j < 26; j++) {
                if (i != j) {
                   if (arr[i][j]) {
                      cnt++;
                   }
                }
            }
            if (cnt > 1) {
                flag = 0;
            }
        }
        
        cout<<"Case #"<<cases++<<": ";
        
        if (!flag) {
            cout << "0" << endl;
        } else {
            long long ans = 1LL;
            int cnt = 0;
            
            for (i = 0; i < 26; i++) {
                if (!visited[i] && !b[i]) {
                   int chk = 0;
                  
                   if (same[i]) {
                      chk = 1;
                   }
                   
                   for (j = 0; j < 26; j++) {
                       if (arr[i][j] || arr[j][i]) {
                          chk = 1;
                       }
                   }
                
                   if (chk != 0) {
                      long long z = dfs(i);
                      ans = (ans*1LL*z)%mod;
                      cnt++;
                   }
                }
            }
            ans = (ans*1LL*fact[cnt])%mod;
            
            cout << ans << endl;
        }
    }
    return 0;
}

long long dfs(int node)
{
    int j;
    
    visited[node] = 1;

    long long ret = fact[same[node]];
    
    for (j = 0; j < 27; j++) {
        if (arr[node][j] && !visited[node]) {
            ret = (ret*1LL*dfs(j))%mod;
        }
    }
    return ret;
}
