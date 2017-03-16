#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin>>T;

    for (int i = 0; i < T; ++i)
    {
        int N;
        cin>>N;

        vector<int> s(N);
        int sum = 0;
        for (int j = 0; j < N; ++j)
        {
            cin>>s[j];
            sum += s[j];
        }

        int m = 0;
        int sum2 = 0;
        for (int j = 0; j < N; ++j)
        {
            if (2 * sum > N * s[j])
            {
                ++m;
                sum2 += s[j];
            }
        }

        vector<double> ans(N);
        for (int j = 0; j < N; ++j)
        {
            if (sum + sum2 > m * s[j])
            {
                ans[j] = (double)(sum + sum2 - s[j] * m) * 100 / (m * sum);
            }
            else
            {
                ans[j] = 0;
            }
        }

        printf("Case #%d:", i + 1);
        for (int j = 0; j < N; ++j)
        {
            printf(" %.6lf", ans[j]);
        }
        printf("\n");
    }

    return 0;
}
