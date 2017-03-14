#include <cmath>
#include <cstring>
#include <iostream>

#define MAX 30
int h, w;
char grid[MAX][MAX+1];

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

void dostep(int& i, int& j, int& stepi, int& stepj)
{
    i += stepi, j += stepj;
    while (i <= 0 || i >= h-1)
    {
        if (i <= 0)
            i = 1 - i;
        else
            i = 2 * h - 3 - i;
        stepi = -stepi;
    }
    while (j <= 0 || j >= w-1)
    {
        if (j <= 0)
            j = 1 - j;
        else
            j = 2 * w - 3 - j;
        stepj = -stepj;
    }
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
        for (int di=-d; di<=d; ++di)
            for (int dj=-d; dj<=d; ++dj)
                if (di*di + dj*dj <= d*d && gcd(di, dj) == 1)
        {
            int maxsteps = sqrt((double)(d*d / (di*di + dj*dj)));
            i = xi, j = xj;
            int stepi = di, stepj = dj;
            for (int step=0; step<maxsteps; ++step)
            {
                dostep(i, j, stepi, stepj);
                if (i == xi && j == xj)
                {
                    ++result;
                    break;
                }
            }
        }
        
        cout << "Case #" << c << ": " << result << endl;
    }
    return 0;
}
