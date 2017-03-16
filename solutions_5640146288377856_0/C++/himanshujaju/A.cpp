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

int main()
{
      ofstream fout("A.out");
      ifstream fin("A.in");
      int t;
      fin >> t;
      for(int ii = 1;ii<=t;ii++)
      {
            int r,c,w;
            fin >> r >> c >> w;
            int ans = (r-1) * (c/w);
            ans += ((c-1)/w) + w;

            CASE(ii);
            fout << ans << endl;
      }
      fin.close();
      fout.close();
      return 0;
}
