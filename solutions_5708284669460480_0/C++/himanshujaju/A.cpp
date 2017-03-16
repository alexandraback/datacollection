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

double dp[111][111];
int K,L,S;
string a,b;

double prob[26] = {0};

double solve(int taken,int cnt)
{
      if(cnt == L) return 1;
      else if(taken == S) return 0;
      else if(dp[taken][cnt] != -1) return dp[taken][cnt];
      double ret = 0;
      ret = prob[b[cnt]] * solve(taken + 1,cnt + 1) + (1 - prob[b[cnt]]) * solve(taken + 1,cnt);
      return (dp[taken][cnt] = ret);
}

double ans = 0;
double fx = 0;

void backtrack(string str)
{
      if(sz(str) == S)
      {
            double temp = 0;
            for(int i = 0;i<sz(str);i++)
            {
                  int j = 0;
                  while(j<sz(b) && (i+j) < sz(str))
                  {
                        if(str[i+j] == b[j]) j += 1;
                        else break;
                  }
                  if(j == sz(b)) ans += 1 , temp += 1;
            }
            fx = max(fx,temp);
      }
      else
            FOR(i,0,sz(a)) backtrack(str + (char)(a[i]));
}

int main()
{
      ofstream fout("A.out");
      ifstream fin("A.in");
      int t;
      fin >> t;
      fout.setf( std::ios::fixed, std:: ios::floatfield ); // floatfield set to fixed
      for(int ii = 1;ii<=t;ii++)
      {
            ans = 0;
            fx = 0;
            fin >> K >> L >> S;
            fin >> a >> b;
            backtrack("");
            ans /= pow(K,S);
            ans = fx - ans;
            CASE(ii);
            fout.precision(10);
            fout << ans << endl;
      }
      fin.close();
      fout.close();
      return 0;
}
