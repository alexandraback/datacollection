#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#define forn(i, n ) for(int i = 0;i < (int)(n);i++)

using namespace std;
typedef long long ll;


vector<ll> c[2];
vector<ll> t[2];
ll out;

void rek(int i,int j, ll sum){
  //printf("%d %d %I64d\n",i,j,sum);
  if(i == 3 || j == t[1].size())
    out = max(out,sum);
  else{ 
    if(t[0][i] == t[1][j]){
      ll x = min(c[0][i],c[1][j]);
      //printf("%d %d %I64d %I64d %I64d %I64d\n",i,j,x,c[0][i],c[1][j],sum +x);
      c[0][i] -= x;
      c[1][j] -= x;
      rek(i+1,j,sum + x);
      rek(i,j+1,sum + x);
      c[0][i] += x;
      c[1][j] += x;
    }
    else{
      rek(i+1, j, sum);
      rek(i, j+1, sum);
    }
  }
}
int main(){
  int _;
  scanf("%d",&_);
  forn(__,_){
    printf("Case #%d: ",__ + 1);
    fprintf(stderr,"Case #%d: ",__ + 1);
    int n,m;
    scanf("%d %d",&n,&m);
    c[0].resize(n);
    t[0].resize(n);
    c[1].resize(m);
    t[1].resize(m);
    forn(i,2)
      forn(j,c[i].size())
        scanf("%I64d %I64d", &c[i][j], &t[i][j]);
    forn(i,3-n)
      c[0].push_back(0),t[0].push_back(0);
    forn(j,2)
      if(t[0][j] == t[0][j+1]){
        c[0][j] += c[0][j+1];
        c[0][j+1] = t[0][j+1] = 0;
      }
    out = 0;
    rek(0,0,0);
    printf("%I64d\n",out);    
  }
}
