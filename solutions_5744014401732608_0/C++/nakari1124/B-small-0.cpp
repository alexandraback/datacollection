#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long i64;

typedef i64 int_t;

typedef pair<i64, i64> pi;

typedef vector<int_t> vi;
typedef vector<vi> vvi;
#define pb push_back
#define iter(T) T::iterator
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(auto i = (c).begin(); i != (c).end(); ++i)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(s, e, n)  for(n = (s); n < (e); ++n)

void matMul(const vvi &A, const vvi &B, vvi &C) {
  i64 n = A.size(), i, j, k;
  C.resize(n);
  REP(0, n, i) {
    C[i].resize(n);
    REP(0, n, j) {
      C[i][j] = 0;
      REP(0, n, k) {
	C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

class Solver {
public:
  Solver() {}
  ~Solver() {}

  void solve();
};

void Solver::solve() {
  i64 B, M;
  cin >> B >> M;
  unsigned long long bits, bits_end = 1 << (B * (B - 1) / 2);
  vvi Adj(B, vi(B));
  bool found = false;
  REP(0, bits_end, bits) {
    vvi Adj1(B, vi(B, 0));
    bool valid = true;
    i64 i, j;
    
    i64 bidx = 0;
    REP(0, B-1, i) {
      REP(i+1, B, j) {
	i64 val = ((bits & (1 << bidx)) != 0) ? 1 : 0;
	bidx++;

	Adj[i][j] = val;
      }
    }
    REP(0, B, i) {
      Adj1[i][i] = 1;
    }

    if(!valid) {
      continue;
    }

      i64 k;
#if 0
      REP(0, B, j) {
	REP(0, B, k) {
	  cout << Adj[j][k];
	}
	cout << endl;
      }
      cout << endl << endl;;
     #endif 
    vvi Adj2;
    i64 count = 0;
    REP(0, B+1, i) {
      matMul(Adj, Adj1, Adj2);
      Adj1 = Adj2;


      bool zero = true;
      REP(0, B, j) {
	if(Adj1[j][j] != 0) {
	  valid = false;
	  break;
	}
	REP(0, B, k) {
	  if(Adj1[j][k] != 0) {
	    zero = false;
	  }
	}
      }
      if(zero) {
	break;
      }

      count += Adj1[0][B-1];
      if(count > M) {
	break;
      }

      if(!valid) {
	break;
      }
    }

    if(valid && count == M) {
      found = true;
      break;
    }
  }

  if(!found) {
    cout << "IMPOSSIBLE" << endl;
  }
  else {
    cout << "POSSIBLE" << endl;
    i64 i, j;
    REP(0, B, i) {
      REP(0, B, j) {
	cout << Adj[i][j];
      }
      cout << endl;
    }
  }
}

int main(int argc, char *argv[]){
  i64 T;
  cin >> T;
  getchar();
  i64 t;

  REP(0, T, t) {
    Solver s;
    cout << "Case #" << t + 1 << ": ";
    s.solve();
  }

  return 0;
}

