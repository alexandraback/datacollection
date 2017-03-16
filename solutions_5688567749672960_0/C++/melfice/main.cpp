#include <bits/stdc++.h>

using namespace std;

    const int maxn = 1e6 + 1;
    int dist[maxn];
    int q[maxn];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dist, 63, sizeof(dist));
    dist[1] = 1;
    int l = 0, r = 1;
    q[0] = 1;
    while(l < r)
    {
        int v = q[l++];
        if(v + 1 < maxn)
            if(dist[v] + 1 < dist[v + 1])
            {
                dist[v + 1] = dist[v] + 1;
                q[r++] = v + 1;
            }
        int rv = 0;
        int t = v;
        while(t)
        {
            rv = rv * 10 + t % 10;
            t /= 10;
        }
        if(rv < maxn)
            if(dist[v] + 1 < dist[rv])
            {
                dist[rv] = dist[v] + 1;
                q[r++] = rv;
            }
    }

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        int n;
        cin >> n;
        cout << dist[n] << endl;
    }
}
