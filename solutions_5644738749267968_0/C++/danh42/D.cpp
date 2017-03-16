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
#include <deque>


using namespace std;
class TestCase
{
public:
   
   int N;
   vector<double> her; vector<double> him;

   int w(int fs, int fe, int ms, int me)
   {
      if (fs > fe) return 0;
      int best = 0;
      if (her[fe] > him[me])
      {
         best = w(fs, fe-1, ms+1, me) + 1;
      }
      else
      {
         best = w(fs, fe-1, ms, me-1);
      }
      return best;
   }
   int dw(int fs, int fe, int ms, int me)
   {
      if (fs > fe) return 0;
      int best = w(fs, fe, ms, me);
      if (her[fs] > him[ms])
      {
         best = max(best, dw(fs+1,fe,ms+1,me) + 1);
      }
      else if (her[fs] < him[me])
      {
         best = max(best, dw(fs+1,fe,ms,me-1));
      }
      return best;
   }


   std::string eval(istream& is)
   {
      
      is >> N;
      for (int i = 0; i < N ; i++)
      {
         double x;
         is >> x;
         her.push_back(x);
      }
      for (int i = 0; i < N; i++)
      {
         double x;
         is >> x;
         him.push_back(x);
      }

      std::sort(her.begin(), her.end());
      std::sort(him.begin(), him.end());
            
      std::stringstream ss;
      ss << dw(0,N-1,0,N-1) << ' ' << w(0,N-1,0,N-1);
      return ss.str();
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

