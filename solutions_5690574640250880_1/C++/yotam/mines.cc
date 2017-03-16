// CodeJam
// Author:  Yotam Medini  yotam.medini@gmail.com -- Created: 2013/April/20

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

class Problem
{
 public:
    Problem(istream& fi);
    void solve();
    void print_solution(ostream&);
    bool is_possible() const { return possible; }

 private:
    void solve_side_rows();
    void solve_side_cols();
    void solve_side_3cols();
    void solve_greedy();
    void solve_greedy_wh(unsigned w, unsigned h);
    bool possible;
    unsigned R, C, M;

    // side solve
    unsigned whole_mine_rows;
    unsigned whole_mine_cols;
    unsigned residue;

    bool transpose;
    char grid[50][50]; // fits maximal grid
};

Problem::Problem(istream& fi) :
    possible(false)
{
    fi >> R >> C >> M;
    memset(grid, '.', sizeof(grid));
    transpose = (R < C);
    if (transpose)
    {
        unsigned t = R; R = C; C = t;
    }
}

void Problem::solve()
{
    whole_mine_rows = M / C;
    residue = M % C;
    if ((M == 0) || (M == R*C - 1))
    {
        possible = true;
    }
    else if (C == 1)
    {
        possible = M <= R - 2;
    }
    else if (C == 2)
    {
        possible = (M % 2 == 0) and M <= 2*(R - 2);
    }

    if (possible)
    {
        solve_side_rows();
    }
    else if (R >= 3)
    {
        whole_mine_cols = M / R;
        residue = M % R;
        if (((whole_mine_cols + 2 < C ) && (residue + 2 <= R)) ||
            (whole_mine_cols + 3 < C) ||
            ((whole_mine_cols + 2 == C) && (residue == 0)))
        {
            possible = true;
            solve_side_cols();
        }
    }

    if (!possible && (C >= 2) && (R*C - M < 3*R))
    {
         solve_side_3cols();
    }

    if (!possible)
    {
        if (M >= 9) { solve_greedy(); }
    }
}

void Problem::solve_side_rows()
{
    unsigned r;

    grid[0][0] = 'c';
    r = R;
    while (r > R - whole_mine_rows)
    {
        --r;
        for (unsigned c = 0; c < C; ++c)
        {
            grid[r][c] = '*';
        }
    }
    --r;
    for (unsigned c = C - 1; c > C - 1 - residue; --c)
    {
        grid[r][c] = '*';
    }
}

void Problem::solve_side_cols()
{
    unsigned c;

    grid[0][0] = 'c';
    c = C;
    while (c > C - whole_mine_cols)
    {
        --c;
        for (unsigned r = 0; r < R; ++r)
        {
            grid[r][c] = '*';
        }
    }
    --c;
    unsigned re = R - 1 - residue;
    unsigned residue_near = R - residue;
    if (residue_near == 1)
    { // leave at least 2 non-mine cells in residue-column
        ++re;
        grid[R-1][c - 1] = '*'; // single mine on another column
    }
    for (unsigned r = R - 1; r > re; --r)
    {
        grid[r][c] = '*';
    }
    
}

void Problem::solve_side_3cols()
{
    int non_mines = R*C - M;
    int nmh_begin = min((int)R, non_mines/2);
    int nmh_end = max(2, non_mines/3);
    for (int nmh = nmh_begin; !possible && nmh >= nmh_end; --nmh)
    {
        int nmr = non_mines - 2*nmh;
        possible = (nmr <= nmh) && (nmr != 1) && ((nmr == 0) || (C >= 3));
        if (possible)
        {
            memset(grid, '*', sizeof(grid));
            for (int r = 0; r < nmh; ++r)
            {
                grid[r][0] = grid[r][1] = '.';
            }
            for (int r = 0; r < nmr; ++r)
            {
                grid[r][2] = '.';
            }
            grid[0][0] = 'c';
        }
    }
}

void Problem::solve_greedy()
{
    // Here we start as if default starts with all mines.
    for (unsigned w = 3; !possible && (w <= C - 2); ++w)
    {
        unsigned h0 = (R * C - M) / w;
        unsigned hlow = max(h0 - 1, (unsigned)3);
        unsigned hhigh = min(h0, R - 2);
        for (unsigned h = hlow; !possible && (h <= hhigh); ++h)
        {
            solve_greedy_wh(w, h);
        }
    }
}

void Problem::solve_greedy_wh(unsigned w, unsigned h)
{
    unsigned more_needed = (R*C - M) - w*h;
    unsigned can_add = 0, can_add_h = 0, can_add_w = 0;
    unsigned add_h = 0, add_w = 0;

    if (w < C - 2) { can_add_h = h; }
    if (h < R - 2) { can_add_w = w; }
    can_add = can_add_h + can_add_w;
    if ((w < C - 2) && (h < R - 2))
    {
        ++can_add;
    }

    if ((more_needed >= 3) && (more_needed <= can_add))
    {
        if (more_needed <= can_add_h)
        {
            add_h = more_needed;
            possible = true;
        }
        else if (more_needed <= can_add_w)
        {
            add_w = more_needed;
            possible = true;
        }
        else
        {
            // We may assume  can_add_w, can_add_h >= 3
            if (more_needed >= 6)
            {
                if (can_add_h > can_add_w)
                {
                    add_h = max(can_add_h, more_needed - 3);
                    add_w = more_needed - add_h;
                    possible = add_w >= 3;
                }
                else
                {
                    add_w = max(can_add_w, more_needed - 3);
                    add_h = more_needed - add_w;
                    possible = add_h >= 3;
                }
            }
        }
    }


    if (possible)
    {
        possible = true;
        memset(grid, '*', sizeof(grid));
        for (unsigned r = 0; r < h; ++r)
        {
            for (unsigned c = 0; c < w; ++c)
            {
                grid[r][c] = '.';
            }
        }
        for (unsigned r = 0; r < add_h; ++r)
        {
            grid[w][r] = '.';
        }
        for (unsigned c = 0; c < add_w; ++c)
        {
            grid[c][h] = '.';
        }
        grid[0][0] = 'c';
    }
}


void Problem::print_solution(ostream &os)
{
    if (transpose)
    {
        for (unsigned r = 0; r < C; ++r)
        {
            for (unsigned c = 0; c < R; ++c)
            {
                os << grid[c][r];
            }
            os << "\n";
        }
    }
    else
    {
        for (unsigned r = 0; r < R; ++r)
        {
            for (unsigned c = 0; c < C; ++c)
            {
                os << grid[r][c];
            }
            os << "\n";
        }
    }
}

int main(int argc, char ** argv)
{
    const string dash("-");

    istream *pfi = (argc < 2 || (string(argv[1]) == dash))
         ? &cin
         : new ifstream(argv[1]);
    ostream *pfo = (argc < 3 || (string(argv[2]) == dash))
         ? &cout
         : new ofstream(argv[2]);

    unsigned n_cases;
    *pfi >> n_cases;

    ostream &fout = *pfo;
    for (unsigned ci = 0; ci < n_cases; ci++)
    {
        Problem problem(*pfi);
        problem.solve();
        fout << "Case #"<< ci+1 << ":\n";
        if (problem.is_possible())
        {
            problem.print_solution(fout);
        }
        else
        {
            fout << "Impossible\n";
        }
        fout.flush();

    }

    if (pfi != &cin) { delete pfi; }
    if (pfo != &cout) { delete pfo; }
    return 0;
}
