//Aleksander Łukasiewicz
#include<cstdio>
using namespace std;

int t, c, d, n;
int denom[100];
bool sorted[100];
bool dp[100];

int main(){
  scanf("%d", &t);
  for(int pp=1; pp<=t; pp++){
    scanf("%d %d %d", &c, &d, &n);    
    for(int i=0; i<d; i++){
      scanf("%d", &denom[i]);
      if(denom[i] <= n)
	sorted[ denom[i] ] = true;
    }
    for(int i=1; i<=n; i++) dp[i] = 0;
    for(int i=0; i<d; i++){
      int val = denom[i];
      for(int j=n; j>val; j--)
	if(dp[j - val])
	  dp[j] = true;
      dp[val] = true;
    }
    
    int res = 0;
    int good = 0;
    for(int i=1; i<=n; i++)
      if(dp[i])
	good++;
    
    int ind = 1;
    while(good != n){
      while(dp[ind])
	ind++;
      
      for(int i=n; i>ind; i--)
	if(dp[i-ind])
	  dp[i] = true;
      dp[ind] = true;
      
      good = 0;
      for(int i=1; i<=n; i++)
      if(dp[i])
	good++;
      res++;
    }
    
    printf("Case #%d: %d\n", pp, res); 
  }

return 0;
}