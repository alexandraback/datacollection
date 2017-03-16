#include <bits/stdc++.h>
using namespace std;

long long reverse(long long N)
{
    long long r = 0;
    while (N)
    {
        int digit = N % 10;
        N /= 10;
        r *= 10;
        r += digit;
    }
    return r;
}

struct State
{
    long long n, d;
};

const long long INF = 10000000000000000;

long long solve(long long N)
{
    vector<bool> seen(10*N, false);
    queue<State> q;
    q.push({1, 1});

    while (true)
    {
        State next = q.front(); q.pop();
        if (next.n == N) return next.d;
        if (seen[next.n]) continue;
        else seen[next.n] = true;

        q.push({next.n + 1, next.d + 1});
        q.push({reverse(next.n), next.d + 1});
    }
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        long long N; cin >> N;
        printf("Case #%d: %lld\n", t, solve(N));
    }
    return 0;
}
