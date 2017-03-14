// Google Code Jam 2012 Qualification Problem D: Hall of Mirrors

#include <cassert>
#include <cstring>
#include <set>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

static long long gcd(long long a, long long b)
{
    while (b)
    {
        long long c = a%b;
        a = b, b = c;
    }
    return a;
}

struct Fraction
{
    long long n, d;

    Fraction(long long nn = 0, long long dd = 1)
    {
        long long f = gcd(nn,dd);
        n = nn/f;
        d = dd/f;
    }
};

Fraction operator+(const Fraction &f, const Fraction &g) {
    return Fraction(f.n*g.d + f.d*g.n, f.d*g.d);
}

Fraction operator-(const Fraction &f, const Fraction &g) {
    return Fraction(f.n*g.d - f.d*g.n, f.d*g.d);
}

Fraction operator*(const Fraction &f, const Fraction &g) {
    return Fraction(f.n*g.n, f.d*g.d);
}

Fraction operator/(const Fraction &f, const Fraction &g) {
    return Fraction(f.n*g.d, f.d*g.n);
}

bool operator==(const Fraction &f, const Fraction &g) {
    return f.n*g.d == f.d*g.n;
}

bool operator<(const Fraction &f, const Fraction &g) {
    return f.n*g.d < f.d*g.n;
}

ostream &operator<< (ostream &os, const Fraction &f) {
    return os << f.n << '/' << f.d;
}


static const int S = 30;  // maximum grid size

static int D;
static char grid[S][S];
static int start_row, start_col;
static char G[4][S][S];  // rotated grids; indexed G[dir][y][x]
static Fraction Sx[4], Sy[4];   // rotated starting points

struct Segment
{
    Fraction x, y, dx, dy;
    int dir;   // chosen such that dx and dy are both positive
};

static Segment reflect_horizontal(const Segment &s)
{
    Segment res =  { s.y, S - s.x,
                     s.dy, s.dx, (s.dir + 1)%4 };
    return res;
}

static Segment reflect_vertical(const Segment &s)
{
    Segment res =  { S - s.y, s.x,
                     s.dy, s.dx, (s.dir + 3)%4 };
    return res;
}

static Segment reflect_back(const Segment &s)
{
    Segment res =  { S - s.x, S - s.y,
                     s.dx, s.dy, (s.dir + 2)%4 };
    return res;
}

/* Reduces segment `s' by ray-tracing until either dx == dy == 0 (in which
   case true is returned) or we hit a corner of a mirror (the ray is absorbed,
   and false is returend). */
static bool reduce(Segment &s)
{
    for (;;)
    {
        // dx and dy are positive fractions
        assert(s.dx.n > 0 && s.dx.d > 0);
        assert(s.dy.n > 0 && s.dy.d > 0);

        // find fraction of segment to traverse before we hit a horizontal/vertical wall:
        Fraction f = (Fraction(s.x.n/s.x.d + 1) - s.x)/s.dx;
        Fraction g = (Fraction(s.y.n/s.y.d + 1) - s.y)/s.dy;
        if (f.n >= f.d && g.n >= g.d)
        {
            s.x = s.x + s.dx;
            s.y = s.y + s.dy;
            s.dx = 0;
            s.dy = 0;
            return true;
        }

        if (f < g)  // hit a vertical grid line
        {
            s.x = s.x + f*s.dx;
            s.y = s.y + f*s.dy;
            s.dx = s.dx - f*s.dx;
            s.dy = s.dy - f*s.dy;
            assert(s.x.d == 1);
            if (G[s.dir][s.y.n/s.y.d][s.x.n] == '#')
            {
                s = reflect_horizontal(s);
            }
        }
        else
        if (g < f)  // hit a horizontal grid line
        {
            s.x = s.x + g*s.dx;
            s.y = s.y + g*s.dy;
            s.dx = s.dx - g*s.dx;
            s.dy = s.dy - g*s.dy;
            assert(s.y.d == 1);
            if (G[s.dir][s.y.n][s.x.n/s.x.d] == '#')
            {
                s = reflect_vertical(s);
            }
        }
        else  // hit a corner
        {
            assert(f == g);
            s.x = s.x + f*s.dx;
            s.y = s.y + f*s.dy;
            s.dx = s.dx - f*s.dx;
            s.dy = s.dy - f*s.dy;
            assert(s.x.d == 1 && s.y.d == 1);
            if (G[s.dir][s.y.n][s.x.n] == '#')
            {
                bool h = G[s.dir][s.y.n - 1][s.x.n    ] == '#';
                bool v = G[s.dir][s.y.n    ][s.x.n - 1] == '#';

                if (h && !v)
                {
                    s = reflect_horizontal(s);
                }
                else
                if (v && !h)
                {
                    s = reflect_vertical(s);
                }
                else
                if (h && v)
                {
                    assert(v && h);
                    s = reflect_back(s);
                }
                else
                {
                    assert(!h && !v);
                    return false;
                }
            }
        }
    }
}

static void find_start()
{
    for (int r = 0; r < S; ++r)
    {
        for (int c = 0; c < S; ++c)
        {
            if (grid[r][c] == 'X')
            {
                grid[r][c] = '.';
                start_row = r;
                start_col = c;
                return;
            }
        }
    }
    assert(0);
}

static int solve()
{
    // Find 'X' that marks the starting row/column (and remove it from the grid)
    find_start();

    // Computed rotated starting locations and grids:
    Sx[0] = Fraction(2*start_col + 1, 2);
    Sy[0] = Fraction(2*start_row + 1, 2);
    memcpy(G[0], grid, S*S);
    for (int dir = 1; dir < 4; ++dir)
    {
        Sx[dir] = Sy[dir - 1];
        Sy[dir] = S - Sx[dir - 1];
        for (int y = 0; y < S; ++y)
        {
            for (int x = 0; x < S; ++x)
            {
                G[dir][S - 1 - x][y] = G[dir - 1][y][x];
            }
        }
    }

    // Compute all possible paths:
    int res = 0;
    for (int dir = 0; dir < 4; ++dir)
    {
        // Cardinal direction:
        {
            int dx = 0;
            assert(G[dir][Sy[dir].n/Sy[dir].d][Sx[dir].n/Sx[dir].d] == '.');
            while (G[dir][Sy[dir].n/Sy[dir].d][Sx[dir].n/Sx[dir].d + dx] != '#') ++dx;
            if (2*dx - 1 <= D) ++res;
        }

        // Non-cardinal direction:
        set<Fraction> dirs;
        for (int dx = 1; dx < D; ++dx)
        {
            for (int dy = 1; dy < D; ++dy)
            {
                if (dx*dx + dy*dy > D*D) continue;
                Segment s = { Sx[dir], Sy[dir], dx, dy, dir };
                if (reduce(s))
                {
                    if (s.x == Sx[s.dir] && s.y == Sy[s.dir])
                    {
                        dirs.insert(Fraction(dx, dy));
                    }
                }
            }
        }
        res += dirs.size();
    }
    return res;
}

int main()
{
    int cases = 0;
    cin >> cases;
    for (int c = 1; c <= cases; ++c)
    {
        int H, W;
        cin >> H >> W >> D;
        assert(cin);
        assert(H <= S && W <= S);
        memset(grid, '#', sizeof(grid));
        for (int r = 0; r < H; ++r)
        {
            string s;
            cin >> s;
            assert(s.size() == (size_t)W);
            for (int c = 0; c < W; ++c) grid[r][c] = s[c];
        }
        cout << "Case #" << c << ": " << solve() << '\n';
    }
}
