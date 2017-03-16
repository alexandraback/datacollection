#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

void solve()
{
    int T;
    cin >> T;
    int grid[128][128];
    for (int t=0;t<T;t++)
    {
        int X,Y;
        cin >> Y >> X;
        for (int y=0;y<Y;y++)
        {
            for (int x=0;x<X;x++)
            {
                cin >> grid[x][y];
            }
        }

        bool bYes = true;
        for (int y=0;y<Y;y++)
        {
            for (int x=0;x<X;x++)
            {

                bool h = false;
                for (int x2=0;x2<X;x2++)
                    if (grid[x2][y]>grid[x][y])
                    {
                        h = true;
                        break;
                    }
                bool v = false;
                for (int y2=0;y2<Y;y2++)
                    if (grid[x][y2]>grid[x][y])
                    {
                        v = true;
                        break;
                    }
                if (h && v)
                {
                    bYes = false;
                    goto next;
                }
            }
        }
        next:;
        if (bYes)
            cout << "Case #" << t+1 << ": YES" << endl;
        else
            cout << "Case #" << t+1 << ": NO" << endl;
    }

}

int main(int argc,char *argv[])
{
  solve();

  return 0;
}
