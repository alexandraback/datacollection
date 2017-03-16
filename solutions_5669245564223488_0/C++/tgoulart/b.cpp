#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void solveTestCase(int testCase);

int main(int argc, char *argv[]) {
    int T;
    cin >> T;
    for (int i=1; i <= T; ++i) {
        solveTestCase(i);
    }

	return 0;
}

// Code begins

#define UNUSED 0
#define CURRENT 1
#define USED 2

void solveTestCase(int testCase) {
    int N;
    cin >> N;

    vector <string> sets;
    vector <int> indices;

    for (int i=0; i < N; ++i) {
        string str;
        cin >> str;
        sets.push_back(str);
        indices.push_back(i);
    }

    int ans = 0;

    do {
        bool valid = true;

        string train = "";
        for (int i=0; i < indices.size(); ++i) {
            train += sets[indices[i]];
        }

        vector <int> state(27, UNUSED);
        char last = 27;
        for (int i=0; i < train.length(); ++i) {
            char now = train[i] - 'a';
            if (now != last) {
                state[last] = USED;
            }
            if (state[now] == USED) {
                goto SKIP;
            }
            state[now] = CURRENT;
            last = now;
        }
        ++ans;
    SKIP:;
    } while (next_permutation(indices.begin(), indices.end()));

    cout << "Case #" << testCase << ": " << ans << endl;
}
