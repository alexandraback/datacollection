#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>

// #include "Integer.h"
#define Integer int

using namespace std;

#define InputVector(v, Type) vector<Type> v; { Type t; int _n; cin >> _n; v.reserve(_n); while (--_n >= 0) { cin >> t; v.push_back(t); } }

bool debug = false;

vector< vector<int> > C, F;
vector< vector<Integer> > T;
int H, N, M;

bool computeTimeToMove(int i0, int j0, int i1, int j1, const Integer &t0, Integer &t1, int pass) {
  if (C[i1][j1] - F[i0][j0] < 50) return false;
  if (C[i1][j1] - F[i1][j1] < 50) return false;
  if (C[i0][j0] - F[i1][j1] < 50) return false;

  if (pass==0) {
    if (C[i1][j1] - 50 < H) return false;
    t1 = t0;
  } else {
    t1 = -(C[i1][j1] - 50 - H);
    if (t1 < t0) t1 = t0;

    if ((H - t1) - F[i0][j0] >= 20)
      t1 += 10;
    else 
      t1 += 100;
  }

  return true;
} 

int main(void) {
  int iTest, nTests; cin >> nTests;
  Integer negOne(-1);

  for (iTest = 1; iTest <= nTests; ++iTest) {
    cerr << iTest << "/" << nTests << "\n";

    cin >> H >> N >> M;

    C.resize(N); F.resize(N); T.resize(N);

    int i, j;
    for (i = 0; i < N; ++i) {
      T[i].resize(M);
      C[i].resize(M);
      for (j = 0; j < M; ++j)
	cin >> C[i][j];
    }

    for (i = 0; i < N; ++i) {
      F[i].resize(M);
      for (j = 0; j < M; ++j)
	cin >> F[i][j];
    }

    for (i = 0; i < N; ++i)
      for (j = 0; j < M; ++j)
	T[i][j] = -1;
    T[0][0] = 0;
      
    for (int pass = 0; pass <= 1; ++pass) {
      bool stable = false;
      while (!stable) {
	stable = true;
	Integer t;
	
	for (i = 0; i < N; ++i)
	  for (j = 0; j < M; ++j)
	    if (T[i][j]!=negOne) {
	      if (i-1 >= 0) {  // Up?
		if (computeTimeToMove(i, j, i-1, j, T[i][j], t, pass)
		    && (T[i-1][j]==negOne || t < T[i-1][j])) {
		  T[i-1][j] = t;
		  stable = false;
		}
	      } 
	      if (i+1 < N) { // Down?
		if (computeTimeToMove(i, j, i+1, j, T[i][j], t, pass)
		    && (T[i+1][j]==negOne || t < T[i+1][j])) {
		  T[i+1][j] = t;
		  stable = false;
		}
	      } 
	      
	      if (j-1 >= 0) {  // Left?
		if (computeTimeToMove(i, j, i, j-1, T[i][j], t, pass)
		    && (T[i][j-1]==negOne || t < T[i][j-1])) {
		  T[i][j-1] = t;
		  stable = false;
		}
	      } 
	      if (j+1 < M) { // Right?
		if (computeTimeToMove(i, j, i, j+1, T[i][j], t, pass)
		    && (T[i][j+1]==negOne || t < T[i][j+1])) {
		  T[i][j+1] = t;
		  stable = false;
		}
	      } 
	    }
      }

      if (T[N-1][M-1] >= 0) {
	cout << "Case #" << iTest << ": ";
	cout << T[N-1][M-1]/10.0;
	cout << "\n";
	break;
      }
    }
  }

  return 0;
}
