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


template< typename type > type readOne()
{
  type res;
  char inp[5000];
  char* dum = fgets( inp, sizeof( inp ), stdin );
  stringstream ss( dum );
  ss >> res;
  return res;
}

template< typename type > vector<type> readMulti()
{
  vector<type> res;
  char inp[5000];
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

string doit(string S) {
    string res = string(1, S[0]);
    for (int i = 1; i < S.size(); i++) {
	if (S[i] >= res[0]) {
	    res = string(1, S[i]) + res;
	}
	else {
	    res = res + string(1, S[i]);
	}
    }
    return res;
}

string doCase()
{
  //
  // DOIT!
  //
  string S = readOne<string>();
  return doit(S);
}

int main()
{
  int cases = readOne<int>();
  for (int caseno = 1; caseno <= cases; caseno++)
    cout << "Case #" << caseno << ": " << doCase() << endl;
  return 0;
}

