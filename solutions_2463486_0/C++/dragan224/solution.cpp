#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#define msg(var) cout << #var << " = " << var << endl
using namespace std;

bool isPal(int n)
{
    string str = "";
    while (n > 0)
    {
        str.push_back(n % 10 + '0');
        n /= 10;
    }
    for (int i = 0; i < str.size(); i++)
        if (str[i] != str[str.size() - i - 1])
            return false;

    return true;
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("ss.in", "r", stdin);
    freopen("ss.out", "w", stdout);

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        int ans = 0;
        int a, b;
        cin >> a >> b;
        for (int i = 1; i < 1000; i++)
        {
            int ii = i * i;
            if (ii >= a && ii <= b && isPal(ii) && isPal(i))
                ans++;
        }

        cout << "Case #" << T << ": " << ans << "\n";
    }

    return 0;
}
