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
#include <string>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}

int s2i(string s) {
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

string i2s(int n) {
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}

int n, tar;
vector<int> r1, r2, vv;

void run() {
    cin >> n;
    tar = n * 2;
    r1.resize(n);
    r2.resize(n);
    vv.resize(n, 0);
    REP(i,n) vv[i] = 0;
    vector<pair<int, int> > pp;
    REP(i,n) {
        int t1, t2;
        cin >> t1 >> t2;
        pp.push_back(make_pair(-t2, t1));
    }
    sort(pp.begin(), pp.end());
    REP(i,n) {
        r1[i] = pp[i].second;
        r2[i] = -pp[i].first;
    }
    //REP(i,n) cin >> r1[i] >> r2[i];
    int cur = 0, res = 0;
    while (true) {
        bool fl = false;

        REP(i,n) {
            if (vv[i] == 0 && cur >= r2[i]) {
                cur += 2;
                ++res;
                fl = true;
                vv[i] = 2;
                break;
            }
        }
        if (fl) continue;

        REP(i,n) {
            if (vv[i] == 1 && cur >= r2[i]) {
                cur += 1;
                ++res;
                fl = true;
                vv[i] = 2;
                break;
            }
        }
        if (fl) continue;

        REP(i,n) {
            if (vv[i] == 0 && cur >= r1[i]) {
                cur += 1;
                ++res;
                fl = true;
                vv[i] = 1;
                break;
            }
        }
        if (fl) continue;

        break;
    }

    if (cur == tar) cout << res << endl;
    else cout << "Too Bad" << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
