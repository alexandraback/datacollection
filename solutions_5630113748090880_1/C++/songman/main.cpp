#include <bits/stdc++.h>

using namespace std;
using LINT = long long int;
using PII = pair<int,int>;

#define PB push_back
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)

int cache[2507];

void process(int caseNum) {
   int n;
   cin >> n;

   memset(cache, 0, sizeof cache);

   REP(i, 2*n-1)
    REP(j, n)
        {
            int x;
            cin >> x;
            cache[x]++;
        }

    vector<int> res;

    REP(i, 2507)
        if(cache[i] % 2 != 0)
            res.push_back(i);

    sort(res.begin(), res.end());

    cout << "Case #" << caseNum << ":";
    for(int r : res)
        cout << ' ' <<  r;
    cout << endl;
}

int main() {

    int t;
    cin >> t;
    REP(i, t) process(i+1);

    return 0;
}
