#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int cache[6][11]; // e, index
int E, R, N;
vector<int> v;

int rec(int e, int index) {
    if (index == N) return 0;
    if (index == N - 1) return (e * v[index]);
    if (cache[e][index] >= 0) return cache[e][index];
    int ans = 0;
    for (int i = 0; i <= e; i++) {
        ans = max(ans, rec(min(E, e - i + R), index + 1) + i * v[index]);
    }
    return cache[e][index] = ans;
}

void init() {
    memset(cache, -1, sizeof(cache));
}

int solve() {
    cin >> E >> R >> N;
    v = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    init();
    return rec(E, 0);
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
