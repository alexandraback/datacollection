#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef long long ll;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp make_pair
#define go(i,n) for(int i=0;i<n;i++)
#define go3(i,j,n) for(int i=j;i<n;i++)
#define inf 1000000000

vvi g;
int n;
vi vis;

bool dfs(int v,int c){
  vis[v]=c;
  go(i,sz(g[v]))
  {
   int to=g[v][i];
   if(vis[to]==c) return true;
   if(dfs(to,c)) return true;
  }
  return false;
}

bool func(){
  
  vis.assign(n,-1);
  go(i,n)
  if(vis[i]==-1) 
   if(dfs(i,i)) return true;
  return false;
}

void oku(){

 int T,m,t;
 cin>>T;
 for(int i=1;i<=T;i++){
  printf("Case #%d: ",i);
  cin>>n;
  g.clear();
  g.resize(n,vi(0));
  
  go(i,n){
  cin>>m;
  go(j,m)
   {
    cin>>t;
    g[i].pb(t-1);
   }
  }
 if(func()) cout<<"Yes";
 else cout<<"No";
 cout<<endl;
 }

}

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
#endif

oku();

return 0;}