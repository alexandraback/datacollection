#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define lol long long
using namespace std;

ifstream in("C-small-1-attempt6.in");
ofstream out("azaza.txt");


#define cin in
#define cout out


int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        int ans = 0;
        if (n == 1)
        {
            int d, h, m;
            cin >> d >> h >> m;
            ans = 0;
        }
        else
        {
            int d1, h1, m1; //faster
            int d2, h2, m2;
            cin >> d1 >> h1 >> m1 >> d2 >> h2 >> m2;
            if (m1 == m2)
            {
                ans = 0;
            }
            else
            {
                if (m1 > m2)
                {
                    swap(m1, m2);
                    swap(d1, d2);
                    swap(h1, h2);
                }

                int azaza = 0;
                if (d2 < d1)
                {
                    d2 += 360;
                    azaza = 360;
                }
               
                double v1 = 360. / m1;
                double v2 = 360. / m2;
                double vs = v1 - v2;
                double tm = (d2 - d1) / vs;
                double pm = d1 + tm * v1; 
                if (pm > azaza + 360 + 0.00000001)
                    ans = 0;
                else
                {
                    if (pm > azaza + 360 - 0.0000001)
                        ans = 1;
                    else
                    {
                        if (pm > 360)
                            pm -= 360;
                        if (360. / vs< (360 - pm) / v2)
                            ans = 1;
                        else
                            ans = 0;
                    }
                }
            }

        }

        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
}


/*
lol rev(lol x)
{
    if (x % 10 == 0)
        return x;
    lol r = 0;
    while (x)
    {
        r *= 10ll;
        r += x % 10ll;
        x /= 10ll;
    }
    return r;
}

lol build(lol x)
{
    return 0;
}

int main()
{
    vector<int> dp(100010002, 1234567890);
    dp[1] = 1;
    dp[0] = 0;
    for (int i = 2; i < 100010002; ++i)
        dp[i] = min(dp[i - 1], dp[rev(i)]) + 1;
    for (int i = 2; i < 100010002; ++i)
    {
        if (rev(i) < i && i % 10 == 1)
        {
            bool z = (dp[rev(i)] + 1 <= dp[i]);
            if (z)
            {
                cout << "ok " << i << endl;
                //cin.get();
            }
            else
            {
                //cout << "fail " << i << endl;
            }
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        lol ans = 0;
        while (n > 1000000)
        {
            ans += n % 10 - 1;
            n -= n % 10 - 1;
            int r = rev(n);
            if (r < n)
            {
                ++ans;
                n = r;
                continue;
            }
            int x = build(n);
        }
        cout << "Case #" << i + 1 << ": " << ans + dp[n] << endl;
    }
}

/*
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        lol r, c, n;
        cin >> r >> c >> n;
        vector<int> v;
        for (int i = 0; i < n; ++i)
            v.push_back(0);
        for (int i = n; i < r * c; ++i)
            v.push_back(1);
        int best = 123456789;
        do
        {
            int curr = 0;
            for (int i = 0; i < r - 1; ++i)
                for (int j = 0; j < c; ++j)
                    if (!v[i * c + j] && !v[(i + 1) * c + j])
                        ++curr;
            for (int j = 0; j < c - 1; ++j)
                for (int i = 0; i < r; ++i)
                    if (!v[i * c + j] && !v[i * c + j + 1])
                        ++curr;
            best = min(best, curr);
        } while (next_permutation(v.begin(), v.end()));
        cout << "Case #" << i + 1 << ": " << best << endl;
    }
}
*/