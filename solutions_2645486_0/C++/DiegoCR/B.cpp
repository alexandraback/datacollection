#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

long long E, R, N;
long long arr[11000];

int solve(int act, int cant)
{
    if ( act >= N )
        return 0;
    int s = 0, aux;
    for ( int i = 0; i <= cant; i ++ )
    {
        aux = i*arr[act] + solve(act + 1, min(E, cant - i + R));
        s = max(s, aux);
    }
    return s;
}

int main()
{
    freopen ( "SmallB.in", "r", stdin );
    freopen ( "SmallB.out", "w", stdout );

    int tc = 0, ntc;

    cin >> ntc;

    while ( ntc -- )
    {
        tc ++;

        cin >> E >> R >> N;

        for ( int i = 0; i < N; i ++ )
            cin >> arr[i];

        int ans = solve(0, E);

        cout << "Case #" << tc << ": " << ans << endl;
    }
}
