#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define MAXFIELDS (50*50)

class Board
{
public:
    Board(int r, int c)
        : r(r), c(c)
    {
        total = r*c;
        for (int i = 0; i < total; ++i)
            fields[i] = '.';
    }

    ostream& print(ostream& out, bool swap) const
    {
        if (!swap)
        {
            for (int y = 0; y < r; ++y)
            {
                for (int x = 0; x < c; ++x)
                    out << fields[index(x, y)];
                out << endl;
            }
        }
        else
        {
            for (int x = 0; x < c; ++x)
            {
                for (int y = 0; y < r; ++y)
                    out << fields[index(x, y)];
                out << endl;
            }
        }
        return out;
    }

    int index(int x, int y) const
    {
        if ((x < 0) || (x >= c) || (y < 0) || (y >= r))
            return -1;
        return y*c + x;
    }

    int mine_count(int x, int y)
    {
        int idx = index(x, y);
        if (idx == -1)
            return 0;
        return fields[idx] == '*' ? 1 : 0;
    }

    void mark()
    {
        for (int i = 0; i < total; ++i)
        {
            if (fields[i] == '.')
            {
                int x = i % c;
                int y = i / c;
                int count = mine_count(x - 1, y - 1) + mine_count(x, y - 1) + mine_count(x + 1, y - 1) +
                    mine_count(x - 1, y) + mine_count(x + 1, y) +
                    mine_count(x - 1, y + 1) + mine_count(x, y + 1) + mine_count(x + 1, y + 1);
                fields[i] = '0' + count;
            }
        }
    }

    void reset()
    {
        for (int i = 0; i < total; ++i)
        {
            if (fields[i] != '*')
                fields[i] = '.';
        }
    }

    int reveal_all(int m)
    {
        if ((m + 1) == total)
        {
            for (int i = 0; i < total; ++i)
            {
                if (fields[i] != '*')
                    return i;
            }
        }

        int cf = -1;
        for (int i = 0; i < total; ++i)
        {
            if (fields[i] == '0')
            {
                cf = i;
                break;
            }
        }
        if (cf == -1)
            return -1;

        queue<int> q;
        q.push(cf);
        fields[cf] = 'm';
        int marked_count = 1;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            int x = f % c;
            int y = f / c;

            process(x - 1, y - 1, q, marked_count);
            process(x, y - 1, q, marked_count);
            process(x + 1, y - 1, q, marked_count);

            process(x - 1, y, q, marked_count);
            process(x + 1, y, q, marked_count);

            process(x - 1, y + 1, q, marked_count);
            process(x, y + 1, q, marked_count);
            process(x + 1, y + 1, q, marked_count);
        }

        if (marked_count == (total - m))
            return cf;
        return -1;
    }

    void process(int x, int y, queue<int>& q, int& marked_count)
    {
        int idx = index(x, y);
        if (idx == -1)
            return;
        char ch = fields[idx];
        if (ch == '0')
            q.push(idx);
        if ((ch != '*') && (ch != 'm'))
        {
            fields[idx] = 'm';
            ++marked_count;
        }
    }

    void set_field(int idx, char ch)
    {
        fields[idx] = ch;
    }

    void set_field(int x, int y, char ch)
    {
        fields[index(x, y)] = ch;
    }

    int get_r() const { return r; }
    int get_c() const { return c; }
    int get_total() const { return total; }

private:
    int r;
    int c;
    int total;
    char fields[MAXFIELDS];
};

bool solve1(Board& board, int m)
{
    for (int i = 0; i < m; ++i)
        board.set_field(i, '*');
    board.mark();
    int f = board.reveal_all(m);
    if (f == -1)
        throw - 1;
    board.reset();
    board.set_field(f, 'c');
    return true;
}

bool solve2(Board& board, int m)
{
    int total = board.get_total();
    int free = total - m;
    if (free == 1)
    {
        for (int i = 0; i < m; ++i)
            board.set_field(i, '*');
        board.set_field(m, 'c');
        return true;
    }

    if ((free == 2) || ((free & 1) != 0))
        return false;

    int hm = m / 2;
    for (int i = 0; i < hm; ++i)
    {
        board.set_field(i, 0, '*');
        board.set_field(i, 1, '*');
    }
    board.mark();
    int f = board.reveal_all(m);
    if (f == -1)
        throw - 1;
    board.reset();
    board.set_field(f, 'c');
    return true;
}

bool solven(Board& board, int m)
{
    int total = board.get_total();
    int rows = board.get_r();
    int cols = board.get_c();
    int free = total - m;
    switch (free)
    {
    case 2:
    case 3:
    case 5:
    case 7:
        return false;
    }

    if (free == 1)
    {
        for (int i = 0; i < m; ++i)
            board.set_field(i, '*');
        board.set_field(m, 'c');
        return true;
    }

    int free_rows = free / cols;
    if (free_rows >= 3)
    {
        int cols_free = cols - (m % cols);
        if (cols_free != 1)
        {
            for (int i = 0; i < m; ++i)
                board.set_field(i, '*');
        }
        else
        {
            for (int i = 0; i < (m-1); ++i)
                board.set_field(i, '*');
            board.set_field(m + 1, '*');
        }
    }
    else
    {
        int in_top_rows = (rows - 3)*cols;
        for (int i = 0; i < in_top_rows; ++i)
            board.set_field(i, '*');
        int in_last_rows = m - in_top_rows;
        if ((in_last_rows <= (cols - 2)) || (in_last_rows == cols))
        {
            for (int i = 0; i < in_last_rows; ++i)
                board.set_field(in_top_rows + i, '*');
        }
        else
        {
            int bottom = in_last_rows - (cols - 3);
            if ((bottom & 1) == 0)
            {
                for (int i = 0; i < cols - 3; ++i)
                    board.set_field(in_top_rows + i, '*');
                int half = bottom / 2;
                for (int i = 0; i < half; ++i)
                {
                    board.set_field(i, rows - 2, '*');
                    board.set_field(i, rows - 1, '*');
                }
            }
            else
            {
                bottom = in_last_rows - cols;
                for (int i = 0; i < cols; ++i)
                    board.set_field(in_top_rows + i, '*');
                int half = bottom / 2;
                for (int i = 0; i < half; ++i)
                {
                    board.set_field(i, rows - 2, '*');
                    board.set_field(i, rows - 1, '*');
                }
            }
        }
    }


    board.mark();
    int f = board.reveal_all(m);
    if (f == -1)
    {
        board.print(cout, false);
        throw - 1;
    }
    board.reset();
    board.set_field(f, 'c');
    return true;
}

void solve(int r, int c, int m)
{
    bool swap = false;
    if (c < r)
    {
        int temp = r;
        r = c;
        c = temp;
        swap = true;
    }
    Board board(r, c);

    bool solvable;
    if (r == 1)
        solvable = solve1(board, m);
    else if (r == 2)
        solvable = solve2(board, m);
    else
        solvable = solven(board, m);

    if (solvable)
        board.print(cout, swap);
    else
        cout << "Impossible" << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ":" << endl;
        int r, c, m;
        cin >> r >> c >> m;
        solve(r, c, m);
    }
    return 0;
}