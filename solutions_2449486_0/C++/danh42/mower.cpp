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
   int N,M;
   vector<vector<int> > rows;
   vector<vector<int> > mown;
   string eval(istream& is)
   {
      is >> N>>M;
      for (int x=0;x<N;x++) {
         vector<int> row, mrow;
         for (int y=0;y<M;y++) {
            int v;
            is >> v;
            row.push_back(v);
            mrow.push_back(999);
         }
         rows.push_back(row);
         mown.push_back(mrow);
      }
      for (int x=0;x<N;++x)
      {
         int maxVal=rows[x][0];
         for (int y=0;y<M;++y)
         {
            maxVal=max(rows[x][y], maxVal);
         }
         for (int y=0;y<M;++y)
         {
            mown[x][y] = min(maxVal, mown[x][y]);
         }
      }
      for (int x=0;x<M;++x)
      {
         int maxVal=rows[0][x];
         for (int y=0;y<N;++y)
         {
            maxVal=max(rows[y][x], maxVal);
         }
         for (int y=0;y<N;++y)
         {
            mown[y][x] = min(maxVal, mown[y][x]);
         }
      }
      return (mown == rows) ? "YES" : "NO";
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
