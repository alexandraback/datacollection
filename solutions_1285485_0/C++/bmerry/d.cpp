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

static int roundup(int x, int m)
{
    assert(m > 0);
    return (x + m - 1) / m * m;
}

static int gcd(int a, int b ) { return b ? gcd(b, a % b) : a; }

static bool get(const vs &grid, int r, int c)
{
    assert(r >= 0 && r < SZ(grid) && c >= 0 && c < SZ(grid[r]));
    return grid[r][c] == '#';
}

static const int deltar[4] = {-1, 0, 1, 0};
static const int deltac[4] = {0, -1, 0, 1};

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int H, W, D;
        cin >> H >> W >> D;
        int sr = -1, sc = -1;
        vs grid(H);
        for (int i = 0; i < H; i++)
        {
            cin >> grid[i];
            for (int j = 0; j < W; j++)
                if (grid[i][j] == 'X')
                {
                    grid[i][j] = '.';
                    sr = i;
                    sc = j;
                }
        }
        assert(sr != -1);

        set<pair<int, int> > good;

        int ans = 0;
        for (int dir = 0; dir < 4; dir++)
        {
            int r = sr;
            int c = sc;
            int dist = 0;
            while (grid[r][c] != '#')
            {
                r += deltar[dir];
                c += deltac[dir];
                dist++;
            }
            if (dist * 2 - 1 <= D)
                ans++;
        }

        sr = 2 * sr + 1;
        sc = 2 * sc + 1;
        D *= 2;
        for (int tr = sr - D; tr <= sr + D; tr++)
            for (int tc = sc - D; tc <= sc + D; tc++)
            {
                int dr = tr - sr;
                int dc = tc - sc;
                int adr = abs(dr);
                int adc = abs(dc);
                int scale = adr * adc;
                if (scale > 0 && adr * adr + adc * adc <= D * D)
                {
                    int beginr = sr * scale;
                    int beginc = sc * scale;
                    int endr = beginr;
                    int endc = beginc;
                    int stepr = dr;
                    int stepc = dc;
                    int t = 0;
                    int T = scale;
                    while (true)
                    {
                        int nextr = roundup(t + adr + 1, 2 * adr) - adr;
                        int nextc = roundup(t + adc + 1, 2 * adc) - adc;
                        t = min(nextr, nextc);
                        if (t >= T)
                            break;
                        int r = beginr + t * stepr;
                        int c = beginc + t * stepc;
                        bool to = get(grid, (r + stepr) / (2 * scale), (c + stepc) / (2 * scale));
                        if (to)
                        {
                            bool hflip = false, vflip = false, kill = false;
                            if (nextr < nextc) // vertical edge
                                hflip = true;
                            else if (nextr > nextc) // horizontal edge
                                vflip = true;
                            else // corner
                            {
                                hflip = get(grid, (r - stepr) / (2 * scale), (c + stepc) / (2 * scale));
                                vflip = get(grid, (r + stepr) / (2 * scale), (c - stepc) / (2 * scale));
                                if (!hflip && !vflip)
                                    kill = true;
                            }

                            if (kill)
                                break;
                            if (hflip)
                            {
                                beginc = 2 * c - beginc;
                                stepc = -stepc;
                            }
                            if (vflip)
                            {
                                beginr = 2 * r - beginr;
                                stepr = -stepr;
                            }
                        }
                    }
                    if (t >= T)
                    {
                        int r = beginr + T * stepr;
                        int c = beginc + T * stepc;
                        if (r == endr && c == endc)
                        {
                            int g = gcd(adr, adc);
                            good.insert(pii(dr / g, dc / g));
                        }
                    }
                }
            }
        ans += good.size();

        printf("Case #%d: %d\n", cas + 1, ans);
    }
    return 0;
}
