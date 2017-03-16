#include <iostream>
#include <cstdlib>
using namespace std;
#define O 1
#define I 2
#define J 3
#define K 4
#define abs(x) (x>=0?x:-x)
typedef long long ll;

int multi[5][5] = { {0, 0, 0, 0, 0},
                    {0, O, I, J, K},
                    {0, I, -O, K, -J},
                    {0, J, -K, -O, I},
                    {0, K, J, -I, -O}};
int m(int a, int b)
{
  int sig = a*b>0?1:-1;
  int ans = multi[abs(a)][abs(b)];
  return sig*ans;
}

int quickPow(int a, long long b)
{
  int ans = 1, r = a;
  while(b)
  {
    if(b&1)
    {
      ans = m(ans, r);
    }
    r = m(r, r);
    b >>= 1;
  }
  return ans;
}

int calc(string s)
{
  int ans = s[0] - 'i' + 2;
    for(int j = 1; j < s.size(); j++)
    {
      ans = m(ans, s[j] - 'i' + 2);
    }
    //ans = quickPow(ans, L);

return ans;
}

int dp[10005];
int main()
{
  int T;
  cin>>T;
  for(int i = 1; i <= T; i++)
  {
    int ans = 0;
    string s, t;
    ll L, X;
    cin>>X>>L;
    cin>>s;
    for(int j = 0; j < L; j++)
      t += s;
    dp[t.size() - 1] = t[t.size() - 1] - 'i' + 2;
    for(int j = t.size() - 2; j >= 0; j--)
    {
      dp[j] = m(t[j]-'i'+2, dp[j+1]);
    }


    if(t.size() < 3) ans = 2;
    else
    {
      int q1 = 1;
      for(int l1 = 1; l1 <= t.size() - 2; l1++)
      {
        q1 = m(q1, t[l1-1] - 'i' + 2);
        if(q1 != I) continue;
        else
        {
          int q2 =1;
          for(int l2 = 1; l2 <= t.size() - l1; l2++)
          {
            q2 = m(q2, t[l1 +l2 -1] - 'i' + 2);
            if(q2 != J) continue;
            else
            {
              if(l1 + l2 < t.size() && dp[l1 + l2] == K)
              {
                ans = -1;
                goto HERE;
              }
            }
          }
        }
      }
    }
    HERE:
        cout<<"Case #"<<i<<": "<< (ans == -1 ? "YES":"NO")<<endl;
  }
  return 0;
}
