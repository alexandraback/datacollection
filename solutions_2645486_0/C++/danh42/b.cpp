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
   int E,R,N;
   vector<int> v;
   vector<bool> done;
   long long eval(istream& is)
   {
      is >> E >> R >> N;
      done.resize(N, false);
      for (int i =0;i<N;++i) {
         int vv;
         is >> vv;
         v.push_back(vv);
      }
      long long totalGood=0;
      for (int iter=0;iter<N;++iter){
         int maxv=0;
         int maxvi=0;
         for (int i = 0; i< N; ++i) {
            if (done[i]) continue;
            if (v[i]>maxv)
            {
               maxv=v[i];
               maxvi=i;
            }
         }
         int regen=R;
         if (maxvi==0) regen=E;
         for (int i = maxvi-1;i>=0;--i)
         {
            if (done[i]) break;
            regen+=R;
            if (i==0) regen=E;
         }
         int nextregen=R;
         if (maxvi+1==N) nextregen = E;
         for (int i = maxvi+1;i<N;++i) {
            if (done[i]) break;
            nextregen+=R;
            if (i+1==N) nextregen=E;
         }
         
         int etouse=min(E,regen);
         if (etouse + nextregen >= E)
         {
            if (maxvi+1 != N)
               etouse = min(etouse, etouse + nextregen - E);
         }
         else
         {
            etouse=0;
         }
         totalGood+=etouse*v[maxvi];
         done[maxvi]=true;
      }
      return totalGood;
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
