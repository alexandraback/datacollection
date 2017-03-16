#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define FOR(prom, a, b) for(int prom = (a); prom < (b); prom++)
#define FORD(prom, a, b) for(int prom = (a); prom > (b); prom--)
#define FORDE(prom, a, b) for(int prom = (a); prom >= (b); prom--)

#define DRI(a) int a; scanf("%d ", &a);
#define DRII(a, b) int a, b; scanf("%d %d ", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d ", &a, &b, &c);
#define DRIIII(a, b, c, d) int a, b, c, d; scanf("%d %d %d %d ", &a, &b, &c, &d);
#define RI(a) scanf("%d ", &a);
#define RII(a, b) scanf("%d %d ", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d ", &a, &b, &c);
#define RIIII(a, b, c, d) scanf("%d %d %d %d ", &a, &b, &c, &d);

#define PB push_back
#define MP make_pair

#define ll long long
#define ull unsigned long long

#define MM(co, cim) memset((co), (cim), sizeof((co)))

#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;

int wins(vector<double> A, vector<double> B) {
	int res = 0;
	int b = 0;
	FOR(a,0,A.size()) {
		if(A[a] > B[b]) {
			res++;
			b++;
		}
	}
	return res;
}

int main ()
{
  DRI(T);
  FOR(t,1,T+1) {
  	DRI(N);
  	vector<double> A, B;
  	double a;
  	FOR(i,0,N) {
  		cin >> a;
  		A.PB(a);
  	}
  	FOR(i,0,N) {
  		cin >> a;
  		B.PB(a);
  	}
  	sort(A.begin(), A.end());
  	sort(B.begin(), B.end());
  	printf("Case #%d: %d %d\n", t, wins(A,B), N-wins(B,A));
  }
  return 0;
}












