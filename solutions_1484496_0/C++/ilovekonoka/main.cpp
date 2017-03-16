#include <iostream>
#include <cmath>
#include <map>

int T;
int N;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

int num[600];

using namespace std;

int pow2[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152 };

int sum[2000000];

map<int , int> myMap;

int main()
{
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        for (int i = 0; i < 2000000; ++i)
            sum[i] = 0;
        myMap.clear();
        cin >> N;
        for (int n = 0; n < N; ++n)
        {
            cin >> num[n];            ;
        }
        bool found = false;
        cout << "Case #" << (t + 1) << ": " << endl;
        for (int i = 1; i < pow2[N]; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (CHECK_BIT(i, j))
                    sum[i] += num[j];
            }
            if (myMap.count(sum[i]) > 0)
            {
                int set1 = myMap[sum[i]];
                int set2 = i;
                // print
                // get out
                for (int j = 0; j < N; ++j)
                {
                    if (CHECK_BIT(set1, j))
                        cout << num[j] << " ";
                }
                cout << endl;
                for (int j = 0; j < N; ++j)
                {
                    if (CHECK_BIT(set2, j))
                        cout << num[j] << " ";
                }
                // get out
                found = true;
                break;
            }
            else
            {
                myMap[sum[i]] = i;
            }
        }
        if (!found)
            cout << "Impossible";
        cout << endl;
    }
}