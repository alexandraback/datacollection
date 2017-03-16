#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int t = 1; t <= T; ++t)
    {
        int k, c, s;
        cin >> k >> c >> s;

        long long base = 1;
        for(int i = 0; i < c - 1; ++i)
            base *= k;

        cout << "Case #" << t << ": ";
        long long ans = 1;
        for(int i = 0; i < s; ++i)
        {
            cout << ans << " ";
            ans += base;
        }
        cout << endl;
    }
    return 0;
}