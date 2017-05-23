#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#define msg(var) cout << #var << " = " << var << endl
using namespace std;

const int maxN = 224;

int n, m, t;
int col[maxN], row[maxN];
priority_queue<pair<int, pair<int, int> > > heap;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("ss.in", "r", stdin);
    freopen("ss.out", "w", stdout);

    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        memset(col, -1, sizeof(col));
        memset(row, -1, sizeof(row));
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                heap.push(make_pair(x, make_pair(i, j)));
            }

        bool error = false;
        while (!heap.empty())
        {
            pair<int, pair<int, int> > curr = heap.top();
            heap.pop();
            int x = curr.second.first, y = curr.second.second;
            int val = curr.first;

            if (row[x] > val && col[y] > val)
            {
                error = true;
                break;
            }
            row[x] = max(row[x], val); col[y] = max(col[y], val);
        }
        while (!heap.empty())
            heap.pop();

        if (!error)
            printf("Case #%d: YES\n", T);
        else
            printf("Case #%d: NO\n", T);
    }

    return 0;
}
