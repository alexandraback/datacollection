#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt)
    {
        cerr << "Executing Case #" << tt << "\n";
        cout << "Case #" << tt << ": ";

        int n, m; cin >> n >> m;
        string a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        bool g[n][n];
        memset(g, 0, sizeof(g));
        for(int i = 0; i < m; ++i)
        {
            int x, y; cin >> x >> y;
            --x, --y;
            g[x][y] = g[y][x] = true;
        }

        int p[n];
        for(int i = 0; i < n; ++i) p[i] = i;

        string ret = "";
        do
        {
            stack<int> cu;
            cu.push(0);
            for(int i = 1; i < n; ++i)
            {
                while(!cu.empty() and !g[p[i]][p[cu.top()]]) cu.pop();
                if(cu.empty()) break;
                cu.push(i);
            }
            if(cu.empty()) continue;

            string cur = "";
            for(int i = 0; i < n; ++i) cur += a[p[i]];

            if(ret == "") ret = cur;
            else ret = min(ret, cur);
        } while(next_permutation(p, p + n));

        cout << ret << "\n";
    }
    return 0;
}