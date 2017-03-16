#include <iostream>
using namespace std;
bool f[10000]; int  a[1000];
int T, c, d, v;
int main()
{
    cin >> T;
    for (int I = 1; I <= T; ++I)
    {
        cin >> c >> d >>v;
        for (int i = 0; i < d; ++i)
            cin >> a[i];
        memset(f, 0, sizeof(f));
        f[0] = true;
        for (int k = 1; k <= c; ++k)
            for (int j = 0; j < d; ++j)
                for (int i = v; i >= a[j]; --i)
                    f[i] = f[i] | f[i-a[j]];
        int ans = 0;
        for (int i = 0; i <= v; ++i)
            if (!f[i])
            {
                ans++;
                for (int k = 1; k <= c; ++k)
                    for (int j = v; j >= i; --j)
                        f[j] = f[j] | f[j-i];
            }
        printf("Case #%d: %d\n", I, ans);

    }
}

