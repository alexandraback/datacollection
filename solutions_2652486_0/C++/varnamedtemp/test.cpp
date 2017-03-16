#include <iostream>
#include <cstdio>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <memory.h>
#include <bitset>
#include <time.h>

using namespace std;

#define ll long long

int N, M, K, R, A[10];
vector<vector<int> > s;

void solve(int n, vector<int> v) {
    if(n == N + 1) {
        int p = 1;
        for(int i = 1;i<=K;i++) {
            bool ok = false;
            for(int j = 0;j<1<<(v.size());j++) {
                int p = 1;
                for(int k = 0;k<N;k++) {
                    if(j & (1<<k)) {
                        p *= v[k];
                    }
                }
                if(p == A[i]) ok = true;
            }
            if(!ok) return;
        }
        s.push_back(v);
        return;
    }
    for(int i = 2;i<=M;i++) {
        v.push_back(i);
        solve(n + 1, v);
        v.pop_back();
    }
}

int main() {
    srand(time(NULL));
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    printf("Case #1:\n");
    int T;
    scanf("%d",&T);
    scanf("%d %d %d %d", &R, &N, &M, &K);
    for(int k = 0;k<R;k++) {
        s.clear();
        for(int i = 1;i<=K;i++) {
            scanf("%d",&A[i]);
        }
        vector<int> v;
        solve(1, v);

        int size = s.size();
        int idx = rand()%size;

        vector<int> res = s[idx];
        for(int i = 0;i<res.size();i++)
            printf("%d", res[i]);
        printf("\n");
    }
    return 0;
}
