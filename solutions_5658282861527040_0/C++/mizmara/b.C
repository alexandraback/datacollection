#include <iostream>

using namespace std;

typedef unsigned long long int ull;

int main()
{
    int numTests;
    ull a, b, k;
    cin >> numTests;

    for(int t = 0; t < numTests; ++t)
    {
        cin >> a >> b >> k;
        ull count = 0;
        for(ull i = 0; i < a; ++i)
        {
            for(ull j = 0; j < b; ++j)
            {
                for(ull h = 0; h < k; ++h)
                {
                    if((i & j) == h)
                        ++count;
                }
            }
        }
        cout << "Case #" << t+1 << ": " << count << endl;
    }
    return 0;
}
