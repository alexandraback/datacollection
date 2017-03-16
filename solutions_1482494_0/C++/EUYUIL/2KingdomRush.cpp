#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1111;

int T, n, a[N], b[N], star, rem2;
bool da[N], db[N];

inline bool attempt1()
{
    for (int i = 0; i < n; ++i) {
        if (!da[i] && star >= a[i]) {
            da[i] = true;
            ++star;
            return true;
        }
    }
    return false;
}

inline bool attempt2()
{
    for (int i = 0; i < n; ++i) {
        if (!db[i] && star >= b[i]) {
            db[i] = true;
            ++star; --rem2;
            if (!da[i]) {
                ++star;
                da[i] = true;
            }
            return true;
        }
    }
    return false;
}

inline void init() {
    memset(da, 0, sizeof da);
    memset(db, 0, sizeof db);
    star = 0; rem2 = n;
}

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);

    cin >> T;
    for (int cs = 1; cs <= T; ++cs)
    {
        cin >> n; init();
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];
        int cnt = 0;
        while (true)
        {
            while (attempt2())
                ++cnt;
            if (rem2 == 0)
                break;
            if (!attempt1()) { // 2 is not done but 1 is.
                cnt = -1;
                break;
            }
            ++cnt;
        }
        if (cnt == -1)
            cout << "Case #" << cs << ": " << "Too Bad" << endl;
        else
            cout << "Case #" << cs << ": " << cnt << endl;
    }
    return 0;
}
