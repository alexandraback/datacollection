#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <tuple>
#include <functional>
#include <sstream>
#include <cassert>
using namespace std;

class TestCase
{
public:
   vector<string> rows;
   int wins(int x0, int y0, int xi, int yi)
   {
      char vals[4] = { rows[x0][y0], rows[x0+xi][y0+yi], rows[x0+xi*2][y0+yi*2], rows[x0+xi*3][y0+yi*3] };
      bool xwin=true, ywin=true;
      for (int i = 0; i < 4; ++i)
      {
         if (vals[i] == 'O') xwin=false;
         if (vals[i]=='X') ywin=false;
         if (vals[i]=='.') xwin=ywin=false;
      }
      if (ywin) return 1;
      if (xwin) return 2;
      return 0;
   }
   string eval(istream& is)
   {
      bool isdraw=true;
      for (int i = 0; i < 4; ++i) {
         string row; is >> row;
         rows.push_back(row);
         for (int y = 0; y < 4; ++y) { if (row[y]=='.') isdraw=false; }
      }
      
      int winval=0;
      for (int x = 0; x < 4 && winval==0; ++x)
      {
         for (int y = 0; y < 4 && winval==0; ++y)
         {
            if ((x==0 || x == 3) || (y==0 || y==3))
            {
               int xi=0,yi=0;
               if (x==0) xi=1;
               if (x==3) xi=-1;
               if (y==0) yi=1;
               if (y==3) yi=-1;
               winval = wins(x, y, xi, yi);
               if (! winval)
               {
                  if (xi!=0 && yi!=0)
                  {
                     winval = wins(x, y, xi, 0) | wins(x, y, 0, yi);
                  }
               }
            }
         }
      }
      if (winval==1) return "O won";
      if (winval==2) return "X won";
      if (isdraw) return "Draw";
      return "Game has not completed";
   }
};

int main(int argc, char* argv[])
{
   ifstream infile(argv[1]);
   int T;
   infile >> T;
   for (int tc = 0; tc < T; ++tc)
   {
      TestCase testcase;
      cout << "Case #" << tc+1 << ": " << testcase.eval(infile) << '\n';
   }
   return 0;
}
