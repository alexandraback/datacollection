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
    int n;
    cin >> n;
    set<int> digits;
    if(n == 0) {
        cout << "Case #" << caseNum << ": INSOMNIA" << endl;
        return;
    }

    int acc = 0;
    while(digits.size() < 10) {
        acc += n;
        int tmp = acc;
        while(tmp) {
            digits.insert(tmp % 10);
            tmp /= 10;
        }
    }

    cout << "Case #" << caseNum << ": " << acc << endl;
}

int main() {
    int t;
    cin >> t;
    REP(i, t) process(i+1);
    return 0;
}
