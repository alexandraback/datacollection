/*
  ID: nigo1
  LANG: C++
  TASK: B
*/
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <stack>

#define TIME printf("%f", (double)clock()/CLOCKS_PER_SEC);

using namespace std;

int T;

int N, M, H;
int C[128][128];
int F[128][128];

double can_enter[128][128];
double drag[128][128];

typedef pair <double, pair <int, int> > dii;
set < dii > s;

bool used[128][128];

int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

double solve() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (C[i][j] - 50 >= H)
                can_enter[i][j] = 0.0;
            else {
                can_enter[i][j] = (double)(H - C[i][j] + 50)/10.0;
            }
        }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (F[i][j] + 20 >= H)
                drag[i][j] = 0.0;
            else {
                drag[i][j] = (double)(H - F[i][j] - 20)/10.0;
            }
        }

    s.clear();
    memset (used, 0, sizeof used);

    s.insert ( make_pair (0, make_pair (0, 0)) );

    while (!s.empty()) {
        dii n = *s.begin();
        s.erase(s.begin());

        if (n.second.first == N - 1 and n.second.second == M - 1) return n.first;

        double t = n.first;
        int x = n.second.first;
        int y = n.second.second;
        double water_level = H - t*10;


        if (used[x][y]) continue;
        used[x][y] = 1;

        //cout << t << " " << water_level << " " << x + 1 << " " << y + 1<< endl;
        if (water_level < 1e-9) water_level = 0;

        for (int i = 0; i < 4; i++) {
            int newx = x + moves[i][0], newy = y + moves[i][1];

            if (newx < 0 or newx >= N) continue;
            if (newy < 0 or newy >= M) continue;

            if (used[newx][newy]) continue;

            if (!(F[x][y] + 50.0 - (double)C[newx][newy] < 1e-9)) continue;
            if (!(F[newx][newy] + 50.0 - (double)C[newx][newy] < 1e-9)) continue;
            if (!(F[newx][newy] + 50.0 - (double)C[x][y] < 1e-9)) continue;

            if (t < 1e-9 and can_enter[newx][newy] < 1e-9) {
                s.insert (make_pair (can_enter[newx][newy], make_pair (newx, newy)));
                continue;
            }

            if (drag[x][y] < t) {
                s.insert (make_pair (max (t + 10.0, can_enter[newx][newy] + 10), make_pair (newx, newy)));
            } else {
                if (drag[x][y] > can_enter[newx][newy])
                    s.insert (make_pair (max (t, can_enter[newx][newy]) + 1, make_pair (newx, newy)));
                else
                    s.insert (make_pair (can_enter[newx][newy] + 10.0, make_pair (newx, newy)));
            }
        }
    }
    return -1;

}

int main()
{
	freopen ("B.in", "r", stdin);
	freopen ("B.out", "w", stdout);

	scanf ("%d", &T);

	for (int test = 1; test <= T; test++) {
        printf ("Case #%d: ", test);

        scanf ("%d%d%d", &H, &N, &M);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf ("%d", &C[i][j]);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf ("%d", &F[i][j]);

        double ans = solve();
       // cout << can_enter[N - 1][M - 1] << " ";
        printf ("%lf\n", ans);
	}


    return 0;
}
