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
   int R,N,M,K;
   vector<int> prod;
   std::string eval(istream& is)
   {
      std::stringstream result;
      is >> R >> N >> M >> K;
      for (int rc=0;rc<R;++rc) {
         map<int,int> prodOccur;
         set<int> prodSet;
         for (int i = 0; i < K; ++i) {
            int p;
            is >> p;
            prod.push_back(p);
            prodOccur[p]++;
            prodSet.insert(p);
         }
         vector<int> occur(10, 0);
         int occurCount=0;
         set<int> pos;
         for (int i = 2; i <= M;++i) {
            for (int pi=0;pi<prod.size();++pi) {
               int num=prod[pi];
               while ((num % i)==0)
               {
                  num/=i;
                  occur[i]++;
                  ++occurCount;
               }
               if ((prod[pi]%i) == 0) {
                  pos.insert(i);
               }
            }
         }
         int bestScore=0;
         vector<int> answer;
         for (int tri=0;tri<10000;++tri) {
            vector<int> picks;
            for (int nn=0;nn<N;++nn) {
               int pick=0;
               int rv=rand()%occurCount;
               int sum=0;
               for (int i=2;i<=M;++i) {
                  sum += occur[i];
                  if (sum > rv) {
                     pick=i;
                     break;
                  }
               }
               assert(pick);
               picks.push_back(pick);
            }
            
            int score = 0;
            set<int> hitProds;
            for (int mc=0;mc<100;++mc) {
               int prod=1;
               for (int i = 0; i < N; ++i) {
                  if ((rand()%2)) {
                     prod*=picks[i];
                  }
               }
               if (prodOccur.find(prod) != prodOccur.end()) {
                  hitProds.insert(prod);
                  score += prodOccur[prod];
               }
            }
            if (hitProds!=prodSet) score=0;
            if (score > bestScore)
            {
               answer = picks;
               score = bestScore;
            }
         }
         std::stringstream ss;
         for (int i = 0; i < answer.size(); ++i) {
            ss << answer[i];
         }
         result << '\n' << ss.str();
      }
      return result.str();;
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
