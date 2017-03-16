#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

int solve()
{
    string s;
    cin >> s;
    int N = s.length();
    vector<int> dp0(N+1);
    vector<int> dp1(N+1);

    for (int l = 1; l <= N; ++l)
    {
        if (s[l-1] == '-')
        {
            dp0[l] = dp0[l-1];
            dp1[l] = dp0[l-1] + 1;
        }
        else
        {
            dp0[l] = dp1[l-1] + 1;
            dp1[l] = dp1[l-1];
        }
    }

    return dp1[N];
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        cout << "Case #" << csIx << ": " << solve() << endl;
    }
    
    return 0;
}
