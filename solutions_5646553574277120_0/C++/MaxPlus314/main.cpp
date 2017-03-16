#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int v, c, d, am, pos[300], t, a[300];

void add(int x)
{
    for (int j = v; j >= x; --j)
        pos[j] |= pos[j - x];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> c >> d >> v;
        for (int i = 0; i < d; ++i)
            cin >> a[i];
        am = 0;
        memset(pos, 0, sizeof(pos));
        pos[0] = 1;
        for (int i = 0; i < d; ++i)
            for (int j = v; j >= a[i]; --j)
                pos[j] |= pos[j - a[i]];
        for (int j = 0; j <= v; ++j)
            if (!pos[j])
                add(j), am++;
        cout << "Case #" << i + 1 << ": " << am << '\n';
    }
    return 0;
}
