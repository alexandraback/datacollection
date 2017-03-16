#include<iostream>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
// #define DEBUG

using namespace std;

// typedef pair<int,int>P;
// typedef complex<double>P;

typedef long long int ll;
typedef unsigned long long int ull;

const int INF = 1e9;
const double EPS=1e-9;

int solve(){
  int R,C,W;
  cin >> R >> C >> W;
  return W + C/W*R + ((C - C/W*W) != 0) - 1;
}

int main(int argc, char *argv[])
{
  int T;
  cin >> T;
  for(int i = 1 ; i <= T ; i++){
    cout << "Case #" << i << ": " << solve() << endl;
  }
  return 0;
}
