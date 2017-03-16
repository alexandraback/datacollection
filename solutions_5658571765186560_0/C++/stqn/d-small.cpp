#include <bits/stdc++.h>
using namespace std;

int n, w, h;

void input()
{
    cin >> n >> w >> h;
    if (w > h) swap(w, h);
}

bool solve()
{
    return w >= n - 1 and w * h % n == 0;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        input();
        cout << "Case #" << i << ": "
             << (solve() ? "GABRIEL" : "RICHARD")
             << endl;
    }
}
