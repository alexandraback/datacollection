#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long int size_pyramid(long long int d) {
  if(d<0) {
    return 0;
  }
  return (d+1)*(d+1) - (d)*(d+1)/2;
}

double fall(int d, vector<vector<double> > & P, int Y, int N) {
  if(Y<0) {
    cerr<<endl<<"  - "<<Y<<" "<<N<<" "<<1<<" (below ground)";
    return 1;
  }
  if(N-Y >= d) {
    cerr<<endl<<"  - "<<Y<<" "<<N<<" "<<1<<" (trivial)";
    return 1;
  }
  if(P[Y][N]>=0) {
    cerr<<endl<<"  - "<<Y<<" "<<N<<" "<<1<<" (cached)";
    return P[Y][N];
  }
  double sol=0;

  double mt = 1;
  for(int n=N-1;n>=0;--n) {
    mt /= 2;
    sol += fall(d, P, Y-1, n) * mt;
  }

  P[Y][N] = sol;
  cerr<<endl<<"  - "<<Y<<" "<<N<<" "<<sol;
  return sol;
}

double solve(int N, int X, int Y) {
  if(X<0) {
    X=-X;
  }
  long long int spnext = size_pyramid(X+Y);
  long long int spprev = size_pyramid(X+Y-2);

  cerr<<"n="<<N<<"  x="<<X<<"  y="<<Y<<"  d="<<X+Y<<": ";
  cerr<<"next: "<<spnext<<" prev:"<<spprev<<"    ";
  // Trivial cases
  if(N>=spnext) {
    cerr<<"Trivial 1"<<endl;
    return 1.;
  }
  if(N<=spprev) {
    cerr<<"Trivial 0"<<endl;
    return 0.;
  }
  if(X==0) {
    if(N==spnext) {
      cerr<<"X=0, filled"<<endl;
      return 1.;
    } else {
      cerr<<"X=0, not filled"<<endl;
      return 0.;
    }
  }
  N-=spprev;
  int d=X+Y+1;

  vector<vector<double> > P(d+1, vector<double>(N+1, -1));

  double sol = fall(d, P, Y, N);
  cerr<<endl;
  return sol;
}

int main(int argc, char** argv) {
  int T;
  cin>>T;

  for(int t=0;t<T;++t) {
    int N, X, Y;
    cin>>N>>X>>Y;
    double sol = solve(N, X, Y);
    cout<<"Case #"<<(t+1)<<": "<<sol<<endl;
  }

  return 0;
}
