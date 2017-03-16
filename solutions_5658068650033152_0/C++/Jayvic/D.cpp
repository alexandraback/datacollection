#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long ll;

int solve(void)
{
    int n, m, k;
    cin >> n >> m >> k;

    if (k <= 4 || n <= 2 || m <= 2)
    {
        return k;
    }

    int x = min(n, m);
    int y = max(n, m);
    int cnt = 5, last;
    int ans = 4;

    if (k <= cnt)
    {
        return ans;
    }

    for (int i = 4; i <= x; ++i)
    {
        last = cnt;
        if (i % 2 == 0)
        {
            cnt += (i - 1) / 2;
        }
        else
        {
            cnt += i / 2;
        }
        ans += 1;

        if (k <= cnt)
        {
            return min(ans, ans - 1 + k - last);
        }

        last = cnt;
        if (i % 2 == 0)
        {
            cnt += (i - 1) / 2 + 1;
        }
        else
        {
            cnt += i / 2 + 1;
        }
        ans += 1;

        if (k <= cnt)
        {
            return min(ans, ans - 1 + k - last);
        }
    }

    for (int i = (x % 2 == 0) ? x - 1 : x; i <= y; ++i)
    {
        last = cnt;
        cnt += x / 2;
        ans += 1;
        if (k <= cnt)
        {
            return min(ans, ans - 1 + k - last);
        }
        last = cnt;
        cnt += (x + 1) / 2;
        ans += 1;
        if (k <= cnt)
        {
            return min(ans, ans - 1 + k - last);
        }
    }

    int step = (x % 2 == 0) ? x - 2 : x - 1;
    step /= 2;
    int flag = 0;
    while (step != 0)
    {
        last = cnt;
        cnt += step;
        ans += 1;
        if (k <= cnt)
        {
            return min(ans, ans - 1 + k - last);
        }
        last = cnt;
        cnt += step;
        ans += 1;
        if (k <= cnt)
        {
            return min(ans, ans - 1 + k - last);
        }
        last = cnt;
        cnt += step;
        ans += 1;
        if (k <= cnt)
        {
            return min(ans, ans - 1 + k - last);
        }
        last = cnt;
        cnt += step;
        ans += 1;
        if (k <= cnt)
        {
            return min(ans, ans - 1 + k - last);
        }
        step -= 1;
    }
}

int main(void)
{
    int numTest;
    cin >> numTest;
    for (int testCase = 1; testCase <= numTest; ++testCase)
    {
        cout << "Case #" << testCase << ": ";
        cout << solve() << endl;
    }
    return 0;
}
