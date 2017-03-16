#include <algorithm>
#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  

bool isVowel(char c) {
    if (c == 'a') return true;
    if (c == 'i') return true;
    if (c == 'u') return true;
    if (c == 'e') return true;
    if (c == 'o') return true;
    return false;
}

void solve() {
    string s;
    int n;
    cin >> s >> n;

    int head = 0;
    int tail = -1;
    int cnt = 0;

    vector<pair<int, int> > v;
    REP (i, s.length()) {
        if (isVowel(s[i])) {
            if (cnt >= n)
                v.push_back(make_pair(head, tail));
            head = i+1;
        }
        else {
            ++cnt;
            tail = i;
        }

        if (i == (int)s.length() - 1 && !isVowel(s[i])) {
            if (cnt >= n)
                v.push_back(make_pair(head, tail));
        }
    }

    vector<int> pos;
    const int oo = 1<<30;
    REP (i, s.length()) {
        vector<pair<int, int> >::iterator itr = lower_bound(v.begin(), v.end(), make_pair(i, oo));
        if (itr == v.begin())
            continue;
        --itr;

        if (itr->first <= i && i + n - 1 <= itr->second)
            pos.push_back(i);
    }

    long long ret = 0;
    REP (i, s.length()) {
        vector<int>::iterator itr = lower_bound(pos.begin(), pos.end(), i);
        if (itr == pos.end())
            continue;

        int x = *itr + n - 1;
        ret += s.length() - 1 - x + 1;
    }

    cout << ret << endl;
}

int main() {
    int T;
    cin >> T;
    REP (i, T) {
        printf("Case #%d: ", i+1);
        cerr << i << endl;
        solve();
    }
    return 0;
}
