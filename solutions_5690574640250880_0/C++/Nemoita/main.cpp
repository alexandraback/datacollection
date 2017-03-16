#include <iostream>
#include <math.h>

using namespace std;

#if 1
#define INPUT_FILE  "C-small.in.txt"
#define OUTPUT_FILE "C-small.out.txt"
#else
#define INPUT_FILE  "C-large.in.txt"
#define OUTPUT_FILE "C-large.out.txt"
#endif

char grid [50][50];
int T, R, C, M;
int r, c, m;

int main(int argc, const char * argv[])
{
    freopen(INPUT_FILE, "r", stdin);
	freopen(OUTPUT_FILE, "w+", stdout);
    
    cin >> T;

    // For each test case
    for (int t = 0; t < T; t++)
    {
        bool impossible = false;
        
        cin >> R >> C >> M;
        
        r = R;
        c = C;
        m = M;
        
        // Limits: 0 <= M < RxC
        
        // Reduce area
        while (c>0 && r>0)
        {
            if (r>c)
            {
                // Fill row
                if (m>=c)
                {
                    m-=c;
                    r--;
                }
                else { break; }
            }
            else
            {
                // Fill column
                if (m>=r)
                {
                    m-=r;
                    c--;
                }
                else { break; }
            }
        }
        
        // Current area: r x c
        // Current mines: m
        // New limits: m < r, m < c
        
        const int minesInLargerSide = (m == 0) ? 0 : ((m+2)/2);
        const int minesInSmallerSide = (m == 0) ? 0 : (m - minesInLargerSide + 1);
        const int larger = r > c ? r : c;
        const int smaller = r > c ? c : r;

        if ((R==1) || (C==1) ||
            ((minesInLargerSide < larger-1) && (minesInSmallerSide < smaller-1)) ||
            ((r==1)&&(c==1)))
        {
            const int IR = R - r;
            const int IC = C - c;
            
            // Fill in grid
            for (int ir = 0; ir < R; ir++)
            {
                int ic = 0;
                if (ir < IR)
                {
                    for (; ic < C; ic++)
                        grid [ir][ic] = '*';
                }
                else
                {
                    for (; ic < IC; ic++)
                        grid [ir][ic] = '*';
                    for (; ic < C; ic++)
                        grid [ir][ic] = '.';
                }
            }
            
            // Fill in reduced area is there are mines left
            if (m != 0)
            {
                const int minesInRow = (larger == c) ? minesInLargerSide : minesInSmallerSide;
                const int minesInCol = (larger == c) ? minesInSmallerSide : minesInLargerSide;
                    
                for (int i = 0; i < minesInRow; i++)
                {
                    grid[IR][IC+i] = '*';
                }
                for (int i = 1; i < minesInCol; i++)
                {
                    grid[IR+i][IC] = '*';
                }
            }
            
            grid[R-1][C-1] = 'c';
        }
        else
        {
            impossible = true;
        }

        cout << "Case #" << t+1 << ":" << endl;
        if (impossible)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            for (int ir = 0; ir<R; ir++)
            {
                for (int ic = 0; ic<C; ic++)
                {
                    cout << grid[ir][ic];
                }
                cout << endl;
            }
        }
    }

    return 0;
}

