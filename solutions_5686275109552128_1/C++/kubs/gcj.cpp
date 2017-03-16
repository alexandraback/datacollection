#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int k, int p[], int d)
{
    int not_special = k;
    if (p[0] <= not_special)
        return true;
    int time_needed;
    while(not_special > 0)
    {
        time_needed = 0;
        for(int i = 0; i < d; i++)
        {
            if (p[i] <= not_special)
                break;
            time_needed += p[i] / not_special;
            if (p[i] % not_special == 0)
                time_needed -= 1;
        }
        if (not_special == k - time_needed)
            return true;
        not_special = k - time_needed;
    }
    return false;
}

int solve()
{
    int d;
    cin >> d;
    int p[d];
    for (int i = 0; i < d; i++)
    {
        cin >> p[i];
        p[i] *= -1;
    }
    sort(p, p + d);
    for (int i = 0; i < d; i++)
    {
        p[i] *= -1;
    }
    int l = 0;
    int u = p[0];
    int k;
    while(u - l > 1)
    {
        k = (l + u) / 2;
        if (check(k, p, d))
        {
            u = k;
        }
        else
        {
            l = k;
        }
    }
    return u;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int s = solve();
        cout << "Case #" << i << ": " << s << endl;
    }
    return 0;
}
