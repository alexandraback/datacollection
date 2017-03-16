#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector< pair< int, int > >& levels)
{
    int stars = 0;
    for (int result = 0; ;++result)
    {
        // find lv2 only
        bool found = false;
        for (size_t i = 0; i < levels.size(); ++i)
        {
            if (0 <= levels[i].second &&
                levels[i].second <= stars &&
                0 <= levels[i].first)
            {
                levels[i].first = -1;
                levels[i].second = -1;
                stars += 2;
                found = true;
                break;
            }
        }
        if (found) continue;
        // find lv2'
        for (size_t i = 0; i < levels.size(); ++i)
        {
            if (0 <= levels[i].second &&
                levels[i].second <= stars)
            {
                levels[i].first = -1;
                levels[i].second = -1;
                stars += 1;
                found = true;
                break;
            }
        }
        if (found) continue;
        // find lv1
        int candidate = n;
        for (size_t i = 0; i < levels.size(); ++i)
        {
            if (0 <= levels[i].first &&
                levels[i].first <= stars)
            {
                if (candidate == n)
                {
                    candidate = i;
                    found = true;
                }
                else
                {
                    if (levels[candidate].second < levels[i].second)
                    {
                        candidate = i;
                        found = true;
                    }
                }
            }
        }
        if (found)
        {
            levels[candidate].first = -1;
            stars += 1;
            continue;
        }
        // finish?
        bool finish = true;
        for (size_t i = 0; i < levels.size(); ++i)
        {
            if (0 <= levels[i].second)
            {
                finish = false;
                break;
            }
        }
        if (finish) return result;
        // Too Bad
        return -1;
    }
}

int solveCase()
{
    int n = 0;
    cin >> n;
    vector< pair< int, int > > levels(n);
    for (int i = 0; i < n; ++i)
    {
        pair< int, int > p;
        cin >> p.first >> p.second;
        levels[i] = p;
    }
    return solve(n, levels);
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int ans = solveCase();
        cout << "Case #" << (i+1) << ": ";
        if (ans < 0) cout << "Too Bad" << endl;
        else cout << ans << endl;
    }
    return 0;
}
