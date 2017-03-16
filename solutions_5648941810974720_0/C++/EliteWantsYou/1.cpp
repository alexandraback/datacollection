#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int T, n, i, j, h, d[200];
vector < pair < char, int > > v[10];
string s, t;

int main()
{
    v[0].pb(mp('Z', 1));
    v[0].pb(mp('E', 1));
    v[0].pb(mp('R', 1));
    v[0].pb(mp('O', 1));
    v[1].pb(mp('O', 1));
    v[1].pb(mp('N', 1));
    v[1].pb(mp('E', 1));
    v[2].pb(mp('T', 1));
    v[2].pb(mp('W', 1));
    v[2].pb(mp('O', 1));
    v[3].pb(mp('T', 1));
    v[3].pb(mp('H', 1));
    v[3].pb(mp('R', 1));
    v[3].pb(mp('E', 2));
    v[4].pb(mp('F', 1));
    v[4].pb(mp('O', 1));
    v[4].pb(mp('U', 1));
    v[4].pb(mp('R', 1));
    v[5].pb(mp('F', 1));
    v[5].pb(mp('I', 1));
    v[5].pb(mp('V', 1));
    v[5].pb(mp('E', 1));
    v[6].pb(mp('S', 1));
    v[6].pb(mp('I', 1));
    v[6].pb(mp('X', 1));
    v[7].pb(mp('S', 1));
    v[7].pb(mp('E', 2));
    v[7].pb(mp('V', 1));
    v[7].pb(mp('N', 1));
    v[8].pb(mp('E', 1));
    v[8].pb(mp('I', 1));
    v[8].pb(mp('G', 1));
    v[8].pb(mp('H', 1));
    v[8].pb(mp('T', 1));
    v[9].pb(mp('N', 2));
    v[9].pb(mp('I', 1));
    v[9].pb(mp('E', 1));
    int p[10] = {2, 6, 4, 0, 8, 1, 3, 5, 7, 9};
    cin >> T;
    for( int k = 1; k <= T; k++ ){
        cin >> s;
        t = "";
        cout << "Case #" << k << ": ";
        for( i = 0; i < s.size(); i++ )
            d[s[i]]++;
        for( i = 0; i < 10; i++ ){
            h = 1000000;
            for( j = 0; j < v[p[i]].size(); j++ )
                h = min(h, d[v[p[i]][j].fi] / v[p[i]][j].se);
            for( j = 0; j < v[p[i]].size(); j++ )
                d[v[p[i]][j].fi] -= v[p[i]][j].se * h;
            for( j = 1; j <= h; j++ )
                t += char(p[i] + '0');
        }
        sort( t.begin(), t.end() );
        cout << t << endl;
    }
}
