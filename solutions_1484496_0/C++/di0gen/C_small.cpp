#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <memory.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

//long long!

const int max_n = 501, max_s = 100001 * 21;
int a[max_n + 1];
int dp[max_s + 1];

int main()
{
    ifstream cin ("C-small-attempt0.in");
    ofstream cout("C-small-attempt0.out");
    int t;
    cin >> t;
    for (int count = 1; count <= t; count++)
    {
        cout << "Case #" << count << ":\n";
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        bool ok = false;
        for (int m = 1; m < (1 << n); m++)
        {
            int s = 0;
            for (int i = 0; i < n; i++)
                if (m & (1 << i))
                   s += a[i];
            if (dp[s] != 0)
            {
               ok = true;
               vector <int> v[2];
               for (int i = 0; i < n; i++)
               {
                   if (dp[s] & (1 << i))
                      v[0].pb(a[i]);
                   if (m & (1 << i))
                      v[1].pb(a[i]);
               }
               for (int k = 0; k < 2; k++) {
                   for (int i = 0; i < v[k].size(); i++) {
                       bool go = true;
                       for (int j = 0; j < v[1 - k].size(); j++)
                           if (v[k][i] == v[1 - k][j])
                              go = false;
                       if (go)
                          cout << v[k][i] << ' ';
                   }
                   cout << endl;
               }
               break;
            }
            else
                dp[s] = m;
        }
        if (!ok)
           cout << "Impossible" << endl;
    }
    return 0;
}
