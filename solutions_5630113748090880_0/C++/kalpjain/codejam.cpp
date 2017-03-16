#include <bits/stdc++.h>
using namespace std;

int main(void) {
    freopen("in.txt", "rt", stdin);
    freopen("test.txt", "wt", stdout);
    int t, n;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc)
    {
        cin >> n;
        int i, j, m[3000] = {0}, a;
        vector <int> v;
        for(i = 0; i < 2 * n - 1; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                cin >> a;
                m[a]++;
            }
        }
        cout << "Case #" << tc << ": ";
        for(i = 1; i <= 2500; ++i)
        {
            if(m[i] % 2)
                v.push_back(i);
        }
        for(i = 0; i < n; ++i)
            cout << v[i] << " ";
        cout << "\n";
    }
    return 0;
}
