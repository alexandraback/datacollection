#include <climits>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <queue>
using namespace std;
const int NMAX=10000;
double p2[NMAX];

void run(int case_index) {
  double res=0; int n,x,y; cin>>n>>x>>y; x=abs(x);
  int k=0,t=1; while(not (t<=n and n<t+4*k+5)) t += 4*k+5, k++;
  if(x+y<=2*k) res=1;
  else if(x+y==2*k+2){
    int m=n-t, l; double p=1;
    vector<double> q(2*k+3);
    for (int i = 0; i <= m; i++){
      if (i>=2*k+3) l=2*k+2;
      else if (m-i>=2*k+3) l=m-(2*k+2);
      else l=i;
      q[l] += p*p2[m-i];
      p*=0.5*(m-i)/(i+1);
    }
    for (int l = y+1; l < 2*k+3; l++)
      res += q[l];
  }
  else res=0;
  cout << "Case #" << case_index << ": " << res;
  cout << endl;
}

int main(int argc, char* argv[]) {
  p2[0]=1; for (int k = 0; k < NMAX; k++) p2[k+1] = p2[k]*0.5;
  int n; cin >> n;
  for(int i = 1; i <= n; i++){
    cerr << i << " ";
    run(i);
  }
  cerr << endl;
  return 0;
}
