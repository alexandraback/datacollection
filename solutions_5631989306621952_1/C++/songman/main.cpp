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
    string str;
    cin >> str;

    deque<char> res;

    res.push_front(str[0]);

    for(int i = 1; i < str.size(); ++i)
        if(str[i] >= res.front())
            res.push_front(str[i]);
        else
            res.push_back(str[i]);

    cout << "Case #" << caseNum << ": ";

    for(char c : res)
        cout << c;
    cout << endl;

}

int main() {

    int t;
    cin >> t;
    REP(i, t) process(i+1);

    return 0;
}
