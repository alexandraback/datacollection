#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int test()
{
    int64_t k, c, s;
    cin >> k >> c >> s;

    if (s < k)
        return -1;
    else
        return k;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int result = test();
        cout << "Case #" << i + 1 << ":";
        if (result == -1)
            cout << " IMPOSSIBLE\n";
        else
        {
            for (int i = 1; i <= result; i++)
                cout << " " << i;
            cout << endl;
        }
    }
}
