#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int N = 5555;

vector<string> dict;
char w[N];

int f[N][10];

int main() {
    freopen("dict.txt", "r", stdin);
    int maxlen = 0;
    while (gets(w)) {
        dict.push_back(w);
        maxlen = max(maxlen, (int) dict.back().size());
    }
    cerr << "End reading" << endl;
    cerr << clock() << endl;

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int _T;
    scanf("%d\n", &_T);

    for (int __test = 1; __test <= _T; ++__test) {
        gets(w);
        int n = strlen(w);

        memset(f, 63, sizeof(f));
        f[0][5] = 0;
        for (int pos = 0; pos < n; ++pos)
            for (int prev = 0; prev <= 5; ++prev) {
                if (f[pos][prev] > n) continue;
                int laster = pos - prev - 1;

                for (int i = 0; i < dict.size(); ++i) 
                    if (pos + dict[i].size() <= n) {
                        int prever = laster;
                        bool cool = true;
                        int cost = 0;
                        for (int j = 0; j < dict[i].size(); ++j)
                            if (w[pos + j] != dict[i][j]) {
                                if (pos + j - prever < 5) {
                                    cool = false;
                                    break;
                                } else {
                                    prever = pos + j;
                                    ++cost;
                                }
                            }
                        if (cool) {
                            int rel = pos + dict[i].size() - prever - 1;
                            if (rel > 5) rel = 5;
                            if (f[pos + dict[i].size()][rel] > f[pos][prev] + cost) {
                                f[pos + dict[i].size()][rel] = f[pos][prev] + cost;
                            }
                        }
                    }
            }

        int ans = f[n][0];
        for (int i = 0; i <= 5; ++i) ans = min(ans, f[n][i]);
        printf("Case #%d: ", __test);
        cout << ans << endl;


        cerr << __test << " finished" << endl;
        cerr << clock() << endl;
    }


    return 0;
}

