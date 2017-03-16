#include <bits/stdc++.h>
using namespace std;

int TC, dist[1000005];
queue< pair<int, int> > Q;

int reverse(int x) {
    string S = "";
    while (x > 0) {
        S += (x % 10) + '0';
        x /= 10;
    }
    int ans = 0;
    for (int i = 0; i < S.length(); i++) {
        ans *= 10;
        ans += S[i] - '0';
    }
    return ans;
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    scanf("%d", &TC);
    Q.push(make_pair(1, 0));
    memset(dist, -1, sizeof(dist));
    while (!Q.empty()) {
        int x = Q.front().first, distance = Q.front().second;
        Q.pop();
        if (dist[x] != -1) continue;
        else dist[x] = distance;
        int opt1 = x+1;
        int opt2 = reverse(x);
        if (dist[opt1] == -1 && opt1 <= 1000000) Q.push(make_pair(opt1, distance+1));
        if (dist[opt2] == -1 && opt2 <= 1000000) Q.push(make_pair(opt2, distance+1));
    }
    for (int tc = 1; tc <= TC; tc++) {
        long long x;
        scanf("%lld", &x);
        printf("Case #%d: %d\n", tc, dist[x]+1);
    }
}
