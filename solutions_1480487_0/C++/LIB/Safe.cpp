#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;


double findMaxMin(vector<int> v)
{
    // assert v.size > 1
    sort(v.begin(), v.end());
    int  sum = accumulate(v.begin(), v.end(), 0);
    double total = sum * 2;
    for (int i = v.size() - 1; i >= 0; --i)
    {
        if (v[i] >= total / (i + 1))
        {
            total -= v[i];
        } else
            return total / (i + 1);
    }
    return 0;
}

int main()
{
    int N, T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        cout << "Case #" << i << ":";
        cin >> N;
        vector<int> scores;
        for (int j = 0; j < N; ++j)
        {
            int temp;
            cin >> temp;
            scores.push_back(temp);
        }
        // find max min score
        int sum = accumulate(scores.begin(), scores.end(), 0);
        double m = findMaxMin(scores);
        for (int j = 0; j < scores.size(); ++j)
        {
            cout << " ";
            if (scores[j] >= m) cout << "0.0";
            else cout << setprecision(8) << (m - scores[j]) * 100.0 / sum;
        }
        cout << endl;
    }
    return 0;
}
