#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define ri(X) scanf("%d", &(X))
#define pi(X) printf("%d", (X))
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define lint long long
#define pii pair<int,int>
#define inf 1e9
#define linf 1e18
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define uni(X) X.erase(unique(X.begin(), X.end()), X.end());
const int mn = 1e5+9;
lint T;
lint L,X,LX;
int h(char c){
  if(c == 'i') return 1;
  if(c == 'j') return 2;
  if(c == 'k') return 3;
}
string s;
vector<int> ve;
int p[4][4] = {{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
int b[4][4] ={{0,0,0,0},{0,1,0,1},{0,1,1,0},{0,0,1,1}};


class par{
public:
  int v, w;
  par(int ww= 0, int vv =0){
    v = vv;
    w = ww;
  }
  par operator*(par s){
    return par((w+s.w+b[v][s.v])%2, p[v][s.v]);
  }
  void print(){
    printf("[%d %d]\n", w, v);
  }
};

par exp(par a, long long b){
  par result = par(0,0);
  par power = a;
  while(b>0) {
    if (b%2==1) result = (result*power);
    power = (power*power);
    b = b/2;
  }
  return result;
}


par g(int z, int v, int w){
  
  if(z%L== 0 && z != 0 ){
    return par(w,v);
  }
  
  int i = z%L;
  //printf("%d %d %d %d\n", i, z, v, w);
  int nv = p[v][ve[i]];
  int nw = (w+b[v][ve[i]])%2;
  return g(z+1, nv, nw);
}


const int mz = 1000000;
bool visit[mn][4][2];
int obj;
int f(int z, int v, int w){
  
  assert(z < mz);
  int i = z%L;
  //printf("%d %d %d %d\n", z, i,  v, w);
  if(obj == v && w == 0) return z-1;	
  
  if(visit[i][v][w] || z>= LX) return -1;
  visit[i][v][w] = 1;
  
  
  int nv = p[v][ve[i]];
  int nw = (w+b[v][ve[i]])%2;
  return f(z+1, nv, nw);
}

bool solve(){
  LX = L*X;
  ve.clear();
  for(int i = 0; i < s.size(); i++){
    ve.pb(h(s[i]));
  }

  lint ii, ij, ik;
  obj = 1;
  memset(visit,0,sizeof(visit));
  ii = f(0,0,0);
  
  if(ii==-1) return 0;
  
  obj = 2;
  memset(visit,0,sizeof(visit));
  ij = f(ii+1,0,0);
  
  if(ij==-1) return 0;
  
  obj = 3;
  memset(visit,0,sizeof(visit));
  ik = f(ij+1,0,0);
  
  
  
  lint b = X-((ik+1ll+L-1)/L);
  //cout << LX << " " << ik << " " << b << endl;
  par w = g(ik+1,0,0)*exp(g(0,0,0),b);
  
  return w.w==0 && w.v==0;
  //return ;
  
}

int main(){
 
  cin >> T;
  for(int t = 0; t < T; t++){
    cin >> L >> X;
    cin >> s;
    printf("Case #%d: %s\n",t+1, solve()?"YES":"NO");
  }
  return 0;
}

