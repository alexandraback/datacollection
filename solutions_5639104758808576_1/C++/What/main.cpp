#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

int solve(string s)
{
    int res = 0;
    int total = 0;
    for (int i = 0; i < static_cast<int>(s.size()); ++i)
    {
        res = max(res, i - total);
        total += s[i] - '0';
    }
    return res;
}

int main()
{
    int caseCount = 0;
    cin >> caseCount;

    for (int i = 0; i < caseCount; ++i)
    {
        int maxShyness = 0;
        cin >> maxShyness;
        string counts;
        cin >> counts;
        // cerr << "Test " << i << " " << maxShyness << " " << counts << endl;
        assert(counts.size() == static_cast<size_t>(maxShyness + 1));
        int res = solve(counts);
        cout << "Case #" << i + 1 << ": " << res << endl;
    }
    return 0;
}

