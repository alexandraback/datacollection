#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>

#define foreach(i,v) for(typeof(v.end())i=v.begin();i!=v.end();++i) 

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

int N, M, K;
char maze[22][22];
char tmaze[22][22];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

static inline
void test(queue< pair<int,int> >& q, int x, int y, int& ret)
{
    if (!maze[x][y]) {
        maze[x][y] = 1;
        q.push(make_pair(x, y));
        ret++;
    }
}

int count_reachable()
{
    int ret = 0;
    queue< pair<int, int> > q;
    for (int i = 1; i <= M; i++) {
        test(q, 1, i, ret);
        test(q, N, i, ret);
    }

    for (int i = 1; i <= N; i++) {
        test(q, i, 1, ret);
        test(q, i, M, ret);
    }

    while (!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
            test(q, f.first + dx[i], f.second + dy[i], ret);
    }

    return ret;
}

int main(int argc, const char* argv[])
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int pts;
        int best;
        cin >> N >> M >> K;

        memset(tmaze, 0, sizeof(tmaze));
        for (int i = 0; i < M+2; i++)
            tmaze[0][i] = tmaze[N+1][i] = 1;
        for (int i = 0; i < N+2; i++)
            tmaze[i][0] = tmaze[i][M+1] = 1;

        pts = N * M;
        best = N * M;
        for (int m = 1; m < (1 << pts); m++) {
            int tm = m;
            int count = 0;
            memcpy(maze, tmaze, sizeof(maze));

            while (tm) {
                int bit = __builtin_ctz(tm);
                maze[bit / M + 1][bit % M + 1] = 1;
                tm &= (tm - 1);
                count++;
            }

            if (count >= best)
                continue;
                
            if (pts - count_reachable() >= K)
               best = count; 
        }
        cout << "Case #" << t << ": " << best << endl;
    }
    return 0;
}
