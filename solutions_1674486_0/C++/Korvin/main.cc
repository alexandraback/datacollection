#include <vector> // headers {{{
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <time.h>

using namespace std; // }}}

string result(vector<vector<int> > tb)
{
    //ofstream fcout("log.out", ios::app);
    vector<vector<int> > tb0(tb);

    int n = tb.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && i != k && j != k && tb0[i][k] && tb0[k][j])
                    tb0[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || !tb0[i][j])
                continue;
            if (tb[i][j]) {
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j || !tb0[k][j] || !tb[i][k])
                        continue;
                    return "Yes";
                }
            }
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j || !tb0[k][j] || !tb[i][k])
                    continue;
                for (int k0 = 0; k0 < n; ++k0) {
                    if (k0 == k || k0 == i || k0 == j || !tb0[k0][j] || !tb[i][k0])
                        continue;
                    return "Yes";
                }
            }
        }
    }

    return "No";
}

int main()
{
    //time_t start, end;
    //time(&start);

    ifstream fcin("test.in");
    ofstream fcout("test.out");
    //fcout.precision(6);
    //fcout.setf(ios::fixed,ios::floatfield);

    int T;
    fcin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        fcin >> N;
        vector<vector<int> > tb(N, vector<int>(N));
        for (int j = 0; j < N; ++j) {
            int cur;
            fcin >> cur;
            for (int k = 0; k < cur; ++k) {
                int Mi;
                fcin >> Mi;
                tb[j][Mi - 1] = 1;
            }
        }
        fcout << "Case #" << i + 1 << ": " << result(tb) << endl;
    }

    //time(&end);
    //cout << difftime(end, start) << endl;

    return 0;
}
