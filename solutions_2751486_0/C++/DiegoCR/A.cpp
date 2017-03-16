#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1000005];

bool isV(char c)
{
    if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
        return true;

    return false;
}

int main()
{
    freopen ( "a.in", "r", stdin );
    freopen ( "SmallA.out", "w", stdout );

    int ntc, tc = 0, n;
    string l;

    cin >> ntc;

    while ( ntc -- )
    {
        tc ++;

        cin >> l >> n;

        if ( isV(l[0]) )
            arr[0] = 0;
        else
            arr[0] = 1;

        for ( int i = 1; i < l.size(); i ++ )
            if ( isV(l[i]) )
                arr[i] = 0;
            else
                arr[i] = arr[i - 1] + 1;

        long long ans = 0, ant = n - 2;

        for ( long long i = n - 1; i < l.size(); i ++ )
            if ( arr[i] >= n )
            {
                ans += (i - ant)*(l.size() - i);
                ant = i;
            }

        cout << "Case #" << tc << ": " << ans << endl;
    }
}
