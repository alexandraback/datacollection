#include <functional>
#include <algorithm>
#include <utility>
#include <cassert>
#include <cmath>
#include <ctime>

#include <numeric>
#include <iomanip>
#include <complex>
#include <float.h>
#include <cfloat>

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <cstdio>

#include <cstring>
#include <string>

#include <iterator>
#include <vector>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;

int kOfTest, N;
vector<bool> used;
vector< vector<int> > g;
vector<int> vlist, dp;

void dfs (int v) {
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs (to);
    }
    vlist.push_back (v);
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> kOfTest;

    for(int iTest = 1; iTest <= kOfTest; ++iTest) {
        cin >> N;
        g.clear();
        g.resize(N);
        for(int from = 0; from < N; ++from) {
            int K;
            cin >> K;
            for(int j = 0; j < K; ++j) {
                int to;
                cin >> to;

                -- to;

                g[from].push_back(to);
            }
        }

        used.clear();
        used.resize(N, false);

        vlist.clear();

        for (int i = 0; i < N; ++i)
            if (!used[i])
                dfs (i);
        reverse (vlist.begin(), vlist.end());

        bool ok = false;
        for(int i = 0; i < N; ++i) {
            int from = vlist[i];
            dp.clear();
            dp.resize(N, 0);
            dp[from] = 1;
            for(int j = i; j < N; ++j) {
                from = vlist[j];
                for(int q = 0; q < g[from].size(); ++q) {
                    int to = g[from][q];
                    dp[to] += dp[from];
                    if(dp[to] > 1) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
            if(ok) break;
        }


        cout << "Case #" << iTest << ": " << ((ok) ? "Yes" : "No") << endl;
    }

    return 0;
}

