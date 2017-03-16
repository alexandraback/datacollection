#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long


//set<int>::iterator ii;


int arr[113][113];
int main()
{
    ios::sync_with_stdio(false);

    inf;
    outf;

    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        cout << "Case #" << ca++ <<": ";

        int i, j, x = 0, y, n, m, a, b, c;

        cin >> n >> m;

        memset( arr, 0, sizeof( arr ) );

        for( i=1; i < n; i++ )
    {
        if( x >= m )
            break;
        arr[i][n]++;
        arr[i][0]++;
        x++;

        if( x >= m )
            break;
    }
    c = n-1;
    while( c > 0 )
    {
        if( x >= m )
            break;
        for( i=1; i < n; i++ )
    {
        if( x >= m )
            break;
        if( arr[i][c] == 0 && i != c && arr[c][i] == 0 )
        {
            arr[i][c]++;
            arr[i][0] += arr[c][0];
            x += arr[c][0];
        }

        if( x >= m )
            break;
    }
     if( x >= m )
            break;
    c--;

    }
    //cout << x << endl;

    if( x == m )
    {
        cout << "POSSIBLE" << endl;
        for( i=1; i<=n; i++ )
    {
            for( j=1; j<=n; j++ )
        {
            cout << arr[i][j] ;
        }

        cout << endl;
    }

    }

    else
        cout << "IMPOSSIBLE" << endl;

    }

    return 0;

}



