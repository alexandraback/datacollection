#include<bits/stdc++.h>


using namespace std;

#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define elif else if
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define CLEAR(array, value) memset(ptr, value, sizeof(array));

int main()
{
   //ios_base::sync_with_stdio(0);
  freopen("int","r",stdin);
  freopen("out","w",stdout);
  int CASES ;
  cin >> CASES;
  for (int CASE = 1; CASE <= CASES; ++CASE)
  {
   int r,c,w;
   cin>>r>>c>>w;
   int ans= c/w + w;
   if(c%w==0)
    ans--;
    printf("Case #%d: ", CASE);
    cout<<ans<<"\n";
  }

  return 0;
}