#include <iostream>

using namespace std;

int main()
{
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        int a, b, k;
        cin >> a >> b >> k;
        int ans = 0;
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                if ((i & j) < k)
                    ans++;
        cout << "Case #" << tc << ": ";
        cout << ans << endl;
    }
}
