#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

#define inp_s     ios_base::sync_with_stdio(false)
#define DRT()     int test_case;cin>>test_case;while(test_case--)

#define VI        vector<int>
#define VS        vector<string>
#define VLL       vector<LL>
#define PII       pair<int,int>
#define PLL       pair<LL,LL>
#define all(c)    c.begin(),c.end()
#define sz(c)     c.size()
#define clr(c)    c.clear()
#define pb        push_back
#define mp        make_pair

#define GI(x)     scanf("%d",&x)

#define FOR(i,a,b)      for(int i=(a);i<(b);i++)
#define RFOR(i,a,b)     for(int i=(b)-1;i>=(a);i--)

#define gcd(a,b)  __gcd(a,b)
#define MOD       1000000007
#define EPS       1E-10
#define ELR       2.71828182845904523536
#define PI        acos(-1)

#define CASE(x)   fout << "Case #" << x << ": "

VI coins;

int main()
{
      ifstream fin("A.in");
      ofstream fout("A.out");
      int t;
      fin >> t;
      for(int ii = 1; ii <= t ;ii++)
      {
            int c,d,v;
            fin >> c >> d >> v;
            coins.resize(d);
            FOR(i,0,d) fin >> coins[i];
            VI poss(v+1,0);
            FOR(i,0,(1<<d))
            {
                  int temp = i;
                  int j = 0;
                  int val = 0;
                  while(temp)
                  {
                        if(temp%2) val += coins[j];
                        j += 1;
                        temp /= 2;
                  }
                  if(val <= v)
                  poss[val] = 1;
            }
            int ans = 0;
            while(1)
            {
                  int den = 0;
                  while(den <= v && poss[den] == 1) den += 1;
                  if(den > v) break;
                  ans += 1;
                  d += 1;
                  coins.pb(den);

                  FOR(i,0,(1<<d))
                  {
                        int temp = i;
                        int j = 0;
                        int val = 0;
                        while(temp)
                        {
                              if(temp%2) val += coins[j];
                              j += 1;
                              temp /= 2;
                        }
                        if(val <= v)
                        poss[val] = 1;
                  }
            }
            CASE(ii);
            fout << ans << endl;
      }
      return 0;
}
