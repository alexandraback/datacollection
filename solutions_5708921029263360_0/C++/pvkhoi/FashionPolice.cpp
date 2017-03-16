#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(a) int(a.size())

struct tp {
    int x, y, z;
    tp(int _x = 0, int _y = 0, int _z = 0) : x(_x), y(_y), z(_z) {}
};

int bestMask, maxDay;
int cnt[33][33];
vector <tp> A;
int J, P, S, K;

void dq(int pos, int mask, int cur) {
    if (pos == sz(A)) {
        if (cur > maxDay) {
            maxDay = cur;
            bestMask = mask;
        }
        return;
    }
    dq(pos+1, mask, cur);
    tp u = A[pos];
    if (cnt[u.x][u.y+J]+1 <= K && cnt[u.x][u.z+J+P]+1 <= K && cnt[u.y+J][u.z+J+P]+1 <= K) {
        cnt[u.x][u.y+J]++;
        cnt[u.x][u.z+J+P]++;
        cnt[u.y+J][u.z+J+P]++;
        dq(pos+1, mask | (1 << pos), cur+1);
        cnt[u.x][u.y+J]--;
        cnt[u.x][u.z+J+P]--;
        cnt[u.y+J][u.z+J+P]--;
    }
}

void solve() {
    memset(cnt, 0, sizeof cnt);
    bestMask = -1;
    maxDay = 0;
    A.clear();
    
    for (int x = 1; x <= J; x++)
    for (int y = 1; y <= P; y++)
    for (int z = 1; z <= S; z++)
        A.pb(tp(x, y, z));
//    cout << sz(A) << endl;
    dq(0, 0, 0);
    printf("%d\n", maxDay);
    for (int i = 0; i < sz(A); i++) {
        if ((1 << i) & bestMask) {
            printf("%d %d %d\n", A[i].x, A[i].y, A[i].z);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d%d%d%d", &J, &P, &S, &K);
        printf("Case #%d: ", t);
        solve();
    }
    
    return 0;
}
