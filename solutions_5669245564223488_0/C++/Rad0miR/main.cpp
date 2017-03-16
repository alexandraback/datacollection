#include <map>
#include <set>
#include <queue>
#include <time.h>
#include <string>
#include <math.h>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
const int inf = 1000000000,
          mod = 1000000007;
#define Wi(a) printf("%d ", (a))
#define Wi2(a, b) printf("%d %d ", (a), (b))
#define Wie(a) printf("%d\n", (a))
#define Wie2(a, b) printf("%d %d\n", (a), (b))
#define Ri(a) scanf("%d", &(a))
#define Ri2(a, b) scanf("%d%d", &(a), &(b))
#define F first
#define S second
#define pii pair < int, int >
#define v(tp) vector< tp >
#define ll long long
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for(int (i) = (a), _n_ = (b); (i) <= _n_; (i)++)
#define FORD(i,a,b) for(int (i) = (a), _n_ = (b); (i) >= _n_; (i)--)
#define forn(i,b) FOR((i),0,(b) - 1)
using namespace std;



int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T;
    Ri(T);
    FOR( nom, 1, T ) {
        int n;
        Ri( n );
        int ans = 0;
        bool used[50];
        int k[50];
        memset( used, 0, 50 );
        memset( k, 0, 200 );
        vector < pair< int, string > > v;
        forn( i, n ) {
            string s;
            cin >> s;
            s.resize( unique(all(s)) - s.begin() );
            //cout << s << endl;
            FOR( j, 1, s.size() - 2 ) {
                //if( used[ s[j] - 'a' ] ) goto ex;
                used[ s[j] - 'a' ] = 1;
                k[ s[j] - 'a' ]++;
            }
            k[ s[0] - 'a' ]++;
            k[ s[s.size() - 1] - 'a' ]++;
            if( s.size() != 1 && s[0] == s[s.size() - 1] ) goto ex;
            if( s.size() > 2 ) s.erase( s.begin() + 1, s.end() - 1 );
            //cout << s << endl;
            v.pb( mp( i, s ) );
            //cout << v[i].S.F << v[i].S.S << endl;
        }
        forn( i, 50 ) {
            if( used[ i ] && k[i] >= 2 ) goto ex;
        }
        do {
            string s, s1;
            forn( i, v.size() ) {
                s += v[i].S;
            }
            s1 = s;
            sort( all(s) );
            if( unique( all(s) ) - s.begin() == unique( all(s1) ) - s1.begin() ) ans++;
        } while( next_permutation( all(v) ) );
        ex:;
        cout << "Case #" << nom << ": " << ans << "\n";
        //cout << clock() << endl;
    }

    return 0;
}
