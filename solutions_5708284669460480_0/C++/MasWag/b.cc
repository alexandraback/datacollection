#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

#define rep(i,n) for (int i = 0; i < n; i++)

int factorial (int x)
{
  int r = 1;
  rep (i,x)
    {
      r *= i + 1;
    }

  return r;
}

int main(void)
{
  int T;
  scanf ("%d",&T);
  for (int t = 0;t < T;++t)
    {
      double ans;
      int K,L,S;
      multiset<char> inp;
      vector<char> test;
      scanf ("%d %d %d\n",&K,&L,&S);
      const int max_appearance = S / L;
      double last_prob = 0;
      double single_prob = 1;
      int longest_match = -1;

      rep (i,K)
        {
          char c;
          scanf ("%c",&c);
          inp.insert (c);
        }
      // LF
      getchar ();

      rep (i,L)
        {
          char c;
          scanf ("%c",&c);

          auto it = inp.find (c);
          if (it == inp.end ())
            {
              while (getchar () != '\n');
              ans = 0.0;
              goto end;
            }
          test.push_back(c);
        }
      
      ans = max_appearance;

      for (auto c:test)
        {
          single_prob *= static_cast<double>(inp.count (c)) / K;
        }

      for (int i = L / 2 - 1; i >= 0;--i)
        {
          bool ok = true;
          for (int j = 0;j <= i;++j)
            {
              if (test[i - j] != test[L - 1 -j])
                {
                  ok = false;
                  break;
                }
            }
          if (ok)
            {
              longest_match = i;
              break;
            }
        }
      

      for (int i = max_appearance;i >= 0;--i)
        {
          double prob = pow(single_prob,i) * factorial (S+L*i+i) /(factorial (S+L*i) * factorial (i));
          
          ans -= (prob - last_prob) * i;
          last_prob = prob;
        }
      

      end:
      printf ("Case #%d: %f\n",t+1,ans);
    }
  return 0;
}
