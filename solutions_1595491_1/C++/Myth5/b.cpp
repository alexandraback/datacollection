#include <iostream>
using namespace std;

int t[200], f[50][2], n, s, p;

int main()
{
    freopen("b2.in", "r", stdin);
    freopen("b2.out", "w", stdout);
    
    int t1, t2;
    cin >> t1;
    for (int x = 0; x <= 10; ++x)
        for (int y = x; y <= 10; ++y)
            for (int z = y; z <= 10; ++z) {
                if (z - x == 2)
                    f[x + y + z][1] >?= z;
                if (z - x <= 1)
                    f[x + y + z][0] >?= z;
            }
                

                
    for (t2 = 1; t2 <= t1; ++t2) {
        cout << "Case #" << t2 << ": ";
        cin >> n >> s >> p;
        for (int i = 1; i <= n; ++i)
            cin >> t[i];
        sort(t + 1, t + n + 1);
        int ret = 0;
        for (int i = n; i; --i)
            if (f[t[i]][0] >= p)
                ++ret;
            else
            if (s > 0 && f[t[i]][1] >= p) {
                ++ret;
                --s;
            }
        cout << ret << endl;
    }
    
    return 0;
}
