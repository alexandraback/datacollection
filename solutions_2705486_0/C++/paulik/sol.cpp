#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int INF = 1e9;

vector<string> dict;

void load(const char* filename) {
    ifstream input(filename);
    vector<char> buffer(1 << 13);
    input.rdbuf()->pubsetbuf(&buffer[0], buffer.size());
    string str;
    while (getline(input, str))
        dict.push_back(str);
}

int solve() {
    string s;
    cin >> s;
    int n = s.size();

    vector< vector<int> > f(n + 1, vector<int>(5, INF));
    f[0][4] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < dict.size(); ++j) {
            const string& str = dict[j];
            if (i + str.size() > n)
                continue;
            int first_bad = INF;
            int last_bad = -INF;
            bool very_bad = false;
            int diff = 0;
            for (int k = 0; k < str.size(); ++k)
                if (str[k] != s[i + k]) {
                    if (k - last_bad < 5) {
                        very_bad = true;
                        break;
                    }
                    ++diff;
                    last_bad = k;
                    if (first_bad == INF)
                        first_bad = k;
                }
            if (very_bad)
                continue;
            last_bad = min(int(str.size()) - last_bad - 1, 4);

            int ii = i + str.size();
            for (int j = 4; j >= 0 && j + first_bad >= 4; --j) {
                if (f[i][j] == INF)
                    continue;
                f[ii][last_bad] = min(f[ii][last_bad], f[i][j] + diff);
            }
        }
    }

    int ans = INF;
    for (int j = 0; j < 5; ++j)
        ans = min(ans, f[n][j]);
    return ans;
}

int main() {
    int tt;
    scanf("%d", &tt);
    load("dict.txt");
    for (int t = 1; t <= tt; ++t) {
        printf("Case #%d: %d\n", t, solve());
    }

    return 0;
}

