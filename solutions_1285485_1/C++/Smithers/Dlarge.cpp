#include <cmath>
#include <cstring>
#include <iostream>

#define MAX 30
int h, w;
char grid[MAX][MAX+1];

#define MAXD 50
char substeps[2*MAXD];

using namespace std;

int gcd(int i, int j)
{
    i = abs(i);
    j = abs(j);
    
    int temp;
    while (i)
        temp = i, i = j - (j / i * i), j = temp;
    
    return j;
}

void calcsubsteps(int di, int dj)
{
    di = abs(di);
    dj = abs(dj);
    char* p = substeps;
    if (di >= dj)
    {
        for (int i=0, j=0; i<di; ++i)
        {
            int x = (2*i+1) * dj + di;
            if (x % (2 * di))
            {
                if (x / (2*di) > j)
                    *p++ = 'j';
                *p++ = 'i';
            }
            else
            {
                *p++ = 'x';
            }
            j = x / (2 * di);
        }
        *p = 0;
    }
    else
    {
        for (int j=0, i=0; j<dj; ++j)
        {
            int x = (2*j+1) * di + dj;
            if (x % (2 * dj))
            {
                if (x / (2*dj) > i)
                    *p++ = 'i';
                *p++ = 'j';
            }
            else
            {
                *p++ = 'x';
            }
            i = x / (2 * dj);
        }
        *p = 0;
    }
}

int dostep(int& i, int& j, int& stepi, int& stepj)
{
    for (char* p=substeps; *p; ++p)
    {
        switch (*p)
        {
        case 'i':
            if (grid[i+stepi][j] == '#')
                stepi = -stepi;         // Vertical bounce.
            else
                i += stepi;             // Vertical step.
            break;
        case 'j':
            if (grid[i][j+stepj] == '#')
                stepj = -stepj;         // Horizontal bounce.
            else
                j += stepj;             // Horizontal step.
            break;
        case 'x':
            if (grid[i+stepi][j+stepj] == '#')
            {
                if (grid[i+stepi][j] == '#' && grid[i][j+stepj] == '#')
                {
                    stepi = -stepi;     // Diagonal bounce.
                    stepj = -stepj;
                }
                else if (grid[i+stepi][j] == '#')
                {
                    stepi = -stepi;     // Vertical bounce, horizontal step.
                    j += stepj;
                }
                else if (grid[i][j+stepj] == '#')
                {
                    i += stepi;         // Horizontal bounce, vertical step.
                    stepj = -stepj;
                }
                else
                    return 1;           // Destroyed.
            }
            else
            {
                i += stepi;             // Diagonal step.
                j += stepj;
            }
            break;
        }
    }
    return 0;
}

int test(int maxsteps, int xi, int xj, int di, int dj)
{
    int i = xi, j = xj;
    di = di > 0 ? 1 : di < 0 ? -1 : 0;
    dj = dj > 0 ? 1 : dj < 0 ? -1 : 0;
    for (int step=0; step<maxsteps; ++step)
    {
        if (dostep(i, j, di, dj))
            return 0;
        if (i == xi && j == xj)
            return 1;
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    for (int c=1; c<=t; c++)
    {
        int d;
        cin >> h >> w >> d;
        int i, j;
        for (i=0; i<h; ++i)
            cin >> grid[i];
        
        int xi, xj;
        char* p;
        for (xi=0; xi<h; ++xi)
        {
            if (p = strchr(grid[xi], 'X'))
            {
                xj = p - grid[xi];
                break;
            }
        }
        
        int result = 0;
        for (int di=0; di<=d; ++di)
            for (int dj=0; dj<=d; ++dj)
                if (di*di + dj*dj <= d*d && gcd(di, dj) == 1)
        {
            calcsubsteps(di, dj);
            int maxsteps = sqrt((double)(d*d / (di*di + dj*dj)));
            result += test(maxsteps, xi, xj, di, dj);
            if (di)
                result += test(maxsteps, xi, xj, -di, dj);
            if (dj)
                result += test(maxsteps, xi, xj, di, -dj);
            if (di && dj)
                result += test(maxsteps, xi, xj, -di, -dj);
        }
        
        cout << "Case #" << c << ": " << result << endl;
    }
    return 0;
}
