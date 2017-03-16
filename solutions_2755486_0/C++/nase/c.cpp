#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>
#include <cassert>

using namespace std;

#define ll          long long
#define VI          vector<int>
#define ALL(a)      (a).begin(), (a).end()
#define SORT(a)     sort( ALL(a) )
#define PB          push_back
#define FOR(i,a,b)  for( int i = (a); i < (int)(b); i++ )
#define dump_(x)     cerr << #x << " = " << (x) << " ";
#define dump(x)     cerr << #x << " = " << (x) << endl
#define dump_vec(x) FOR(zZz,0,x.size()) cout << x[zZz] << " "; cout << endl

char inp[1000000];

template< typename type > type readOne()
{
    type res;
    char* dum = fgets( inp, sizeof( inp ), stdin );
    stringstream ss( dum );
    ss >> res;
    return res;
}

template< typename type > vector<type> readMulti()
{
    vector<type> res;
    char* dum = fgets( inp, sizeof( inp ), stdin );
    stringstream ss( dum );
    for ( type t; ss >> t; )
        res.push_back( t );
    return res;
}

//
//
// LET'S START
//
//

map<int, long long> memo;
vector< pair<int, long long > > repair;
// day, ((west, east), s)
typedef pair<int, pair< pair<int, int>, ll > > Attack;
#define Day(a) a.first
#define W(a) a.second.first.first
#define E(a) a.second.first.second
#define S(a) a.second.second
vector<Attack> attacks;
Attack makeAttack(int day, int west, int east, long long st) {
    return make_pair(day, make_pair( make_pair(west, east), st));
}

int doCase()
{
    memo.clear();
    repair.clear();
    attacks.clear();

    assert(attacks.size() == 0);
    
    int N;
    scanf("%d", &N);
    FOR(i, 0, N) {
        int d, n, w, e, s, dd, dp, ds;
        scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
        FOR(j, 0, n) {
            int day = d + dd * j;
            int west = w + dp * j;
            int east = e + dp * j;
            long long str = s + (long long)ds * j;

            Attack a = makeAttack(day, west, east, str);
            attacks.push_back(a);
        }
    }

    sort(attacks.begin(), attacks.end());

    int res = 0;

    cerr << attacks.size() << endl;
    
    FOR(i, 0, attacks.size()) {
        int d = Day(attacks[i]);
//        cerr << "--------------- res = " << res << "\n";
//        cerr << "d = " << d << endl;
        int nextd = i < attacks.size() - 1 ? Day(attacks[i+1]) : d + 1;
        int w = W(attacks[i]);
        int e = E(attacks[i]);
        long long s = S(attacks[i]);
        bool good = false;
        
        FOR(x, w * 2, e * 2 + 1) {
            long long h = memo.count(x) ? memo[x] : 0;
//            cerr << "x, s, h = " << x / 2.0 << ":" << s << "," << h << endl;
            if (h < s) {
                good = true;
//                cerr << d << " GOOD ATTACK! " << x / 2.0 << " h=" << h << ", s=" << s << endl;
                repair.push_back(make_pair(x, s));
            }
        }

        if (good)
            res++;
        
        if (nextd > d) {
            FOR(j, 0, repair.size()) {
                int x = repair[j].first;
                ll s = repair[j].second;
                if (memo.count(x) == 0 || s > memo[x])
                    memo[x] = s;
            }
        }
    }

    return res;
}

int main()
{
    int cases = readOne<int>();
    for (int caseno = 1; caseno <= cases; caseno++)
        cout << "Case #" << caseno << ": " << doCase() << endl;
    return 0;
}

