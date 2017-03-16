#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MODV 1000000007

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;
void addmod(int &a, ll b){a=(a+b); if(a>=MODV)a-=MODV;}
void mulmod(int &a, ll b){a=(a*b)%MODV;}
int getint(){int a;scanf("%d",&a);return a;}
ll getll(){ll a;scanf("%lld",&a);return a;}
ll power(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) { res=res*a; }
    b >>= 1;
    a = a*a;
  }
  return res;
}

void doit() {
  ll b=getint();
  ll m=getll();
  if(m>power(2,b-2)){
    printf("IMPOSSIBLE\n");
    return;
  }
  printf("POSSIBLE\n");
  vector<string> vs;
  for(int i=0;i<b;i++){
    string s="";
    for(int j=0;j<b;j++){
      if(j>i)s+="1";
      else s+="0";
    }
    vs.pb(s);
  }
  ll mx=power(2,b-2);
  mx = mx/2;
  //while(m){
    for(int i=1;i<b;i++){
      cerr<<i<<" "<<m<<" "<<mx<<endl;
      if(m>=mx){
        m-=mx;
      }else{
        vs[0][i]='0';
      }
      if(mx>1)mx=mx/2;
    }
  //}
  for(int i=0;i<b;i++){
    printf("%s\n",vs[i].c_str());
  }
}

int main() {
  int tc;
  scanf("%d",&tc);
  for(int i=1;i<=tc;i++){
    printf("Case #%d: ",i);
    doit();
  }
  return 0;
}
