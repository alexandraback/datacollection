#include <iostream>
#include <cstdio>

using namespace std;

int solve(int n, const string& d)
{
    int ans = 0;
    int ccnt = 0;
    for(int i=0; i<=n; i++)
    {
        int c = d[i]-'0';

        if (c)
        {
            if (ccnt < i)
            {
                ans += i-ccnt;
                ccnt = i;
            }
            ccnt += c;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for (int i=1; i<=t; i++)
    {
        int n; string d;
        cin >> n >> d;
        cout << "Case #" << i << ": " << solve(n, d) << "\n";
    }
}
