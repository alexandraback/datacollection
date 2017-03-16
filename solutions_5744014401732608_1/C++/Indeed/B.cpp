#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int ma[51][51];
void process(int tc)
{
    ll n = 0, m = 0;
    cin >> n >> m;
    cout << "Case #" << tc << ": ";
    memset(ma , 0 ,sizeof ma);
    if (1LL << (n - 2) < m)
    {
        cout << "IMPOSSIBLE" << endl;
        return ;
    } else if (1LL << (n - 2) == m)
    {
        for (int i = 1 ; i <= n ; ++i)
            for (int j = i + 1 ; j <= n ; ++j)
                ma[i][j] = 1;
    } else
    {
        for (int i = 2 ; i <= n ; ++i)
            for (int j = i + 1 ; j <= n ; ++j)
                ma[i][j] = 1;
        for (ll k = 0 ; n - 1 - k >= 2; ++k)
            if ( m & (1 << k) )
                ma[1][n - 1 - k] = 1;
    }
    cout << "POSSIBLE" << endl;
    for (int i = 1 ; i <= n ; ++i)
    {
        for (int j = 1 ; j <= n ; ++j)
            cout << ma[i][j];
        cout << endl;
    }
}

int main()
{
    int t = 0 ;
    cin >> t;
    for (int i = 1 ; i <= t ; ++i)
        process(i);
    return 0;
}
