#include <bits/stdc++.h>

using namespace std;

void solution();

int main()
{
    ios_base::sync_with_stdio(false);
#ifdef HOME
    freopen("C.in", "rt", stdin);
    clock_t start = clock();
#endif
    solution();
#ifdef HOME
    cerr.precision(3);
    cerr << endl << "Total time: " << fixed << double(clock() - start) / double(CLOCKS_PER_SEC) << endl;
#endif
    return 0;
}

typedef long long ll;
#define int ll

int J, P, S, K;

struct cloth
{
    int a, b, c;
    cloth(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
};

void solve()
{
    map<pair<int,int>, int> s[3];
    vector<cloth> answer;
    for (int i = 1; i <= J; ++i)
        for (int j = 1; j <= P; ++j)
            for (int k = 1; k <= S; ++k)
            {
                auto p12 = make_pair(i, j);
                auto p13 = make_pair(i, k);
                auto p23 = make_pair(j, k);
                if (s[0][p12] >= K) continue;
                if (s[1][p13] >= K) continue;
                if (s[2][p23] >= K) continue;
                s[0][p12] += 1;
                s[1][p13] += 1;
                s[2][p23] += 1;
                answer.emplace_back(i, j, k);
            }
    cout << answer.size() << endl;
    for (auto it : answer)
        cout << it.a << " " << it.b << " " << it.c << endl;
}

void solution()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cout << "Case #" << t + 1 << ": ";
        cin >> J >> P >> S >> K;
        solve();
    }
}
