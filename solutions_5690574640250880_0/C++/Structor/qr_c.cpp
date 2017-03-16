#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define MAXFIELDS (50*50)

class Board
{
public:
    Board(int r, int c, int m)
        : r(r), c(c), m(m)
    {
        total = r*c;
        for (int i = 0; i < total; ++i)
            fields[i] = i < m ? '*' : '.';
    }

    ostream& print(ostream& out) const
    {
        const char* curr = fields;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                out << *curr;
                ++curr;
            }
            out << endl;
        }
        return out;
    }

    int index(int x, int y) const
    {
        if ((x < 0) || (x >= c) || (y < 0) || (y >= r))
            return -1;
        return y*c + x;
    }

    bool next_permutation()
    {
        return std::next_permutation(fields, fields + r*c);
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

    int reveal_all()
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

private:
    int r;
    int c;
    int m;
    int total;
    char fields[MAXFIELDS];
};

ostream& operator<<(ostream& out, const Board& board)
{    
    return board.print(out);
}

void solve(int r, int c, int m)
{
    bool solvable = false;
    Board board(r, c, m);
    do
    {
        board.mark();
        int f = board.reveal_all();
        if (f != -1)
        {
            board.reset();
            board.set_field(f, 'c');
            solvable = true;
            break;
        }
        board.reset();
    } while (board.next_permutation());

    if (solvable)
        cout << board;
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