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

char inp[5000000];

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

int vowel[256];
int cnt[1000010];
int where[1000010];

ll doCase()
{
    memset(cnt, 0, sizeof(cnt));
    memset(where, -1, sizeof(cnt));
    
    int n;
    scanf("%s%d", inp, &n);
    int L = strlen(inp);
    
//    cerr << inp << "," << n << ",L = " << L << endl;

    ll res = 0;

    int c = 0;
    FOR(i, 0, L) {
        if (vowel[inp[i]]) {
            c = 0;
        }
        else {
            c++;
        }
        cnt[i] = c;
    }

//    dump_vec(vector<int>(cnt, cnt + L));

    int w = L;
    for (int i = L - 1; i >= 0; i--) {
        where[i] = w;
        if (cnt[i] >= n) {
            w = i;
        }
    }

//    dump_vec(vector<int>(where, where + L));
    
    FOR(i, 0, L) {
        if (cnt[i] >= n) {
            res += (ll)(i + 2 - n) * (where[i] - i);
        }
    }
    
    return res;
}

int main()
{
    memset(vowel, 0, sizeof(vowel));
    vowel['a'] = 1;
    vowel['e'] = 1;
    vowel['i'] = 1;
    vowel['o'] = 1;
    vowel['u'] = 1;
    int cases = readOne<int>();
    for (int caseno = 1; caseno <= cases; caseno++)
        cout << "Case #" << caseno << ": " << doCase() << endl;
    return 0;
}

