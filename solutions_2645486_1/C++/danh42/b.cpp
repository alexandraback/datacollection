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
   long E,R,N;
   vector<long long> v;
   vector<bool> done;
   long long eval(istream& is)
   {
      is >> E >> R >> N;
      done.resize(N, false);
      for (long long i =0;i<N;++i) {
         long long vv;
         is >> vv;
         v.push_back(vv);
      }
      long long totalGood=0;
      for (long long iter=0;iter<N;++iter){
         long long maxv=0;
         long long maxvi=0;
         for (long long i = 0; i< N; ++i) {
            if (done[i]) continue;
            if (v[i]>maxv)
            {
               maxv=v[i];
               maxvi=i;
            }
         }
         long long regen=R;
         if (maxvi==0) regen=E;
         for (long long i = maxvi-1;i>=0;--i)
         {
            if (done[i]) break;
            regen+=R;
            if (i==0) regen=E;
         }
         long long nextregen=R;
         if (maxvi+1==N) nextregen = E;
         for (long long i = maxvi+1;i<N;++i) {
            if (done[i]) break;
            nextregen+=R;
            if (i+1==N) nextregen=E;
         }
         
         long long etouse=min((long long)E,regen);
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

int main(long long argc, char* argv[])
{
   ifstream infile("B-large.in");
   long T;
   infile >> T;
   for (long long tc = 0; tc < T; ++tc)
   {
      TestCase testcase;
      cout << "Case #" << tc+1 << ": " << testcase.eval(infile) << '\n';
   }
   return 0;
}
