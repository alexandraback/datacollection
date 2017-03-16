#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int partial_solve(int A, int N, vector<int> const& M) {
  int s = 0;
  for(int n=0;n<N;++n) {
    int m = M[n];
    while(A<=m) {
      // Generate a mote of size A-1
      A += A-1;
      s++;
    }
    A += m;
  }
  return s;
}

int solve() {
  // Our mote
  int A;
  cin>>A;
  // Number of motes
  int N;
  cin>>N;
  // Size of motes
  vector<int> M;
  for(int n=0;n<N;++n) {
    int m;
    cin>>m;
    M.push_back(m);
  }
  sort(M.begin(), M.end());

  // We can never grow our mote
  if(A == 1) {
    return N;
  }

  // After 20 max-groth, the mote reaches max size
  int max_remove = 22;

  int best = N;
  for(int i=0;i<max_remove && i<=N; ++i) {
    int s = partial_solve(A, N-i, M);
    if(s+i < best) {
      best = s+i;
    }
  }

  return best;
}

int main(int argc, char** argv) {
  int T;
  cin>>T;

  for(int t=0;t<T;++t) {
    int sol = solve();
    cout<<"Case #"<<(t+1)<<": "<<sol<<endl;
  }

  return 0;
}
