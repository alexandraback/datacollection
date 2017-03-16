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

char inp[500000];

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

int doCase()
{
    
    //
    // READ INPUT
    //
    ll A, N;
    vector<ll> foo = readMulti<ll>();
    A = foo[0]; N = foo[1];
    vector<ll> bar = readMulti<ll>();

    if (N != bar.size()) {
        cerr << "BAD!" << endl;
        cerr << N << "," << bar.size() << endl;
    }

    sort(bar.begin(), bar.end());

    vector<ll> motes;
    for (int i = 0; i < bar.size(); i++) {
        if (bar[i] < A) {
            A += bar[i];
        }
        else {
            motes.push_back(bar[i]);
        }
    }

    int res = motes.size();

    for (int rem = 0; rem <= motes.size(); rem++) {
        vector<ll> tmp;
        for (int i = 0; i < motes.size() - rem; i++) {
            tmp.push_back(motes[i]);
        }
        for (int add = 0; add <= tmp.size(); add++) {
            ll newA = A;
            bool solved = false;
            for (int i = 0; i < add; i++) {
                bool good = true;
                newA = newA * 2 - 1;
                for (int j = 0; j < tmp.size(); j++) {
                    if (tmp[j] < newA) {
                        newA += tmp[j];
                    }
                    else {
                        good = false;
                    }
                }
                if (good) {
                    solved = true;
                }
            }
            if (solved) {
                res = min(res, rem + add);
                break;
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

