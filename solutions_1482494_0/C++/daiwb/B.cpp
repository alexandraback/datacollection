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

int mm[1 << 20][25];
int n, tar;
vector<int> r1, r2;

#define INF 1000000000

int dp(int state, int cur) {
    int& res = mm[state][cur];
    if (res != -1) return res;

    if (cur == tar) return res = 0;

    res = INF;
    REP(i,n) {
        int s1 = (state & (1 << (i * 2)));
        int s2 = (state & (1 << (i * 2 + 1)));
        if (s2 == 0) continue;
        if (cur >= r2[i]) {
            int ns = (state ^ (1 << (i * 2 + 1)));
            int add = 0;
            if (s1 == 0) add = 1;
            else add = 2;
            int t = dp(ns, cur + add) + 1;
            res = min(res, t);
        }
        if (cur >= r1[i] && (s1 > 0)) {
            int ns = (state ^ (1 << (i * 2)));
            int t = dp(ns, cur + 1) + 1;
            res = min(res, t);
        }
    }

    return res;
}

void run() {
    cin >> n;
    tar = n * 2;
    r1.resize(n);
    r2.resize(n);
    REP(i,n) cin >> r1[i] >> r2[i];
    memset(mm, -1, sizeof(mm));
    int res = dp((1 << (n * 2)) - 1, 0);
    if (res == INF) cout << "Too Bad" << endl;
    else cout << res << endl;
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
