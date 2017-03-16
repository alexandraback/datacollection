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

int doCase()
{
    int n;
    scanf("%s%d", inp, &n);
    int L = strlen(inp);
    
//    cerr << inp << "," << n << ",L = " << L << endl;

    int res = 0;
    FOR(i, 0, L) FOR(j, i + 1, L + 1) {
        int cnt = 0;
        int c = 0;
        FOR(k, i, j) {
            if (vowel[inp[k]]) {
                c = 0;
            }
            else {
                c++;
                cnt = max(cnt, c);
            }
        }
        string s = string(inp).substr(i, j - i);
//        cerr << s << ":cnt = " << cnt << endl;
        if (cnt >= n) res++;
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

