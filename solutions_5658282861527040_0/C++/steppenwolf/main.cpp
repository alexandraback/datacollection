#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test)
    {
        long long A, B, K;
        cin >> A >> B >> K;
        A--, B--, K--;

        int res = 0;
        for (int i = 0; i <= A; ++i)
        {
            for (int j = 0; j <= B; ++j)
            {
                if ((i & j) <= K) ++res;
            }
        }

        cout << "Case #" << test << ": " << res << endl;
    }

    return 0;
}
