#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
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
   double C, F, X;
   double eval(istream& is)
   {
      is >> C >> F >> X;

      double timeToWin = X / 2.0;
      double timeToNFarms = 0;
      double rate = 2.0;
      for (int farms = 0; true; ++farms)
      {
         timeToNFarms += C / rate;
         rate += F;
         double nextTtw = timeToNFarms + X / rate;
         if (nextTtw < timeToWin)
         {
            timeToWin = nextTtw;
         }
         else
         {
            break;
         }
      }
      return timeToWin;
   }
};

int main(int argc, char* argv[])
{
   ifstream infile(argv[1]);
   int T;
   infile >> T;
   ofstream out("B.out");
   //ostream& out = std::cout;
   for (int tc = 0; tc < T; ++tc)
   {
      TestCase testcase;
      out << "Case #" << tc + 1 << ": " << std::setprecision(10) << testcase.eval(infile) << '\n';
   }
   return 0;
}

