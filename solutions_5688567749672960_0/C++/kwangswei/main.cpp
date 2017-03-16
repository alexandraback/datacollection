#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int cache[1000001] = {0,};

long long reverse(int N) {
    if (N % 10 == 0)
        return 0;
    string str = to_string(N);
    reverse(str.begin(), str.end());
    auto r = stol(str);

    if (N <= r)
        return 0;
    return r;
}

void pre() {
    memset(cache, 0, sizeof(cache));
    cache[0] = 987654321;
    cache[1] = 1;
    for (int i = 2; i < 1000001; ++i) {
        cache[i] = min(cache[i-1], cache[reverse(i)]) + 1;
    }
}

int main() {
    int T;
    cin >> T;

    pre();

    for (int i = 1; i <= T; ++i) {
        int N;
        cin >> N;
        printf("Case #%d: %d\n", i, cache[N]);
    }

    return 0;
}
