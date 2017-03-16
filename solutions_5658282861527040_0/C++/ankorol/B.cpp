#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int A, B, K;
        cin >> A >> B >> K;
        int ans = 0;
        for (int i = 0; i < A; ++i)
            for (int j = 0; j < B; ++j)
            {
                if ((i & j) < K)
                    ans++;
            }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}