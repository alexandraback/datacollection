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
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SUM(a) accumulate(all(a),string())
#define online1
#define RAND ((rand()<<15)+rand())
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;

int T;

int main(){
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  cin>>T;
  Rep(tt,1,T){
    cout<<"Case #"<<tt<<": ";

    double c,f,x;
    cin>>c>>f>>x;
    double ans=1e30, now=0.0;
    Rep(n,0,(int)x){
      ans=min(ans,now+x/(2.0+n*f));
      now+=c/(2.0+n*f);
    }
    printf("%.7f\n", ans);
  }
  return 0;
}
