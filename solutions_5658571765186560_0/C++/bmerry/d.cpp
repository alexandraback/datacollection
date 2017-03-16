#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

/*** START OF TEMPLATE CODE ***/

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())

template<class T>
vector<T> splitstr(const string &s)
{
    istringstream in(s);
    vector<T> out;
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
    return out;
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

    ios::sync_with_stdio(false);
    cin.exceptions(ios::failbit | ios::badbit);
}

/*** END OF TEMPLATE CODE ***/

typedef vector<pii> omino;

static const int dr[4] = {0, 0, -1, 1};
static const int dc[4] = {-1, 1, 0, 0};

static vector<omino> make_ominoes(int X)
{
    if (X == 1)
    {
        return vector<omino>{omino{{0, 0}}};
    }
    else
    {
        vector<omino> sub = make_ominoes(X - 1);
        vector<omino> out;
        for (const omino &s : sub)
        {
            for (const pii &pos : s)
            {
                for (int d = 0; d < 4; d++)
                {
                    pii add{pos.first + dr[d], pos.second + dc[d]};
                    if (!count(RA(s), add))
                    {
                        omino n = s;
                        n.push_back(add);
                        if (add.first == -1)
                        {
                            for (pii &npos : n)
                                npos.first++;
                        }
                        if (add.second == -1)
                        {
                            for (pii &npos : n)
                                npos.second++;
                        }
                        sort(RA(n));
                        out.push_back(n);
                    }
                }
            }
        }
        sort(RA(out));
        out.resize(unique(RA(out)) - out.begin());
        return out;
    }
}

static int dfs(vector<vector<bool> > &grid, int r, int c)
{
    int ans = 1;
    grid[r][c] = true;
    for (int d = 0; d < 4; d++)
    {
        int r2 = r + dr[d];
        int c2 = c + dc[d];
        if (r2 >= 0 && r2 < SZ(grid) && c2 >= 0 && c2 < SZ(grid[0])
            && !grid[r2][c2])
            ans += dfs(grid, r2, c2);
    }
    return ans;
}

static bool fits(const omino &g, int R, int C)
{
    int gR = 0;
    int gC = 0;
    for (const pii &pos : g)
    {
        gR = max(gR, pos.first + 1);
        gC = max(gC, pos.second + 1);
    }
    for (int r = 0; r <= R - gR; r++)
        for (int c = 0; c <= C - gC; c++)
        {
            vector<vector<bool> > grid(R, vector<bool>(C));
            for (const pii &pos : g)
                grid[pos.first + r][pos.second + c] = true;
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    if (!grid[i][j])
                    {
                        if (dfs(grid, i, j) % SZ(g) != 0)
                            goto bad;
                    }
            return true;
bad:;
        }
    return false;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int X, R, C;
        cin >> X >> R >> C;
        bool answer = false;
        if (X <= 6 && R * C % X == 0 && X <= max(R, C))
        {
            auto ominoes = make_ominoes(X);
            for (const omino &g : ominoes)
            {
                if (!fits(g, R, C) && !fits(g, C, R))
                    goto found;
            }
            answer = true;
found:;
        }
        cout << "Case #" << cas + 1 << ": " << (answer ? "GABRIEL" : "RICHARD") << "\n";
    }
    return 0;
}
