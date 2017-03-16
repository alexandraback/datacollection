#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>


void solve(int test)
{
    vector<int> s;
    int a;
    int n;

    cin >> a;
    s.push_back(a);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s.push_back(a);
    }

    n++;
    sort(s.begin() + 1, s.end());

    int ans = n - 1;
    int sum = s[0];
    int cur = 0;

    if (sum > 1)
    {
        for (int i = 1; i < n; ++i)
        {
            ans = min(ans, cur + n - i);
            while (sum <= s[i])
            {
                cur++;
                sum = 2 * sum - 1;
            }
            sum += s[i];
            ans = min(ans, cur + n - i - 1);
        }
    }

    cout << "Case #" << test << ": ";
    cout << ans << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    int T;
    cin >> T;
    for (int test = 1; test <= T; test++)
        solve(test);


    fclose(stdin);
    fclose(stdout);

    return 0;
}
