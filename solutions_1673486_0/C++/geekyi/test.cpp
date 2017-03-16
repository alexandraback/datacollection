#include <iostream>

using namespace std;

int main() {
	int tests;
	std::cin >> tests;
	double * expect = new double[tests];

	for (int i = 0; i < tests; i ++) {
		int A, B;
		std::cin >> A;
		std::cin >> B;
		double * poss = new double[A];
		double tmp_exp = B + 2;

		double * accum_poss = new double[A];
		for (int k = 0; k < A; k ++) {
			if (k == 0) {
				std::cin >> accum_poss[0];
			}
			else {
				double tmp_poss;
				std::cin >> tmp_poss;
				accum_poss[k] = accum_poss[k-1] * tmp_poss;
			}
		}
		
		for (int j = 0 ; j <= A; j ++) {
			double est = (B-A+2*j+1) * accum_poss[A-j-1]
				    +(2*B-A+2*j+2) * (1 - accum_poss[A-j-1]);
			if (est < tmp_exp)
				tmp_exp = est;
		}

		expect[i] = tmp_exp;

		delete(poss);		
	}

	for (int i = 0; i < tests; i ++) {
		std::cout << "Case #" << (i+1) << ": ";
		std::cout.setf(ios::fixed,ios::floatfield);
		std::cout << expect[i] << std::endl;
	}

	delete(expect);
	return 0;
}
