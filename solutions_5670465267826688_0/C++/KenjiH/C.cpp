#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define MP(x,y) make_pair(x,y)
#define REP(i,n) for(int i=0; i<(int)(n); i++)

map<pair<string, string>, string> tbl;

void push(string x, string y, string z) {
    tbl[make_pair(x, y)] = z;
}

void init() {
    push("1", "1", "1"); push("1", "i", "i"); push("1", "j", "j"); push("1", "k", "k"); 
    push("i", "1", "i"); push("i", "i", "-1"); push("i", "j", "k"); push("i", "k", "-j"); 
    push("j", "1", "j"); push("j", "i", "-k"); push("j", "j", "-1"); push("j", "k", "i"); 
    push("k", "1", "k"); push("k", "i", "j"); push("k", "j", "-i"); push("k", "k", "-1"); 
}

string mul(string x, string y) {
    int sign = 0;

    if (x.length() > 1) {
        ++sign;
        x = x.substr(1);
    }

    if (y.length() > 1) {
        ++sign;
        y = y.substr(1);
    }

    string ret = tbl[make_pair(x, y)];

    if (sign % 2) {
        if (ret.length() == 1)
            ret = "-" + ret;
        else
            ret = ret.substr(1);
    }

    return ret;
}

string pow(string s, long long p) {
    string ret = "1";
    REP (i, p%4)
        ret = mul(ret, s);
    return ret;
}

string acc[10000*20+1];

bool check(int l, long long x, const string &s) {
    acc[0] = "1";

    int p1 = 1<<30;
    int p2 = -1;

    for (int i = 0; i < min(20LL, x); i++) {
        for (int j = 0; j < l; j++) {
            acc[i*l+j+1] = mul(acc[i*l+j], string(1, s[j]));
            
            if (acc[i*l+j+1] == "i")
                p1 = min(p1, i*l+j+1);
            if (acc[i*l+j+1] == "k")
                p2 = max(p2, i*l+j+1);
        }
    }

    if (pow(acc[l], x) != "-1")
        return false;

    return p1 < p2;
}

void solve() {
    
    int l;
    long long x;
    string s;

    cin >> l >> x;
    cin >> s;

    if (check(l, x, s))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    
    init();

    int T;
    cin >> T;
    REP (i, T) {
        cerr << "Case #" << i+1 << ": " << endl;
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
