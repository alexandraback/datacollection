#define y1 JulioCortasar
#define y2 GabrielGarsiaMarkes
#include <bits/stdc++.h>
#undef y1
#undef y2

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define pb push_back
#define mp make_pair
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef double lf;

const ll inf = 1e9 + 100500;

#define TASK_NAME "INSERT_TASK_NAME_HERE"
#define TASK_LETTER "a"

#define STANDART_INPUT

#ifdef LOCAL
void initrand()
{
    ll seed;
    asm("rdtsc":"=A"(seed));
    srand(seed);
}
#endif

const int maxn = 10000000;

int q[maxn + 1], dist[maxn + 1];

void precalc()
{
    int qh = 0, qt = 0;
    fill(dist, dist + maxn + 1, -1);
    q[qt++] = 1;
    dist[1] = 1;
    while (qh < qt)
    {
        int x = q[qh++];
        int y = 0;
        for (int t = x; t; y = y * 10 + t % 10, t /= 10);
        if (dist[y] == -1)
        {
            dist[y] = dist[x] + 1;
            q[qt++] = y;
        }
        if (x + 1 <= maxn && dist[x + 1] == -1)
        {
            dist[x + 1] = dist[x] + 1;
            q[qt++] = x + 1;
        }
    }
}

void solve()
{
    int x;
    cin >> x;
    cout << dist[x] << endl;
}

int main()
{
#ifdef LOCAL
    freopen(TASK_LETTER ".in", "r", stdin);
#else
#ifndef STANDART_INPUT
    freopen(TASK_NAME ".in", "r", stdin);
    freopen(TASK_NAME ".out", "w", stdout);
#endif
#endif
    int t;
    cin >> t;
    precalc();
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
#ifdef LOCAL
    cerr << "Time = " << clock() / 1000 << " ms." << endl;
#endif
	return 0;
}
