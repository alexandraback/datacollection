#include <bits/stdc++.h>

using namespace std;

const int nmax = 59;

long long a[nmax][nmax];
long long tests , T , r , i , j , n , m;

int main()
{
freopen("test.in" , "r" , stdin);
freopen("test.out" , "w" , stdout);

cin >> tests;

for (T = 1 ; T <= tests ; ++T)
{
    cin >> n >> m;
    memset(a , 0 , sizeof(a));

    cout << "Case #" << T << ": ";

    if ((1LL << (n - 2)) < m)
    {
        cout << "IMPOSSIBLE\n";
        continue;
    }

    cout << "POSSIBLE\n";

    r = 0;
    while ((1LL << r) <= m) r++;
    r--;

    for (i = 2 ; i <= r + 2 ; ++i)
    for (j = 1 ; j <= i - 1 ; ++j)
    a[j][i] = 1;

    for (i = 0 ; (1LL << i) <= m ; ++i)
    if ((1LL << i) & m) a[i + 2][r + 3] = 1;

    for (i = r + 4 ; i <= n ; ++i)
    a[i - 1][i] = 1;

    for (i = 1 ; i <= n ; ++i , cout << '\n')
    for (j = 1 ; j <= n ; ++j)
    cout << a[i][j];
}

return 0;
}

