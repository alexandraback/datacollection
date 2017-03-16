#include<cstdio>
#include<vector>
using namespace std;
long long int z, i, n, nr, odw, wynik, dp[1000001]; 
std::vector<long long int>v;

long long int odwrotnosc(long long int x)
{
  while(x > 0)
  {
    v.push_back(x % 10);
    x /= 10;
  }
  long long int wyn = 0;
  for(long long int i = 0; i < v.size(); i++)
  {
    wyn *= 10;
    wyn += v[i];
  }
  v.clear();
  return wyn;
}

int main()
{
  scanf("%lld", &z);
  
  for(nr = 1; nr <= z; nr++)
  {
    scanf("%lld", &n);
    
    for(i = 0; i <= n; i++)
    {
      dp[i] = n + 1;
    }
    
    dp[0] = 0;
    
    for(i = 0; i < n; i++)
    {
      odw = odwrotnosc(i);
      if (odw > i){dp[odw] = min(dp[odw], dp[i] + 1);}
      dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }
    printf("Case #%lld: %lld\n", nr, dp[n]);
  }  
  
return 0;
}