#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int arr[110], n;

int solve ( int a, int ind )
{
    if ( ind == n )
        return 0;

    if ( a > arr[ind] )
        return solve(a+arr[ind], ind + 1);

    int ret = n - ind;
    int pos = 1 + solve(a + a-1, ind);

    return min(ret, pos);

}

int main()
{
    freopen ( "a.in", "r", stdin );
    freopen ( "SmallA.out", "w", stdout );

    int ntc, tc = 0;
    int A;

    cin >> ntc;

    while ( ntc -- )
    {
        tc ++;
        cin >> A >> n;

        for ( int i = 0; i < n; i ++ )
            cin >> arr[i];

        if ( A == 1 )
        {
            cout << "Case #" << tc << ": "<< n << endl;
            continue;
        }

        sort ( arr, arr + n );

        int ans = solve( A, 0 );

        cout << "Case #" << tc << ": "<< ans << endl;

    }
}
