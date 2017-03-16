#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool trailing_space = true; // for output

const long M = 1000000007;

long fact[101] = {};

long factorial(int n)
{
   if (fact[n]) return fact[n];

   fact[0] = 1;

   for(int i = 1; i <= n; ++ i)
   {
      if (fact[i]) continue;
      fact[i] = (fact[i-1] * (long)i) % M;
   }

   return fact[n];
}

struct Solver
{
   int N;

   vector<string> labels;

   vector<string> segs;

   long answer;

      char middles[256];
      char heads[256];
      char tails[256];


   void read_input()
   {
      cin >> N;
      labels.resize(N);
      for(int i = 0; i < N; ++ i) cin >> labels[i];
   }

   string get_rep(const string & input)
   {
      string rep(1, input[0]);
      for(int i = 1; i < input.length(); ++ i)
      {
         if (input[i] != rep.back())  rep.push_back(input[i]);
      }
      return rep;
   }

   void process_single(string & rep)
   {
      int i = 0;
      for(; i < N && labels[i] == rep; ++ i);

      char f = rep[0];

      if (middles[f])
      {
         answer = 0;
         return;
      }

      if (!heads[f] && !tails[f])
      {
         segs.push_back(rep);
      }

      answer *= factorial(i);
      answer %= M;

      labels.erase(labels.begin(), labels.begin() + i);
   }

   void solve()
   {
      answer = 0;
      memset(middles, 0, sizeof(middles));
      memset(heads, 0, sizeof(heads));
      memset(tails, 0, sizeof(tails));

      for(int i = 0; i < N; ++ i)
      {
         string & rep = labels[i] = get_rep(labels[i]);
         if (rep.length() > 1)
         {
            char f = rep.front();
            char l = rep.back();
            if (rep.length() > 2 && f == l) return;

            for(int j = 1; j < rep.length() - 1; ++ j)
            {
               char m = rep[j];
               if (middles[m] || heads[m] || tails[m]) return;
               middles[m] = 1;
            }

            if (f == l)
            {
               rep.resize(1);
               if (middles[f]) return;
            }
            else
            {
               if (middles[f]) return;
               if (middles[l]) return;
               if (heads[f]) return;
               heads[f] = 1;
               if (tails[l]) return;
               tails[l] = 1;
               rep.resize(1);
               rep.push_back(l);
            }
         }
      }

      answer = 1;

      sort(labels.begin(), labels.end());
      // we will remove the free words

      while(labels.size())
      {
         string rep = labels[0];

         if (rep.length() == 1)
         {
            process_single(rep);
         }
         else
         {
            labels.erase(labels.begin());
            process_segment(rep);
         }
         if (answer == 0) break;
      }

      if (answer != 0)
      {
         answer *= factorial(segs.size());
         answer %= M;
      }

   }

   void process_segment(string & rep)
   {
      string seg = rep;

      char f = rep.front();
               char l = rep.back();

      while(labels.size())
      {
         bool found = false;
         for(int i = 0; i < labels.size(); ++ i)
         {
            if (labels[i].length() == 1) continue;
            if (labels[i].front() == l)
            {
               found = true;
               l = labels[i].back();
               seg.push_back(l);
               labels.erase(labels.begin() + i);
               break;
            }

         }
         if (!found) break;

      }

      while(labels.size())
      {
         bool found = false;
         for(int i = 0; i < labels.size(); ++ i)
         {
            if (labels[i].length() == 1) continue;
            if (labels[i].back() == f)
            {
               found = true;
               f = labels[i].front();
               seg.insert(0, 1, f);
               labels.erase(labels.begin() + i);
               break;
            }

         }
         if (!found) break;
      }
      if (f == l) answer = 0;
      cerr << seg << '\n';
      segs.push_back(seg);
   }

   void print_output()
   {
      cout << answer;
   }

   void execute()
   {
      read_input();
      solve();
      print_output();
   }
};


int main()
{
   long T = 0;
   cin >> T;
   for (long i = 0; i < T; ++ i)
   {
      cout << "Case #" << i + 1 << ':';
      if (trailing_space) cout << ' ';
      Solver s;
      s.execute();
      cout << '\n';
   }

   return 0;
}

