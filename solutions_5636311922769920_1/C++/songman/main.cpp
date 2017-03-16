#include <bits/stdc++.h>

using namespace std;
using LINT = long long int;
using PII = pair<int,int>;

#define PB push_back
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)

void process(int caseNum) {
    int k, c, s;
    cin >> k >> c >> s;

    cout << "Case #" << caseNum << ":";

    if(s < k)
        cout << " IMPOSSIBLE";
    else
        REP(i, s)
            cout << " " << i+1;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    REP(i, t) process(i+1);
    return 0;
}
