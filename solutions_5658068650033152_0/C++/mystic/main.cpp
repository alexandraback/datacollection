#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool checkB(vector<string>& s) {
    bool cs[256] = {};
    char last = s[0][0];
    cs[last] = true;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s[i].size() - 1; ++j) {
            if (s[i][j] == last)
                continue;
            last = s[i][j];
            if (!cs[(unsigned char)last]) {
                cs[(unsigned char)last] = true;
            } else {
                return false;
            }
        }
    }
    return true;
}

int countC(vector<vector<bool> >& f) {
    vector<vector<int> > f2(f.size(), vector<int>(f[0].size()));
    for (int i = 0; i < f.size(); ++i) {
        if (!f[i].front())
            f2[i].front() = 1;
        if (!f[i].back())
            f2[i].back() = 1;
    }
    for (int j = 0; j < f[0].size(); ++j) {
        if (!f.front()[j])
            f2.front()[j] = 1;
        if (!f.back()[j])
            f2.back()[j] = 1;
    }
    for (int n = 0; n < 20; ++n) {
        for (int i = 0; i < f.size(); ++i) {
            for (int j = 0; j < f.front().size(); ++j) {
                if (f[i][j])
                    continue;
                if (i > 0 && f2[i-1][j] == 1)
                    f2[i][j] = 1;
                if (j > 0 && f2[i][j-1] == 1)
                    f2[i][j] = 1;
                if (i < f.size() - 1 && f2[i+1][j] == 1)
                    f2[i][j] = 1;
                if (j < f[0].size() - 1 && f2[i][j+1] == 1)
                    f2[i][j] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < f.size(); ++i)
        for (int j = 0; j < f[i].size(); ++j)
            count += 1 - f2[i][j];
    return count;
}

int main() {
    int T = 0;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ": ";
        int N, M, K;
        cin >> N >> M >> K;
        int result = K;
        for (int i = 0; i < (1<<N*M); ++i) {
            vector<vector<bool> > b(N, vector<bool>(M));
            int c = 0;
            for (int j = 0; j < N*M; ++j) {
                if (i & (1 << j)) {
                    b[j/M][j%M] = true;
                    c++;
                }
            }
            if (countC(b) >= K)
                result = min(result, c);
        }
        cout << result;
        cout << endl;
    }
}
