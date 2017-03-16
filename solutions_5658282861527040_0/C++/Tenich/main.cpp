#include <iostream>

using namespace std;

int main()
{
    int test_num;
    cin >> test_num;
    for (int test = 1; test <= test_num; ++test) {
        int a, b, k;
        cin >> a >> b >> k;
        long long res = 0;
        for (int i = 0; i < a; ++i)
            for (int j = 0; j < b; ++j)
                if ((i & j) < k)
                    ++res;
        cout << "Case #" << test << ": " << res << "\n";
    }
    return 0;
}
