#include <bitset>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;


constexpr size_t N = 20;

int main()
{
    //ifstream cin("D:/input.txt");
    //ofstream cout("D:/output.txt");
    int T;
    cin >> T;

    for (int cases = 1; cases <= T; ++cases)
    {
        int N0;
        cin >> N0;
        vector<int> num;

        for (int i = 0; i < N; ++i)
        {
            int n;
            cin >> n;
            num.push_back(n);
        }

        vector<int> v1, v2;
        map<int, size_t> sum;

        for (size_t mask = 1; mask < (1 << N); ++mask)
        {
            int s = 0;
            bitset<N> b(mask);

            for (int i = 0; i < N; ++i)
                if (b[i])
                    s += num[i];

            auto iter = sum.find(s);

            if (iter == sum.end())
                sum[s] = mask;
            else
            {
                bitset<N> b1(iter->second);
                bitset<N> b2(mask);

                for (size_t i = 0; i < N; ++i)
                {
                    if (b1[i])
                        v1.push_back(num[i]);
                    else if (b2[i])
                        v2.push_back(num[i]);
                }

                break;
            }
        }

        if (v1.size())
        {
            cout << "Case #" << cases << ':' << endl << v1.front();

            for (size_t i = 1; i < v1.size(); ++i)
                cout << ' ' << v1[i] << flush;

            cout << endl << v2.front();

            for (size_t i = 1; i < v2.size(); ++i)
                cout << ' ' << v2[i] << flush;

            cout << endl;
        }
    }

    return 0;
}
