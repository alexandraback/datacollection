#include<bits/stdc++.h>


using namespace std;

#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define elif else if
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define CLEAR(array, value) memset(ptr, value, sizeof(array));
bool foo(vector<int>set, int sum)
{
  int n=set.size();
    bool subset[sum+1][n+1];
    for (int i = 0; i <= n; i++)
      subset[0][i] = true;
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
       }
     }
      return subset[sum][n];
}
int main()
{
   //ios_base::sync_with_stdio(0);
  freopen("int","r",stdin);
  freopen("out","w",stdout);
  int CASES ;
  cin >> CASES;
  for (int CASE = 1; CASE <= CASES; ++CASE)
  {
   int i ,j,k,lim,n,val,ans=0;
   cin>>lim>>n>>val;
   vector<int>v(n);
   rep(i,n)
   cin>>v[i];
   for(i=1;i<=val;i++)
   {
      if(foo(v,i))
        continue;
      v.pb(i);
      ans++;
      sort(v.begin(),v.end());
   }
   printf("Case #%d: ", CASE);
    cout<<ans<<"\n";
  }

  return 0;
}