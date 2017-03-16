#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
int n, num[1000];
vector<int> P, Q;

bool finished;
void solve(int x, int v1, int v2)
{
    if (v1 == v2 && v1 != 0) {
        finished = true;
        return;
    }
    if (x == n)
        return;

    {
        P.push_back(num[x]);
        solve(x + 1, v1 + num[x], v2);
        if (finished)
            return;
        P.pop_back();
    }
    {
        Q.push_back(num[x]);
        solve(x + 1, v1, v2 + num[x]);
        if (finished)
            return;
        Q.pop_back();
    }
    solve(x + 1, v1, v2);
}

int main(void)
{
    freopen("probC.in", "r", stdin);
    int __;
    cin >> __;
    for (int _ = 1; _ <= __; ++_) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> num[i];

        printf("Case #%d:\n", _);

        finished = false;
        P.clear();
        Q.clear();
        solve(0, 0, 0);

        if (finished) {
            for (int i = 0; i < (int)P.size(); ++i) {
                if (i)
                    cout << " ";
                cout << P[i];
            }
            puts("");
            for (int i = 0; i < (int)Q.size(); ++i) {
                if (i)
                    cout << " ";
                cout << Q[i];
            }
            puts("");
        } else {
            puts("Impossible");
        }
    }
}
