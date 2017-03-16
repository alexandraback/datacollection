#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;

int main(){
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);

  int T;
  cin >> T;
  for(int i=1;i<=T;i++){
    int N,sum=0;
    vi V;
    cin >> N;
    for(int j=0;j<N;j++){
      int ni; cin >> ni;
      V.push_back(ni);
      sum += ni;
    }

    vd sol;
    for(int j=0;j<N;j++){
      double mi;
      mi = 2*sum;
      mi /= N;
      mi -= V[j];
      mi /= (double)sum;
      sol.push_back(mi);
    }
    cout << "Case #" << i << ":";
    for(int j=0;j<N;j++)
      printf(" %lf",100.*sol[j]);
    cout << endl;
  }
  return 0;
}
