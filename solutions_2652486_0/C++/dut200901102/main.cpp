#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int R, n, m, k;
int s[10];

void solve()
{
    cin >> R >> n >> m >> k;
    while(R--)
    {
        for(int i = 0; i < k; ++i) cin >> s[i];
        sort(s, s + k);
        if(n == 1)
        {
            if(s[k - 1] != 1)cout << s[k - 1] << endl;
            else cout << 2 << endl;
        }
        else if(n == 2)
        {
            for(int j = 2; j <= m; ++j)
                for(int jj = 2; jj <= m; ++jj)
                {
                    bool flag = false;
                    for(int jjj = 0; jjj < k; ++jjj)
                    {
                        if(s[jjj] == 1) continue;
                        if(s[jjj] != j && s[jjj] != jj && s[jjj] != j * jj)
                            flag = true;
                    }
                    if(!flag)
                    {
                        cout << j << jj << endl;
                        j = m + 1;
                        jj = m + 1;
                    }
                }
        }
        else
        {
            for(int j = 2; j <= m; ++j)
                for(int jj = 2; jj <= m; ++jj)
                    for(int jjj = 2; jjj <= m; ++jjj)
                    {
                        bool flag = false;
                        for(int jjjj = 0; jjjj < k; ++jjjj){
                            if(s[jjjj] == 1) continue;
                            if(s[jjjj] != j && s[jjjj] != jj && s[jjjj] != jjj &&
                               s[jjjj] != j * jj && s[jjjj] != j * jjj && s[jjjj] != jjj * jj &&
                               s[jjjj] != j * jj * jjj) flag = true;
                        }
                        if(!flag){
                            cout << j << jj << jjj << endl;
                            j = m + 1;
                            jj = m + 1;
                            jjj = m + 1;
                        }
                    }
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, cas = 1;
    for(cin >> t; t--; )
    {
        printf("Case #%d:\n", cas++);
        solve();
    }
    return 0;
}
