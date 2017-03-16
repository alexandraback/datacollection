#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>

using namespace std;

typedef long long ll;

//#define LARGE

int N;
int M[10];
vector<int> v[1000];
bool dp[1000][1000];
set<int> can;

bool func(int n){
    for (int i = 0; i < N; i++){
        if (i == n) continue;
        if (dp[n][i]){
//            printf("n : %d i : %d\n", n + 1, i + 1);
            if (can.find(i) != can.end()) return true;
//            printf("insert %d\n", i + 1);
            can.insert(i);
            if (func(i)) return true;
        }
    }
    return false;
}

bool solve(){
    for (int i = 0; i < N; i++){
        fill(dp[i], dp[i] + N, false);
    }
    for (int i = 0; i < N; i++){
        vector<int> vv = v[i];
        for (int j = 0; j < vv.size(); j++){
            dp[i][vv[j]] = true;
        }
    }
    for (int i = 0; i < N; i++){
        can.clear();
//        printf("i = %d\n", i + 1);
        if (func(i)) return true;
//        printf("\n", i);
    }

    return false;
}

int main() {
#ifdef LARGE
    FILE *in = fopen("A-large.in", "r");
    FILE *out = fopen("A-large.out", "w");
#else
    FILE *in = fopen("A-small-attempt0.in", "r");
    FILE *out = fopen("A-small-attempt0.out", "w");
#endif
    int T;
    fscanf(in, "%d", &T);
    for (int t = 0; t < T; t++) {
        printf("t : %d\n", t);
        fscanf(in, "%d", &N);
        for (int n = 0; n < N; n++) {
            int M;
            fscanf(in, "%d", &M);
            v[n].clear();
            for (int m = 0; m < M; m++) {
                int to;
                fscanf(in, "%d", &to);
                v[n].push_back(to - 1);
            }
        }
        fprintf(out, "Case #%d: %s\n", t + 1, solve() ? "Yes" : "No");
    }
    fclose(in);
    fclose(out);
    return 0;
}
