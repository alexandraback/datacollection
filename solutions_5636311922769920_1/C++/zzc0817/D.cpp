#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca)
    {
        int K, C, S;
        cin >> K >> C >> S;
        // Theory:
        // sufficient to consider original strings with single G (K of them)
        // (numbered from 0) to check i-th string,
        // one need a index with a number i in K-ary number system
        int least = (K + C - 1) / C; // ceiling of K / C
        cout << "Case #" << ca << ":";
        if(S < least)
            cout << " IMPOSSIBLE\n";
        else
        {
            int digits[C] = {0};
            for(int i = 0; i < least; ++i)
            {
                int base = i * C;
                for(int j = 0; j < C; ++j)
                {
                    digits[j] = base + j < K ? base + j : 0;
                    //cout << digits[j] << " ";
                }
                //cout << "\n";
                long long index = 0;
                for(int j = 0; j < C; ++j)
                {
                    index *= K;
                    index += digits[j];
                }
                ++index;
                cout << " " << index;
            }
            cout << "\n";
        }
    }
    cout << flush;
    return 0;
}


