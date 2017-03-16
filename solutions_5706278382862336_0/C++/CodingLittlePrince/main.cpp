#include <fstream>
#include <iostream>

using namespace std;
int gcd ( int a, int b ) {
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
int main() {
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	int cases;
	int i,j;
	int P, Q, Q_t;
	char dummy;
	int gcd_PQ;
	int generations, result;
	bool not_2_frac;

	fin >> cases;
	for(i = 0; i < cases; ++i) {
		fin >> P >> dummy >> Q;
		gcd_PQ = gcd(P, Q);
		P = P/gcd_PQ;
		Q = Q/gcd_PQ;
		generations = result = 0;
		not_2_frac = false;
		Q_t = Q;
		while(Q_t > 0) {
			generations++;
			if(Q_t > P) result++;
			if(Q_t % 2 == 1 && Q_t != 1) { not_2_frac = true; break; }
			Q_t = Q_t >> 1;
			if(generations>40) break;
			
		}
		if(generations>40 || not_2_frac) {
			fout << "Case #" << i+1 << ": impossible" << endl;
		} else {
			fout << "Case #" << i+1 << ": " << result << endl;
		}

		
	}

	fin.close();
	fout.close();
}