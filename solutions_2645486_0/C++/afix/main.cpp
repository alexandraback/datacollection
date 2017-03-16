//GCJ 2013 1A_B
//#include <iostream>
#include <fstream>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int v[100];

int sum(int x, int m) {
    int ans = 0;
    int *p = v;
    while (x) {
        ans += (x % m) * (*p);
        ++p;
        x /= m;
    }
    return ans;
}

int isgood(int i, int e, int r, int n) {
    int ce = e;
    int m = e + 1;
    for (int j = 0; j < n; ++j) {
        ce -= (i % m);
        if (ce < 0) return 0;
        ce = min(ce+r, e);
        i /= m;
    }
    return 1;
}

void solve()
{
    int e, r, n, ep1pown = 1;
    cin >> e >> r >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        ep1pown *= e+1;
    }
    int ans = 0;
    for (int i = 0; i < ep1pown; ++i) {
        if (isgood(i, e, r, n)) {
            ans = max(ans, sum(i, e+1));
            //cout << ans << ' ' << i << endl;
        }
    }
    cout << ans << endl;
}

void init()
{

}

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        init();
        solve();
    }

    return 0;
}
