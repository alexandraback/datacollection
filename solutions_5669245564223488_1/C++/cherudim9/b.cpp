#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#define sz(a) ((int)(a).size())
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define Rep(i,j,k) for (int i=(j); i<=(k); i++)
#define Repd(i,j,k) for (int i=(j); i>=(k); i--)
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SUM(a) accumulate(all(a),string())
#define online1
#define RAND ((rand()<<15)+rand())
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;

const int MOD=1000000007;

int n;
int b[110], c[110], d[110];
string a[110], aa[110];
LL ret;

bool mergeandjudge(char ch){
  int bb=0, cc=0;
  Rep(i,1,n){
    b[i]=c[i]=d[i]=0;
    if (a[i].find(ch)==-1){
      continue;
    }
    d[i]=1;
    
    int x=a[i].find(ch);
    while(x!=-1){
      int y=a[i].find(ch,x+1);
      if (y==-1)
        break;
      if (y!=x+1)
        return 0;
      x=y;
    }

    if (a[i].find(ch)!=0)
      b[i]=1;
    if (a[i].find_last_of(ch)!=sz(a[i])-1)
      c[i]=1;
    bb+=b[i];
    cc+=c[i];
  }
  if (bb>1 || cc>1)
    return 0;
  string s;
  Rep(i,1,n)
    if (d[i])
      if (b[i])
        s+=a[i];
  int now=0;
  Rep(i,1,n)
    if (d[i])
      if (!b[i] && !c[i])
        s+=a[i], now++, ret=ret*now%MOD;
  Rep(i,1,n)
    if (d[i])
      if (c[i] && !b[i])
        s+=a[i];
  int m=0;
  Rep(i,1,n)
    if (!d[i])
      aa[++m]=a[i];
  if (s!="")
    aa[++m]=s;
  n=m;
  Rep(i,1,m)
    a[i]=aa[i];
  return 1;
}

int main(){
  freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);

  int T;
  cin>>T;
  Rep(tt,1,T){
    cout<<"Case #"<<tt<<": ";
    cin>>n;
    Rep(i,1,n)
      cin>>a[i];
    bool flag=1;
    ret=1;
    Rep(c,0,25){
      if (!mergeandjudge('a'+c))
        flag=0;
      // cout<<"after "<<c<<": ";
      // Rep(i,1,n) cout<<a[i]<<", ";
      // cout<<endl;
      // cout<<ret<<endl;
    }
    if (!flag){
      puts("0");
      continue;
    }
    Rep(i,1,n)
      ret=ret*i%MOD;
    cout<<ret<<endl;
  }

  return 0;
}
