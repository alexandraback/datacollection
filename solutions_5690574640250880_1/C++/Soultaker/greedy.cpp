#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

#define FOR(i,a,b)  for (int i = int(a); i <  int(b); ++i)
#define FORE(i,a,b) for (int i = int(a); i <= int(b); ++i)
#define REP(i,n)    FOR(i,0,n)

vector<string> solve(int H, int W, int mines)
{
    assert(mines < H*W);
    vector<string> grid(H, string(W, '.'));
    grid[0][0] = 'c';
    if (H == 1 || W == 1 || mines == H*W - 1 || mines == 0)
    {
        // Trivial solution.
        REP(r, H) REP(c, W) if (mines > 0) {
            grid[H - 1 - r][W - 1 - c] = '*';
            --mines;
        }
        assert(mines == 0);
        return grid;
    }

    FORE(h, 2, H) FORE(w, 2, W) {
        if (mines >= H*W - h*w && mines <= H*W - h*w + (h-2)*(w-2))
        {
            REP(r, H) REP(c, W) if (r >= h || c >= w) {
                grid[r][c] = '*';
                --mines;
            }
            assert(mines >= 0);
            REP(r, h - 2) REP(c, w - 2) if (mines > 0) {
                grid[h - 1 - r][w - 1 - c] = '*';
                --mines;
            }
            return grid;
        }
    }

    return vector<string>();  // no solution!
}

int main()
{
    int cases = 0;
    cin >> cases;
    for (int c = 1; c <= cases; ++c)
    {
        cout << "Case #" << c << ":\n";
        int H = 0, W = 0, M  = 0;
        cin >> H >> W >> M;
        vector<string> solution = solve(H, W, M);
        if (solution.empty())
        {
            cout << "Impossible" << endl;
        }
        else
        {
            REP(r, H) cout << solution[r] << endl;

            // Sanity check solution:
            int m = 0;
            REP(r, H) REP(c, W) if (solution[r][c] == '*') ++m;
            assert(M == m);
        }
    }
}
