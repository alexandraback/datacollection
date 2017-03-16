#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void redirect(int argc, const char **argv)
{
    if (argc > 1)
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) { perror(argv[1]); exit(1); }
        if (-1 == dup2(fd, 0)) { perror(argv[1]); exit(1); }
        if (-1 == close(fd)) { perror(argv[1]); exit(1); }
    }

    if (argc > 2)
    {
        int fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
        if (fd == -1) { perror(argv[2]); exit(1); }
        if (-1 == dup2(fd, 1)) { perror(argv[2]); exit(1); }
        if (-1 == close(fd)) { perror(argv[2]); exit(1); }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int R, C, M;
        cin >> R >> C >> M;
        int RC = R * C;
        printf("Case #%d:\n", cas + 1);
        for (ll mask = 0; mask < (1LL << RC); mask++)
        {
            if (__builtin_popcountll(mask) != M)
                continue;
            vector<vi> grid(R, vi(C));
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                {
                    if (mask & (1LL << (i * C + j)))
                    {
                        grid[i][j] -= 100;
                        for (int p = i - 1; p <= i + 1; p++)
                            for (int q = j - 1; q <= j + 1; q++)
                                if (p >= 0 && p < R && q >= 0 && q < C)
                                    grid[p][q]++;
                    }
                }
            int sr = -1, sc = -1;
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    if (grid[i][j] == 0)
                    {
                        sr = i;
                        sc = j;
                        break;
                    }
            if (sr == -1)
                for (int i = 0; i < R; i++)
                    for (int j = 0; j < C; j++)
                        if (grid[i][j] >= 0)
                        {
                            sr = i;
                            sc = j;
                            break;
                        }

            queue<int> q;
            q.push(sr);
            q.push(sc);
            grid[sr][sc] += 10;
            int op = 0;
            while (!q.empty())
            {
                int r = q.front(); q.pop();
                int c = q.front(); q.pop();
                op++;
                if (grid[r][c] == 10)
                {
                    for (int i = r - 1; i <= r + 1; i++)
                        for (int j = c - 1; j <= c + 1; j++)
                        {
                            if (i >= 0 && i < R && j >= 0 && j < C
                                && grid[i][j] >= 0 && grid[i][j] < 10)
                            {
                                grid[i][j] += 10;
                                q.push(i);
                                q.push(j);
                            }
                        }
                }
            }
            if (op + M == RC)
            {
                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C; j++)
                    {
                        if (grid[i][j] < 0)
                            putchar('*');
                        else if (i == sr && j == sc)
                            putchar('c');
                        else
                            putchar('.');
                    }
                    printf("\n");
                }
                goto done;
            }
        }
        printf("Impossible\n");
done:;
    }
    return 0;
}
