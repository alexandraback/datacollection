#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <list>
#include <memory>
#include <string>
#include <vector>
#include <functional>
#include <climits>
#include <cstring>
#include <cstdio>
using namespace std;

#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define SIZE(v) (int)(v).size()
#define ALL(v) (v).begin(), (v).end()
typedef long long LL;
#define DBG(x) cout << #x << " = " << x << endl
#define DBGV(v) REP(i, SZ((v))) cout << #v << '[' << i << "] = " << (v)[i] << endl

string doit(const string& s)
{
    string res = "";
    REP(i, SIZE(s)) res = max(res + s[i], string(1, s[i]) + res);
    return res;
}

int main()
{
    int testCount;
    cin >> testCount;
    FOR(zzz, 1, testCount) {
        string s;
        cin >> s;
        cout << "Case #" << zzz << ": " << doit(s) << '\n';
    }

    return 0;
}
