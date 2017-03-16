#include <iostream>

using namespace std;

int a[1 << 20];

int main()
{
    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++)
    {
        int n;
        cin >> n;
        cout << "Case #" << tt << ": ";

        if (!n)
        {
            cout << "INSOMNIA" << endl;
            continue;
        }

        bool d[10] = {};
        int k = 0;
        long long z;

        for (z = 0; k < 10; )
        {
            z += n;

            for (long long x = z; x; x /= 10)
            {
                k += !d[x % 10];
                d[x % 10] = true;
            }
        }

        cout << z << endl;
    }

    return 0;
}
