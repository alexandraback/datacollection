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
    if (w * h % n != 0) return false;
    if (n <= 4) return w >= n - 1;
    if (n == 5) return w >= 3 and w * h > 15;
    if (n == 6) return w >= 4;
    return false;
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
