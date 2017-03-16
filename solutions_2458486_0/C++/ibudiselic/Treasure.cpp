#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

const int MAXKEYS = 200;
vector<int> K;
vector<int> need;
vector< vector<int> > get;
int n;

bool done[1<<20];
bool dp[1<<20];
int pick[1<<20];
bool can(int used) {
    if (done[used]) {
        return dp[used];
    }
    done[used] = 1;
    if (used == (1<<n)-1) {
        dp[used] = true;
    } else {
        pick[used] = -1;
        for (int i=0; i<n; ++i) {
            if (used & (1<<i)) continue;
            if (K[need[i]] == 0) continue;
            --K[need[i]];
            for (int j=0; j<(int)get[i].size(); ++j) {
                ++K[get[i][j]];
            }
            if (can(used | (1<<i))) {
                pick[used] = i;
            }
            ++K[need[i]];
            for (int j=0; j<(int)get[i].size(); ++j) {
                --K[get[i][j]];
            }
            if (pick[used] != -1) {
                break;
            }
        }
        dp[used] = (pick[used] != -1);
    }
    return dp[used];
}
int main() {
    cin.sync_with_stdio(false);
    int ncases;
    scanf("%d", &ncases);
    for (int testcase=1; testcase<=ncases; ++testcase) {
        int startkeys;
        scanf("%d %d", &startkeys, &n);
        K.assign(MAXKEYS, 0);
        for (int i=0; i<startkeys; ++i) {
            int k;
            scanf("%d", &k);
            ++K[k-1];
        }
        need.clear();
        get.clear();
        for (int i=0; i<n; ++i) {
            int x, keys;
            scanf("%d %d", &x, &keys);
            need.push_back(x-1);
            vector<int> g;
            for (int j=0; j<keys; ++j) {
                scanf("%d", &x);
                g.push_back(x-1);
            }
            get.push_back(g);
        }

        memset(done, 0, sizeof done);
        if (!can(0)) {
            printf("Case #%d: IMPOSSIBLE\n", testcase);
        } else {
            printf("Case #%d:", testcase);
            int used = 0;
            for (int i=0; i<n; ++i) {
                printf(" %d", pick[used]+1);
                used |= 1<<pick[used];
            }
            putchar('\n');
        }
    }
	return 0;
}
