#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <set>

using namespace std;

class Board
{
public:
    Board(int n, int m) : n(n), m(m)
    {
        board = new bool[n*m];
        for(int i=0; i<n*m; i++)
            board[i] = false;
    }

    bool stone(int i, int j)
    {
        return board[i*m+j];
    }

    int enclosed()
    {
        set<int> notenclosed;
        for(int i=0; i<n; i++)
        {
            if(!stone(i, 0))
                notenclosed.insert(i*m+0);
            if(!stone(i, m-1))
                notenclosed.insert(i*m+m-1);
        }
        for(int i=0; i<m; i++)
        {
            if(!stone(0,i))
                notenclosed.insert(0*m + i);
            if(!stone(n-1, i))
                notenclosed.insert( (n-1)*m + i);
        }
        while(true)
        {
            set<int> newnot = notenclosed;
            for(set<int>::iterator it = notenclosed.begin(); it != notenclosed.end(); ++it)
            {
                int i = *it/m;
                int j = *it % m;
                if(i != 0 && !stone(i-1, j))
                    newnot.insert((i-1)*m+j);
                if(i != n-1 && !stone(i+1, j))
                    newnot.insert((i+1)*m+j);
                if(j != 0 && !stone(i, j-1))
                    newnot.insert(i*m+j-1);
                if(j != m-1 && !stone(i, j+1))
                    newnot.insert(i*m+j+1);
            }
            if(newnot.size() == notenclosed.size())
                break;
            notenclosed = newnot;
        }
        return n*m - notenclosed.size();
    }

    void fillBoard(int state)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int bit = 1<<(i*m+j);
                board[i*m+j] = state&bit;
            }
        }
    }

    int numStones()
    {
        int count=0;
        for(int i=0; i<n*m; i++)
            if(board[i]) count++;
        return count;
    }

    int n;
    int m;
    bool *board;
};

void testCase()
{
    int n, m, k;
    cin >> n >> m >> k;

    Board b(n, m);
    int best = n*m;
    for(int i=0; i<(2<<(n*m)); i++)
    {
        b.fillBoard(i);
        if(b.enclosed() >= k)
            best = min(best, b.numStones());
    }
    cout << " " << best << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cout << "Case #" << i+1 << ":";
        testCase();
    }
}


