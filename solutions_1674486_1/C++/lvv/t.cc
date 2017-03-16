#include "scc/cj.h"		// http://github.com/lvv/scc
//#include "lvv/lvv.h"

#define BS  1000

bool setbit(bitset<BS>& B, vector<vint>& VV, int n) {
	if (B[n]) return false;
	B.set(n);

	for(int nn: VV[n]) {
		if(!setbit(B, VV,  nn))
			return false;
	}
	return true;
}

int main() {
	size_t tt(in);  NL;

	for(size_t t=1;  t<=tt;  t++)  {
		cout << "Case #" <<  t << ": ";

		int N(in); NL;  vector<vint> VV(N);
		// input
		iFOR(N)   {
			int M = in;
			jFOR(M) VV[i] << (int(in)-1);
		}

		// bitset ctor
		vector<bitset<BS>> BB(N);

		// walk bitset
		iFOR(N)   {
			if (!setbit(BB[i], VV,  i))  {
					_ "Yes";
					goto next_test_case; 
			}
		}
		_ "No";
		next_test_case:;
		_ endl;
				//			__ N; __ VV; __ BB;
	}
}
