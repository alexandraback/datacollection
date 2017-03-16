#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>

using namespace std;

const int maxn = 10;

int n, m;
string z[maxn];
int a[maxn][maxn];

int main()
{
    int T;
    cin >> T;
    for (int sc = 0; sc < T; sc++) {
        int i, j;
        cin >> n >> m;
        int best = 0;
        for (i = 0; i < n; i++) {
            cin >> z[i];
            if (z[i] < z[best]) best = i;
        }
        memset(a, 0, sizeof(a));
        for (i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            a[u][v] = a[v][u] = 1;
        }

        string ans = "zzz";
        vector<int> p;
        for (i = 0; i < n; i++)
            p.push_back(i);
        do {
            vector<int> s;
            s.push_back(p[0]);
            int ok = 1;
            for (i = 1; i < n; i++) {
                while (s.size() && !a[s[s.size()-1]][p[i]])
                    s.pop_back();
                if (!s.size())
                    ok = 0;
                s.push_back(p[i]);
            }
            if (ok) {
                string cur;
                for (i = 0; i < n; i++)
                    cur += z[p[i]];
                if (cur < ans) ans = cur;
            }
        } while (next_permutation(p.begin(), p.end()));

        cout << "Case #" << sc+1 << ": ";
        cout << ans;
        cout << endl;
    }
    
    return 0;
}
