#include<iostream>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

typedef long long int LL;
LL vs[100000];
LL E,R;
int n;

LL solve(int cur, int e, int end, LL req) {
  if (cur == end) return 0;
  int maxi = cur;
  LL maxv = vs[cur];
  for(int i=cur+1; i<end; ++i) {
    if (maxv < vs[i]) {
      maxv= vs[i];
      maxi = i;
    }
  }

  LL ans = 0;
  LL max_aggr = MIN(E, e+(maxi-cur)*R);
  LL possible_aggr = R * (end-maxi);
  LL tail = 0;
  if (possible_aggr >= req) {
    //use all
    tail = solve(maxi+1, R, end, req);
    ans += tail + (max_aggr*vs[maxi]);
  } else {
    LL should_remain = req - possible_aggr;
    LL can_use = max_aggr-should_remain;
    tail = solve(maxi+1, should_remain+R, end, req);
    ans += tail + (can_use*vs[maxi]);
  }

  ans += solve(cur, e, maxi, max_aggr);
  return ans;
}



int main() {

  int cas;
  cin>>cas;


  for(int ca=1; ca<=cas; ++ca) {
    cin>>E>>R>>n;
    for(int i=0; i<n; ++i){
      cin>>vs[i];
    }
    cout<<"Case #"<<ca<<": "<<solve(0, E, n, R)<<endl;
  }

}
