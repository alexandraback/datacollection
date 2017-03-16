#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cstring>
#include <ctime>
#include <cassert>

#define REP(k,a) for(int k = 0; k < (a); ++k)
#define FOR(k,a,b) for(int k=(a); k < (b); ++k)
#define FRE(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define SZ(x) ((int)((x).size()))
#define ALL(c) (c).begin(), (c).end()
#define CLR(c) memset((c), 0, sizeof(c))
#define VCLR(v) fill((v).begin(), (v).end(), 0)
#define PB push_back
#define MP make_pair
#define DBG(x) std::cerr << #x" = " << x << std::endl
#define I1 first
#define I2 second

const int INF = 1000000000;

using namespace std;

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<vector<double> > VVD;
typedef vector<string> VS;
typedef pair<int,int> II;
typedef vector<pair<int,int> > VII;
typedef long long LL;
typedef long double LD;

VVI board;
int visited[21][21];

bool covers(int mask, int N, int M, int K)
{
    if (__builtin_popcount(mask) >= K)
        return true;

    board = VVI(N, VI(M));

    for (int i = 0; i < N * M; ++i)
    {
        if (mask & 1 << i)
        {
            board[i / M][i % M] = 1;
        }
    }

    int cnt = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j])
            {
                ++cnt;
                continue;
            }

            CLR(visited);

            queue<II> q;
            q.push(II(i, j));
            // map<II, bool> visited;
            visited[i][j] = true;

            bool exited = false;
            while (!q.empty())
            {
                II top = q.front(); q.pop();
                if (top.I1 == 0 || top.I1 == N-1 || top.I2 == 0 || top.I2 == M-1)
                {
                    exited = true;
                    break;
                }

                int dx[] = {1, 0, -1, 0};
                int dy[] = {0, 1, 0, -1};

                REP(i, 4)
                {
                    int nx = top.I1 + dx[i];
                    int ny = top.I2 + dy[i];
                    II next = II(nx, ny);
                    if (!visited[nx][ny] && !board[nx][ny])
                    {
                        q.push(next);
                    }

                    visited[nx][ny] = true;
                }
            }

            cnt += !exited;
        }
    }

    return cnt >= K;
}

int memo[21][21][21];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    CLR(memo);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int N, M, K;
        cin >> N >> M >> K;

        cout << "Case #" << t+1 << ": ";

        if (memo[N][M][K])
        {
            cout << memo[N][M][K] << endl;
            continue;
        }

        int min_cover = INF;

        REP(mask, 1 << (N*M))
        {
            if (covers(mask, N, M, K))
            {
                min_cover = min(min_cover, __builtin_popcount(mask));
            }
        }

        memo[N][M][K] = memo[M][N][K] = min_cover;
        cout << min_cover << endl;
    }

    return 0;
}
