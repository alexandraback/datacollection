#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define PII       pair<int,int>
#define all(c)    c.begin(),c.end()
#define sz(c)     (int)c.size()
#define clr(c)    c.clear()
#define pb        push_back
#define mp        make_pair
#define cin(x)    scanf("%d",&x)
#define MOD            1000000007
#define EPS            1E-10

ifstream fin("C.in");
ofstream fout("C.out");

int main()
{
      int t;
      fin >> t;
      for(int i = 1; i <= t; i++)
      {
            fout << "Case #" << i << ": ";
            int n;
            fin >> n;
            vector< pair<string,string> > arr(n);
            int ans = 0;
            for(int i = 0; i < (1 << n); i++)
            {
                  vector< pair<string,string> > A;
                  for(int j = 0 ; j < n; j++)
                        if(i & (1 << j))
                              A.pb(arr[j]);
                  int add = 1;
                  for(int a = 0; a < sz(A); a++)
                  {
                        if(!add) break;
                        for(int b = 0; b < sz(A); b++)
                        {
                              if(a == b) continue;
                              if(!add) break;
                              for(int c = 0; c < sz(A); c++)
                              {
                                    if(c == a or c == b) break;
                                    if(A[a].first == A[b].first && A[a].second == A[c].second)
                                    {
                                          add = 0;
                                          break;
                                    }
                              }
                        }
                  }
                  if(add)
                        ans = max(ans , __builtin_popcount(i));
            }
            fout << (n - ans) << endl;
      }
      return 0;
}