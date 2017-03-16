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

const int MAXN = 100 + 10;

int kOfTest, N, M;
int ttoy[MAXN], tbox[MAXN], p[MAXN];
long long kbox[MAXN], ktoy[MAXN], cbox[MAXN], ctoy[MAXN];
long long result;

void calc (int pos, int last) {
    if(pos == N - 1) {
        for(int j = 0; j < N; ++j)
            cbox[j] = kbox[j];
        for(int j = 0; j < M; ++j)
            ctoy[j] = ktoy[j];
        long long col = 0;
        for(int i = 0; i < N; ++i) {
            int left = 0;
            int right = M - 1;
            if(i < N - 1)
                right = p[i];
            if(i > 0)
                left = p[i - 1];
            for(int j = left; j <= right; ++j) {
                if(ttoy[j] != tbox[i]) continue;
                long long value = min(ctoy[j], cbox[i]);
                col += value;
                ctoy[j] -= value;
                cbox[i] -= value;
            }
        }

        result = max(result, col);

        return;
    }
    for(int pp = last; pp < M; ++pp) {
        p[pos] = pp;
        calc (pos + 1, pp);
        p[pos] = 0;
    }    
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> kOfTest;

    for(int iTest = 1; iTest <= kOfTest; ++iTest) {
        cin >> N >> M;

        for(int i = 0; i < N; ++i)
            cin >> kbox[i] >> tbox[i];

        for(int i = 0; i < M; ++i)
            cin >> ktoy[i] >> ttoy[i];

        // #Small
        result = 0;
        calc (0, 0);

        cout << "Case #" << iTest << ": " << result << endl;
    }

    return 0;
}

