#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main()
{
    //ifstream cin("D:/input.txt");
    //ofstream cout("D:/output.txt");
    int T;
    cin >> T;

    for (int cases = 1; cases <= T; ++cases)
    {
        int N;
        vector<int> s;
        int sum = 0;
        cin >> N;

        for (int i = 0; i < N; ++i)
        {
            int t;
            cin >> t;
            s.push_back(t);
            sum += t;
        }

        vector<int> index;
        vector<int> inv_index(N);

        for (int i = 0; i < N; ++i)
            index.push_back(i);

        for (int i = 0; i < N - 1; ++i)
        {
            for (int j = N - 2; j >= i; --j)
            {
                if (s[j] < s[j + 1])
                {
                    int temp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = temp;
                    temp = index[j];
                    index[j] = index[j + 1];
                    index[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < N; ++i)
            inv_index[index[i]] = i;

        vector<double> min;

        for (int i = 0; i < N; ++i)
        {
            int partial = sum;

            for (int j = i; j < N; ++j)
                partial += s[j];

            if (s[i] * (N - i) >= partial)
                min.push_back(0);
            else
            {
                for (int j = i; j < N; ++j)
                    min.push_back((static_cast<double>(partial) / (N - i) - s[j]) / sum);

                break;
            }
        }

        cout << "Case #" << cases << ':' << flush;

        for (int i = 0; i < N; ++i)
            cout << ' ' << setiosflags(ios::fixed) << setprecision(6)
                 << 100 * min[inv_index[i]] << flush;

        cout << endl;
    }

    return 0;
}
