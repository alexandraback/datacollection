#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

map<int, string> mp;
map<int, char> key;
int order[10] = {0, 6, 7, 8, 5, 4, 3, 2, 1, 9};

void init() {
    mp[0] = "ZERO";
    mp[1] = "ONE";
    mp[2] = "TWO";
    mp[3] = "THREE";
    mp[4] = "FOUR";
    mp[5] = "FIVE";
    mp[6] = "SIX";
    mp[7] = "SEVEN";
    mp[8] = "EIGHT";
    mp[9] = "NINE";

    key[0] = 'Z';
    key[6] = 'X';
    key[7] = 'S';
    key[8] = 'G';
    key[5] = 'V';
    key[4] = 'U';
    key[3] = 'R';
    key[2] = 'W';
    key[1] = 'O';
    key[9] = 'I';
}

void run() {
    string s;
    cin >> s;
    int v[26] = {0};
    REP(i,s.length()) {
        v[s[i] - 'A']++;
    }
    vector<int> res;
    REP(i,10) {
        int c = order[i];
        char k = key[c];
        int n = v[k - 'A'];
        string m = mp[c];
        REP(j,m.length()) {
            int idx = m[j] - 'A';
            v[idx] -= n;
        }
        REP(j, n) res.push_back(c);
    }
    sort(res.begin(), res.end());
    REP(i, res.size()) cout << res[i];
    cout << endl;
}

int main() {
    init();
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
