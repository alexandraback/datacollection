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
   int K,N;
   struct Chest{
      int locktype;
      vector<int> keys;
   };
   
   struct State
   {
      bool operator<(const State& rhs) const {
         if (remainingChests < rhs.remainingChests) return true;
         if (remainingChests > rhs.remainingChests) return false;
         return (keys<rhs.keys);
      }
      void removekey(int k)
      {
         int& v = keys[k];
         --v;
         if (v==0) keys.erase(k);
      }
      vector<int>    remainingChests;
      map<int, int>  keys;
      set<int> keyset() const
      {
         set<int> ks;
         for (map<int, int>::const_iterator i = keys.begin(); i != keys.end(); ++i) ks.insert(i->first);
         return ks;
      }
      set<int> chestset() const
      {
         set<int> cs;
         for (int i = 0;i<remainingChests.size(); ++i)
         {
            cs.insert(remainingChests[i]);
         }
         return cs;
      }
   };
   map<int,set<int>> keyTypeToChest;
   vector<int> answer;
   vector<Chest> allChests;
   bool isImpossible(const State& s)
   {
      vector<int> keycounts(200,0);
      set<int> newkeys = s.keyset();
      for (map<int, int>::const_iterator i = s.keys.begin(); i != s.keys.end(); ++i)
      {
         keycounts[i->first]+=i->second;
      }
      set<int> keys = newkeys;
      set<int> chests = s.chestset();
      while (!newkeys.empty()) {
         int kk=*newkeys.begin();
         keys.insert(kk);
         newkeys.erase(newkeys.begin());
         set<int> nc = keyTypeToChest[kk];
         for (int ci : nc)
         {
            if (chests.find(ci) != chests.end()){
               keycounts[kk]--;
               chests.erase(ci);
               for (int k : allChests[ci].keys) {
                  if (keys.find(k)==keys.end()){
                     newkeys.insert(k);
                  }
                  keycounts[k]++;
               }
            }
         }
      }
      if (! chests.empty()) return true;
      for (int i =0;i<200;++i) if (keycounts[i]<0) return true;
      return false;
   }
   bool solve(const State& state)
   {
      if (state.remainingChests.empty())
      {
         return true;
      }
      if (isImpossible(state)) return false;
      for (int i = 0; i < state.remainingChests.size(); ++i)
      {
         Chest& c = allChests[state.remainingChests[i]];
         if (state.keys.find(c.locktype) != state.keys.end())
         {
            State s2 = state;
            s2.removekey(c.locktype);
            s2.remainingChests.erase(s2.remainingChests.begin() + i);
            for (int ki=0;ki<c.keys.size(); ++ki)
            {
               s2.keys[c.keys[ki]]+=1;
            }
            if (solve(s2)) {
               answer.push_back(state.remainingChests[i]);
               return true;
            }
         }
      }
      return false;
   }
   string eval(istream& is)
   {
      State init;
      init.keys.clear();
      is >> K >> N;
      for (int i = 0;i<K; ++i) { int v; is >> v; init.keys[v]++; }
      for (int i = 0;i<N; ++i) {
         init.remainingChests.push_back(i);
         Chest c;
         int keys;
         is >> c.locktype >> keys;
         for (int j =0;j<keys;++j)
         {
            int k; is >> k;
            c.keys.push_back(k);
         }
         keyTypeToChest[c.locktype].insert(allChests.size());
         allChests.push_back(c);
      }
      if (solve(init))
      {
         std::stringstream ss;
         std::reverse(answer.begin(), answer.end());
         for (int i = 0; i < answer.size(); ++i)
         {
            if (i!=0) ss << ' ';
            ss << answer[i]+1;
         }
         return ss.str();
      }
      else
      {
         return "IMPOSSIBLE";
      }
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
      cerr << tc << '\n';
   }
   return 0;
}
