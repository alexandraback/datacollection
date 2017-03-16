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
#include <fstream>

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

#define CSIZE 100
double choose[ CSIZE+1 ][ CSIZE+1 ];
void choose_init()
{
    memset( choose, 0, sizeof( choose ) );
    for ( int i = 0; i <= CSIZE; i++ ) {
        choose[i][0] = 1;
        for ( int j = 1; j <= i; j++ )
            choose[i][j] = ( choose[i-1][j-1] + choose[i-1][j] );
    }
}

//
//
// LET'S START
//
//

vector<string> words;
string S;
int memo[100][100];

int solve(int pos, int last)
{
    int& res = memo[pos][last];
    if (res != -1) return res;
    if (pos >= S.size()) return 0;
    res = 100;
    for (int i = 0; i < words.size(); i++) {
        if (pos + words[i].size() > S.size()) continue;
        bool good = true;
        int tlast = last;
        int error = 0;
        for (int j = 0; j < words[i].size(); j++) {
            if (S[pos + j] != words[i][j]) {
                error ++;
                if (tlast < 100 && pos + j - tlast < 5) {
                    good = false;
                    break;
                }
                tlast = pos + j;
            }
        }
        if (good) {
//            cerr << words[i] << "," << tlast << endl;
            res = min(res, error + solve(pos + words[i].size(), tlast));
        }
    }
    return res;
}

int doCase()
{
    cin >> S;
    memset(memo, -1, sizeof(memo));
    return solve(0, 100);
}

int main()
{
    std::ifstream ifs( "garbled_email_dictionary.txt" );
    int tmp = 0;
    while (!ifs.eof()) {
        tmp ++;
        string t;
        ifs >> t;
        words.push_back(t);
        if (tmp == 521196) break;
    }

    cerr << words.size() << endl;
    cerr << words[words.size() - 1] << endl;
    
    int cases = readOne<int>();
    for (int caseno = 1; caseno <= cases; caseno++)
        cout << "Case #" << caseno << ": " << doCase() << endl;
    return 0;
}

