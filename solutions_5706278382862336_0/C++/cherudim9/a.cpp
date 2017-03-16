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

LL gcd(LL a, LL b){
  if (!b) return a;
  return gcd(b,a%b);
}

bool pw2(LL a){
  if (a==0) return 1;
  if (a==1) return 1;
  return a%2==0 && pw2(a/2);
}

LL num(string a){
  stringstream O;
  O<<a;
  LL ret;
  O>>ret;
  return ret;
}

int main(){
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);

  int T;
  cin>>T;
  Rep(tt,1,T){
    cout<<"Case #"<<tt<<": ";
    string s;
    cin>>s;
    int i=s.find('/');
    LL P,Q;
    P=num(s.substr(0,i));
    Q=num(s.substr(i+1));
    LL ddd=gcd(P,Q);
    P/=ddd;
    Q/=ddd;

    if (!pw2(Q)){
      puts("impossible");
    }else{
      int ans=0;
      LL now=1;
      while(now*P<Q){
        now<<=1;
        ans++;
      }
      cout<<ans<<endl;
    }
  }

  return 0;
}
