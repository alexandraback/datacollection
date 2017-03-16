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

bool check(vector<string>& s) {
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

int main() {
    int T = 0;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ": ";
        int N;
        cin >> N;
        vector<string> s(N);
        for (int i = 0; i < N; ++i) {
            cin >> s[i];
            ostringstream str;
            str << s[i] << i;
            s[i] = str.str();
        }
        int result = 0;
        sort(s.begin(), s.end());
        result += check(s);
        while (next_permutation(s.begin(), s.end())) {
            result += check(s);
        }
        cout << result;
        cout << endl;
    }
}
