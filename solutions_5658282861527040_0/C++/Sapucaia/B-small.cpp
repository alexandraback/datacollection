#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

#define rep0(i,n) for(int i = 0;i < (int)n;i++)
#define rep1(i,n) for(int i = 1;i <= (int)n;i++)
#define per0(i,n) for(int i = (int)n-1;i >= 0;i--)
#define per1(i,n) for(int i = (int)n ;i >= 1;i--)

#define pb push_back
#define fill(d,v) memset(d,v,sizeof(d))

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;


int main()
{
  cin.sync_with_stdio(false);
  int T_;
  cin >> T_;
  for(int t_ = 1; t_ <= T_;t_++)
    {
      int A,B,K;
      int ans = 0;
      cin >> A >> B >> K;
      for(int i = 0; i < A;i++)
	for(int j = 0; j < B;j++)
	  if( (i&j) < K)
	    ans++;
      cout << "Case #" << t_ << ": ";
      cout << ans;
      cout << "\n";
    }
  return 0;
}
