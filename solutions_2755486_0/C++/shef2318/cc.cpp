#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define ll long long

using namespace std;

int N;
set< pair<int, int> >q;
int d[110], n[110], w[110], e[110], s[110], dd[110], dp[110], ds[110], at[110];
int wall[100100], add=50000;

inline bool check(int x)
{
    bool ok=0;   
    //cout<<w[x]+at[x]*dp[x]-add<<" "<<e[x]+at[x]*dp[x]-add<<" "<<s[x]+ds[x]*at[x]<<endl;
    for (int i=w[x]+at[x]*dp[x]; i<=e[x]+at[x]*dp[x]; i++)
        if (  wall[i]<s[x]+ds[x]*at[x]  )
           ok=1;
    //cout<<ok<<endl;
    return ok;   
}
inline pair< pair<int, int>, int >Q(int x)
{
       return make_pair( make_pair(w[x] + at[x]*dp[x], e[x] + at[x]*dp[x]), s[x] + at[x]*ds[x] );
}
void solve(int test)
{
      q.clear();
      for (int i=0; i<100100; i++)
          wall[i]=0;
      int ans=0;
      cin>>N;
      for (int i=1; i<=N; i++)
          cin>>d[i]>>n[i]>>w[i]>>e[i]>>s[i]>>dd[i]>>dp[i]>>ds[i],
          w[i]*=2, e[i]*=2, dp[i]*=2,
          w[i]+=add, e[i]+=add, at[i]=0,
          q.insert( make_pair(d[i], i) );
      while ( !q.empty() )
      {
            int day=(*q.begin()).X;
            vector< pair<pair<int, int>, int> >upd;
            while ( !q.empty() && (*q.begin()).X==day )
            {
                  int tribe=( *q.begin() ).Y;
                  
                  ans+=check( tribe );
                  upd.push_back( Q(tribe)  );
                  at[tribe]++;
                  if ( at[tribe]<n[tribe] )
                     q.insert( make_pair(day+dd[tribe], tribe) );
                  q.erase(q.begin());
            }
            for (int i=0; i<upd.size(); i++)
                for (int j=upd[i].X.X; j<=upd[i].X.Y; j++)
                    wall[j]=max( wall[j], upd[i].Y );
      } 
      printf("Case #%d: %d\n", test, ans);
}
int main ()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
        solve(i);
    cin>>t;    
    return 0;
}
