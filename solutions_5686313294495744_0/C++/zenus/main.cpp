#include <bits/stdc++.h>

using namespace std;

const int nmax = 19;

int tests , T , i , n , fake , j , mask , submask;
vector < string > er;
int a[nmax] , b[nmax] , dp[1 << nmax];
string x[nmax] , y[nmax];

int main()
{
freopen("test.in" , "r" , stdin);
freopen("test.out" , "w" , stdout);

cin >> tests;
for (T = 1 ; T <= tests ; ++T)
{
    cin >> n;
    er.clear();
    memset(dp , 0 , sizeof(dp));

    for (i = 0 ; i < n ; ++i)
    {
        cin >> x[i] >> y[i];
        er.push_back(x[i]);
        er.push_back(y[i]);
    }

    sort(er.begin() , er.end());
    er.resize(distance(er.begin() , unique(er.begin() , er.end())));

    for (i = 0 ; i < n ; ++i)
    {
        a[i] = lower_bound(er.begin() , er.end() , x[i]) - er.begin();
        b[i] = lower_bound(er.begin() , er.end() , y[i]) - er.begin();
    }

    for (mask = 0 ; mask < (1 << n) ; ++mask)
    {
        for (i = 0 ; i < n ; ++i)
        if ((1 << i) & mask)
        {
            submask = mask - (1 << i);

            fake = 0;

            for (j = 0 ; j < n ; ++j)
            if ((1 << j) & submask)
            if (a[j] == a[i])
            {
                fake++;
                break;
            }

            for (j = 0 ; j < n ; ++j)
            if ((1 << j) & submask)
            if (b[j] == b[i])
            {
                fake++;
                break;
            }

            if (fake == 2) dp[mask] = max(dp[mask] , dp[submask] + 1);
            else dp[mask] = max(dp[mask] , dp[submask]);
        }
    }

    cout << "Case #" << T << ": " << dp[(1 << n) - 1] << '\n';
}

return 0;
}
