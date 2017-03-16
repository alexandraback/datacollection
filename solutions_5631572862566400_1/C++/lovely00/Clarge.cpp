// Author: Xujie Si
// Email: six@gatech.edu
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

#define FOR(i,X) for(int i=0;i<(X);++i)
#define PB(X) push_back( (X) )

typedef long long LL;
typedef vector<int> VI;

priority_queue<int> maxQ; // largest on the top
priority_queue<int, VI, greater<int> > minQ; // smallest on the top

typedef  std::pair<int, std::pair<int,int> > RT;

const int N = 1010;
//int d[N];
int f[N];
int len[N];
int dep[N];
bool in[N];
bool vis[N];
RT res[N];


int max_circle = -1;

RT visit(int x, int d){
  if(vis[x]) {
    return res[x];
  }

  if(f[ f[x] ] == x){ // a good pair
    vis [x] = true;
    res[x] = std::make_pair(0, std::make_pair(1, x));
    return res[x];
  }

  if( in[ f[x] ] ){ // a circle
    //cout <<"find a circle: x=" << x <<", d="<<d << ",  f[x]=" << f[x] << ",  d0=" << dep[ f[x] ] << endl; 
    int ct = d - dep[ f[x] ] + 1;

    if(ct > max_circle) {
      max_circle = ct;
    }

    vis[x] = true;
    res[x] = std::make_pair(-1, std::make_pair(-1, -1));
    return res[x];
  }


  dep[x] = d;

  in[x] = true;

  RT r = visit( f[x], d + 1 );
  
  in[x] = false;

  if(r.first == -1){
    vis[x] = true;
    res[x] = r;
    return res[x];
  }
  else if(r.first == 0){
    vis[x] = true;
    res[x] = std::make_pair(0, std::make_pair(r.second.first + 1, r.second.second )  );
    
    return res[x];
  }
  else{
    cerr << "unkown status: (" << r.first << ", (" << r.second.first << ", " << r.second.second << ")" << endl;
  }

  return r;
}


void solve(){
	// exact implementation appears here

  max_circle = 0;
  for(int i=0; i < N; ++i) {
    len[i] = dep[i] = 0;
    in[i] = vis[i] = false;
  }

  int n;
  cin >> n;
  for(int i = 0; i < n ;++i){
    cin >> f[i];
    --f[i];
  }

  for(int i=0;i<n;++i) {
    RT r = visit(i,0);
    if(r.first == 0){
      int key = r.second.second;
      int val = r.second.first;

      if(len[key] < val) {
	len[key] = val;
      }
    }
  }


  int ans = 0;
  for(int i=0; i< n; ++i){
    //cout <<"len[" <<i << "]=" << len[i] << endl;
    ans += len[i];
  }
  //cout << "sum = " << ans << endl;

  if(ans < max_circle){
    ans = max_circle;
  }


  cout << ans << endl;
}


int main()
{
  int cs = 0, T;
  scanf("%d",&T);
  while(++cs <= T){
    printf("Case #%d: ", cs);
    solve();
  }
  return 0;
}
