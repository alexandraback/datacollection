#include <iostream>
using namespace std;

#define MAXN 16

int v[MAXN], E, R, N, BEST;

void dfs(int cur, int cure, int curv) {
    if (cur == N) BEST = max(BEST, curv);
    else {
        for (int i=0; i<=cure; i++) dfs(cur+1, min(E, cure-i+R), curv+i*v[cur]);
    }
}

int main() {
    int T, t, i;

    cin >> T;
    for (t=1; t<=T; t++) {
        cin >> E >> R >> N;
        for (i=0; i<N; i++) cin >> v[i];
        BEST = 0;
        dfs(0, E, 0);
        cout << "Case #" << t << ": " << BEST << endl;
    }

    return 0;
}
