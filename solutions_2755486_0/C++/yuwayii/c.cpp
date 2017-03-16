#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct attack
{
    int d;
    int w, e;
    int s;
};

bool operator<( const attack &a, const attack&b )
{
    return a.d < b.d;
}

vector< attack > atks;

int main()
{
    int t;
    cin >> t;
    for( int tcase = 1; tcase <= t; ++tcase )
    {
        cout << "Case #" << tcase << ": ";

        atks.clear();
        int n;
        int d, m, w, e, s, delta_d, delta_p, delta_s;
        
        cin >> n;
        for( int i = 0; i < n; ++i )
        {
            cin >> d >> m >> w >> e >> s >> delta_d >> delta_p >> delta_s;
            for( int j = 0; j < m; ++j )
            {
                attack tmp;
                tmp.d = d + j * delta_d;
                tmp.w = w + j * delta_p;
                tmp.e = e + j * delta_p;
                tmp.s = s + j * delta_s;
                atks.push_back( tmp );
            }
        }
        sort( atks.begin(), atks.end() );

        //for( int i = 0; i < atks.size(); ++i )
        //cout << atks[ i ].d << ':' << atks[ i ].w << ' ' << atks[ i ].e << ':' << atks[ i ].s << endl;
        
        int res = 0;
        map< int, int > mymap;
        for( int i = 0, l = atks.size(); i < l; ++i )
        {
            if( i != 0 && atks[ i ].d != atks[ i - 1 ].d )
            {
                for( int k = i - 1; k >= 0; --k )
                    if( atks[ k ].d == atks[ i - 1 ].d )
                    {
                        for( int j = atks[ k ].w; j < atks[ k ].e; ++j )
                            if( mymap[ j ] < atks[ k ].s )
                                mymap[ j ] = atks[ k ].s;
                    }
                    else break;
            }
            for( int j = atks[ i ].w; j < atks[ i ].e; ++j )
                if( mymap[ j ] < atks[ i ].s )
                {
                    ++res;
                    break;
                }
        }

        cout << res << endl;
    }
}
