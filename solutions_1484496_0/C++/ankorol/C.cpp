#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;
        int z[21] = {0};
        int sum = 0;
        for (int i = 0; i < N; ++i) 
        {
            cin >> z[i];
        }
        bool find = false;
        long long p = pow(3.0, 20.0);
        cout << "Case #" << t << ":" << endl;
        for (long long i = 0; i < p; ++i)
        {
            int sum1 = 0;
            int sum2 = 0;
            long long j = i;
            int k = 0;
            int f1[20] = {0};
            int k1 = 0;
            int f2[20] = {0};
            int k2 = 0;
            while (j > 0)
            {
                if (j % 3 == 1) 
                {
                    sum1 += z[k];
                    f1[k1++] = z[k];
                }
                if (j % 3 == 2) 
                {
                    sum2 += z[k];
                    f2[k2++] = z[k];
                }
                ++k;
                j /= 3;
            }            
            if ((sum1 == sum2) && (k1 != 0) && (k2 != 0))
            {
                find = true;
                for (int r = 0; r < k1 - 1; ++r) cout << f1[r] << " ";
                cout << f1[k1 - 1] << endl;
                for (int r = 0; r < k2 - 1; ++r) cout << f2[r] << " ";
                cout << f2[k2 - 1] << endl;
                break;
            }
        }
        if (!find)
        {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}