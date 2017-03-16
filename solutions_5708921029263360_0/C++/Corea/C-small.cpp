#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int J, P, S, K;

vector<int> pairs;
vector<int> best;

int JP[13][13];
int PS[13][13];
int JS[13][13];

void get_pair() {
    pairs.clear();
    for (int i = 1; i <= J; i ++) {
        for (int j = 1; j <= P; j ++) {
            for (int k = 1; k <= S; k ++) {
                pairs.push_back(i * 100 + j * 10 + k);
            }
        }
    }
}

void dfs(int now, vector<int> &status) {
    if (now >= pairs.size()) {
        if (status.size() > best.size()) {
            best.clear();
            for (auto &v : status) {
                best.push_back(v);
            }
        }
        return;
    }

    dfs(now + 1, status);
    int j = pairs[now] / 100;
    int p = (pairs[now] / 10) % 10;
    int s = pairs[now] % 10;

    if (JP[j][p] != K && JS[j][s] != K && PS[p][s] != K) {
        JP[j][p] ++;
        JS[j][s] ++;
        PS[p][s] ++;
        status.push_back(pairs[now]);

        dfs(now + 1, status);

        status.pop_back();
        JP[j][p] --;
        JS[j][s] --;
        PS[p][s] --;
    }
}

int main() {
    int T;
    scanf( "%d", &T );
    for (int test = 1; test <= T; test ++) {
        scanf( "%d %d %d %d", &J, &P, &S, &K );

        get_pair();
        vector<int> x;
        dfs(0, x);
        printf( "Case #%d: %d\n", test, (int)best.size());
        for (auto &v : best) {
            printf( "%d %d %d\n", v / 100, (v / 10) % 10, v % 10 );
        }
        best.clear();
    }

    return 0;
}
