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
    for (int t=0;t<T;t++)
    {
        char mp[10][256];
        memset(mp,0,sizeof(mp));
        char dt[4][4];
        int full = 0;
        for (int y=0;y<4;y++)
            for (int x=0;x<4;x++)
            {
                char ch;
                cin >> ch;
                if (ch=='X' || ch=='O' || ch=='T') full++;
                mp[y][ch]++;
                mp[x+4][ch]++;
                if (x==y) mp[8][ch]++;
                if (3-x==y) mp[9][ch]++;
            }
        int X = 0;
        int O = 0;
        for (int i=0;i<10;i++)
        {
            if (mp[i]['X']+mp[i]['T']>=4) X++;
            if (mp[i]['O']+mp[i]['T']>=4) O++;
        }
        if (X>0)
        {
            cout << "Case #" << t+1 << ": X won" << endl;
        } else if (O>0)
        {
            cout << "Case #" << t+1 << ": O won" << endl;
        } else if (full==16)
        {
            cout << "Case #" << t+1 << ": Draw" << endl;
        } else
        {
            cout << "Case #" << t+1 << ": Game has not completed" << endl;
        }
    }

}

int main(int argc,char *argv[])
{
  solve();

  return 0;
}
