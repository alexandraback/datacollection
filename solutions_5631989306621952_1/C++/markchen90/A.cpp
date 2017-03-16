#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define FOREACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define MOD 1000000007
#define INF 2000000000

int T; string s;

string solve(string x, int c) {
    if (x.size() == 0) return x;

    vector<int> pos; pos.PB(-1);

    int cnt = 0;

    FORN(i, x.size()) {
        if (x[i] == (char)('A' + c)) {
            pos.PB(i);
            cnt++;
        }
    }

    pos.PB(x.size());

    string res; FORN(i, cnt) res += (char)('A' + c);

    for (int i = 1; i < pos.size(); i++) {
        if (i == 1) {
            res += solve(x.substr(pos[i-1] + 1, pos[i] - pos[i-1] - 1), c - 1);
        }
        else {
            res += x.substr(pos[i-1] + 1, pos[i] - pos[i-1] - 1);
        }
    }

    return res;
}

int main() {
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        printf("Case #%d: ", tc); cin >> s;
        cout << solve(s, 25) << endl;
    }
    
    return 0;
}
