#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long int ll;

int t;

ll solve(vector<ll>& motes, ll a)
{
  while(!motes.empty() && motes.back() < a)
  {
    a += motes.back();
    motes.pop_back();
  }

  if(motes.empty())
  {
    return 0;
  }
  else
  {
    ll stop = motes.size();

    if(a > 1)
    {
      ll eat = 0;
      while(motes.back() >= a)
      {
        eat += 1;
        a += a - 1;
      }
      return min(stop, eat + solve(motes, a));
    }
    else
    {
      return stop;
    }
  }
}

int main()
{
  scanf("%d", &t);

  for(int z = 1; z <= t; z++)
  {
    ll a, n;
    scanf("%lld %lld", &a, &n);

    vector<ll> motes;

    for(ll i = 0; i < n; ++i)
    {
      ll x;
      scanf("%lld", &x);
      motes.push_back(x);
    }

    sort(motes.begin(), motes.end());
    reverse(motes.begin(), motes.end());

    printf("Case #%d: %lld\n", z, solve(motes, a));
  }

  return 0;
}
