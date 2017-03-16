#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int f[(1 << 20) + 10];
bool z[(1 << 20) + 10];

int get(int a) {
    int b = 0;
    while (a > 0) {
        a = a >> 1;
        ++b;      
    }
    return b;
}


int main() {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    int tt;
    cin >> tt;
    for (int ttt = 1; ttt <= tt; ++ttt) {
        cout << "Case #" << ttt << ":";
        memset(z, 0, sizeof(z));
        int k, n, maxkey = 0;
        cin >> k >> n;
        
        int x[100], y[100];
        vector<int> p[100];
        
        for (int i = 0; i < k; ++i) {
            cin >> x[i];
            --x[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> y[i];
            --y[i];
            if (y[i] > maxkey) maxkey = y[i];
            int a, b;
            cin >> a;
            for (int j = 0; j < a; ++j) {
                cin >> b;
                --b;
                p[i].push_back(b);    
                if (b > maxkey) maxkey = b;
            }
        }
        
        queue<int> que;
        que.push(0); 
        z[0] = true;
        
        int key[100];

        while (!que.empty()) {
            int a = que.front();
            que.pop();
            for (int i = 0; i < n; ++i)
             if ((a & (1 << i)) == 0) {
                 for (int j = 0; j <= maxkey; ++j) key[j] = 0;
                 for (int j = 0; j < k; ++j) ++key[x[j]];
                 for (int j = 0; j < n; ++j)
                  if ((a & (1 << j)) != 0) {
                      for (int l = 0; l < p[j].size(); ++l) ++key[p[j][l]];  
                      --key[y[j]];    
                  }
                 if (key[y[i]] > 0 && !z[a | (1 << i)]) {
                     que.push(a | (1 << i)); 
                     z[a | (1 << i)] = true;
                     f[a | (1 << i)] = a;             
                 }
             }
        }
        
        int a = (1 << n) - 1;
        vector<int> ans;
        if (z[a]) {
            while (a > 0) {
                ans.push_back(get(a-f[a]));
                a = f[a];      
            }
            for (int i = ans.size() - 1; i >= 0; --i) cout << " " << ans[i];
            cout << endl;
        } else {
            cout << " IMPOSSIBLE" << endl;       
        }
    }
    return 0;    
}
