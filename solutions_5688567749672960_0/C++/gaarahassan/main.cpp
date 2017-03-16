#include <bits/stdc++.h>
#define mp make_pair
#define ll long long

using namespace std;
vector <int> v;
vector <pair<int,int> > tt;
vector <int> q;
bool visited [1000005];

ll bfs (ll a , ll i)
{
   ll ans =1;
   queue <pair<ll,ll> > q;
   q.push(mp(i,1));
   while(!q.empty())
   {
       pair<ll,ll> b = q.front();
       q.pop();
       if(visited[b.first])
        continue;
       visited[b.first]=true;

       if(b.first==a)
        return b.second;
       q.push(mp(b.first+1,b.second+1));
       ll t =0;
       while(b.first>0)
       {
           t*=10;
           t+=b.first%10;
           b.first/=10;
       }
       q.push(mp(t,b.second+1));
   }
}

int main()
{
   freopen("in.txt" , "r" , stdin);
   freopen("out.txt" , "w" , stdout);
    int t;
    int a ;
    cin >> t ;
    a=0;
    while(a++ < t)
    {
        memset(visited,false,sizeof(visited));
        ll n;
        cin >> n;
        ll ans = bfs(n , 1);
        cout << "Case #" << a << ": " << ans << endl;
    }
}



