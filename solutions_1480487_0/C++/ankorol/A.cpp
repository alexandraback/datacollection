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
        vector<pair<int, int> > s;
        s.resize(N);
        double sum = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> s[i].first;
            s[i].second = i;
            sum += s[i].first;
        }
        double sum2 = sum;
        sum *= 2;
        sort(s.rbegin(), s.rend());
        double kol = N;
        cout << "Case #" << t << ":";
        double ans[201] = {0};
        for (int i = 0; i < N; ++i)
        {
            if (sum / kol < s[i].first) 
            {
                ans[s[i].second] = 0.0;
                sum -= s[i].first;
            }
            else 
            {
                ans[s[i].second] = (sum / kol - s[i].first) / (sum2);
                sum -= sum / kol;
            }
            kol--;            
        }
        for (int i = 0; i < N; ++i)
        {
            printf(" %.9lf", ans[i]*100);
        }
        cout << endl;
    }
    return 0;
}