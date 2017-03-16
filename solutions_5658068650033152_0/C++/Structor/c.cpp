#include <algorithm>
#include <iostream>

using namespace std;

struct Grid
{
    Grid(int n, int m, int k) : n(n), m(m), k(k)
    {
        total = n*m;
        int empty = total - k;
        for (int i = 0; i < empty; ++i)
            grid[i] = 0;
        for (int i = empty; i < total; ++i)
            grid[i] = 1;
    }

    bool next_comb()
    {
        return next_permutation(grid, grid + total);
    }

    bool need_stone(int i)
    {
        if (grid[i] == 0)
            return false;
        int x = i % n;
        int y = i / n;
        if ((x == 0) || (x == (n - 1)))
            return true;
        if ((y == 0) || (y == (m - 1)))
            return true;
        int left = i - 1;
        if (grid[left] == 0)
            return true;
        int right = i + 1;
        if (grid[right] == 0)
            return true;
        int top = i - n;
        if (grid[top] == 0)
            return true;
        int bottom = i + n;
        if (grid[bottom] == 0)
            return true;
        return false;
    }

    int min_number()
    {
        int ret = 0;
        for (int i = 0; i < total; ++i)
        {
            if (need_stone(i))
                ++ret;
        }
        return ret;
    }

    int n;
    int m;
    int k;
    int total;
    unsigned char grid[30];
};

int solve()
{
    int N, M, K;
    cin >> N >> M >> K;

    /*
    if (K <= 4)
        return K;

    if ((K == 5) && (N >= 2) && (M >= 2))
        return 4;
    */
    Grid grid(N, M, K);
    int best = N*M;
    do
    {
        int act = grid.min_number();
        if (act < best)
            best = act;
    } while (grid.next_comb());
    return best;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}