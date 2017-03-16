#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int T, n;
int a[1005], b[1005], flag[1005];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> n;
        vector<pair<int, int> > v;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
            v.push_back(make_pair(a[i], i * 2));
            v.push_back(make_pair(b[i], i * 2 + 1));
        }
        sort(v.begin(), v.end());
        int cur = 0;
        for(int i = 0; i < v.size(); i++)
            if (cur >= v[i].first) cur++;
            else
            {
                cur = -1; break;
            }
        if (cur == -1) printf("Case #%d: Too Bad\n", t);
        else
        {
            memset(flag, 0, sizeof(flag));
            int ans = 2 * n;
            for(int j = n - 1; j >= 0; j--)
            {
                cur = 0;
                for(int i = 0; i < v.size(); i++)
                {
                    if (v[i].second % 2 == 0 && (flag[v[i].second / 2] || j == v[i].second / 2)) continue;
                    if (cur >= v[i].first)
                    {
                        if (v[i].second % 2 == 1 && (flag[v[i].second / 2] || j == v[i].second / 2)) cur += 2;
                        else cur++;
                    }
                    else
                    {
                        cur = -1; break;
                    }
                }
                if (cur != -1)
                {
                    flag[j] = 1;
                    ans--;
                }
            }
            printf("Case #%d: %d\n", t, ans);
        }
    }
    return 0;
}
