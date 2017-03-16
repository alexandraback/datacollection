#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 55;

vector < int > p[MAXN];
int TownCode[MAXN];
int Time , ans[MAXN];
bool been[MAXN];
int possible[MAXN];

void DFS( int v )
{
    //cout << v << endl;
    been[v] = true;
    ans[ Time ] = v ;
    Time++;

    for ( int i = 0 ; i < p[v].size() ; i++ )
    {
        int u = p[v][i];
        if ( !been[u] && possible[u] == 0 ) possible[u] = v;
    }

    int bestU;

    do
    {
        bestU = 0;
        for ( int i = 0 ; i < p[v].size() ; i++ )
        {
            int u = p[v][i];
            if ( been[u] || possible[u] != v ) continue;
            if ( bestU == 0 ) bestU = u;
            if ( TownCode[ u ] < TownCode[ bestU ] ) bestU = u;
        }
        if ( bestU != 0 ) DFS( bestU );
    }
    while( bestU != 0 );

}

int main()
{
    freopen("input.in" , "r" , stdin );
    freopen("output.out" , "w" , stdout );

    int T;
    cin >> T;

    for ( int t = 1 ; t <= T ; t++ )
    {
        int N , M ;
        cin >> N >> M ;

        for ( int i = 1 ; i <= N ; i++ )
        {
            cin >> TownCode[ i ] ;
            //cout << TownCode[ i ] << endl;
            p[i].clear();
            been[i] = false;
            possible[i] = 0;
        }

        for ( int i = 1 ; i <= M ; i++ )
        {
            int a , b ;
            cin >> a >> b ;
            p[a].push_back( b );
            p[b].push_back( a );
        }

        int start = 1 ;
        for ( int i = 1 ; i <= N ; i++ )
            if ( TownCode[i] < TownCode[start] ) start = i ;


        Time = 1;
        DFS( start );

        cout << "Case #" << t << ": ";

        for ( int i = 1 ; i <= N ; i++ )
            cout << TownCode[ ans[i] ];
        cout << endl;


    }


    return 0;
}
