#include <iostream>

using namespace std;

void processCase()
{
    int A, B, K;
    cin >> A >> B >> K;

    int combs = 0;
    for (int a = 0; a < A; ++a)
    {
        for (int b = 0; b < B; ++b)
        {
            int k = a & b;
            if (k < K)
                ++combs;
        }
    }
    cout << combs << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        cout << "Case #" << i << ": ";
        processCase();
    }
    return 0;
}