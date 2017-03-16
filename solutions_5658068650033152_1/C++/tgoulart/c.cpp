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

int stonesForGap(int i, int j) {
    return i * 2 + j * 2;
}

int enclosedByGap(int i, int j) {
    return i * j + stonesForGap(i, j);
}

void solveTestCase(int testCase) {
    int N, M, K;
    cin >> N >> M >> K;

    if (N > M) {
        swap(N, M);
    }

    cout << "Case #" << testCase << ": ";

    if (N <= 2) {
        cout << K << endl;
        return;
    }
    if (K <= 4) {
        cout << K << endl;
        return;
    }

    int i = 1;
    int j = 1;
    int deltaStones = 0;

    while ((i < N - 2 || j < M - 2) && enclosedByGap(i, j) < K) {
        if (i < j && i < N - 2) {
            ++i;
        } else {
            ++j;
        }
    }

    if (i > j) {
        swap(i, j);
    }

    if (K > enclosedByGap(i, j)) {
        deltaStones = K - enclosedByGap(i, j);
    } else {
        int deltaCovered = 0;
        for (int iter=0; iter < 4; ++iter) {
            if (enclosedByGap(i, j) + deltaCovered - 2 >= K) {
                deltaStones -= 1;
                deltaCovered -= 2;
            }
        }
    }

DONE:
    cout << (stonesForGap(i, j) + deltaStones) << endl;
}
