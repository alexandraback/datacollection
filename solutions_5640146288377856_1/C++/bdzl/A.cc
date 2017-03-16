#include <bits/stdc++.h>
using namespace std;

int GetAnswer(int c, int w)
{
    return (c / w) + w - 1 + (c % w != 0);
}

int main()
{
    // freopen("A-small-attempt0.in", "r", stdin);
    // freopen("A-small-attempt0.out", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int r, c, w;
        cin >> r >> c >> w;
        cout << "Case #" << test + 1 << ": ";
        cout << GetAnswer(c, w) * r << endl;
    }
    return 0;
}
