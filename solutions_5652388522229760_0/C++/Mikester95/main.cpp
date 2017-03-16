#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

void desc(int x, vector<int> &vis) {
    while(x) {
        vis[x%10]++;
        x /= 10;
    }
}

void solve(int n) {
    if (n == 0) {
        cout << "INSOMNIA";
        return;
    }
    int cnt = 0;
    int x = n;
    vector<int> vis(10);

    while (1) {
        desc(x, vis);

        bool ok = true;

        for (int i = 0; i < 10; ++i) {
            if (!vis[i])
                ok = false;
        }

        if (ok)
            break;
        x += n;
    }

    cout << x;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int test;
    cin >> test;
    for (int k = 1; k <= test; ++k) {
        int n;
        cin >> n;
        cout << "Case #" << k << ": ";
        solve(n);
        cout << "\n";
    }
}
