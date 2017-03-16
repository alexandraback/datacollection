#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

long double exp_in_ctn(vector<double> &prob, int A, int B) {
	double crct = 1;
	for (int i = 0; i < A; i++) {
		crct *= prob[i];
	}
	long double e = 2*B-A+2-crct*(long double)(B+1);
	return e;
}

int main(int argc, const char * argv[])
{
	ifstream ifs( "Input.txt" );
    int T = 0;
    ifs >> T;
    for (int i = 0; i < T; i++) {
		int A, B;
		ifs >> A >> B;
		vector<double> prob;
		for (int j = 0; j < A; j++) {
			double p;
			ifs >> p;
			prob.push_back(p);
		}
		vector<double> exp;
		
		for (int j = 0; j < A+1; j++) {
			double e = j + exp_in_ctn(prob, A-j, B);
			exp.push_back(e);
		}
		
		exp.push_back(B+2);
		sort(exp.begin(), exp.end());
		cout << "Case #" << i+1 << ": ";
		printf("%f\n",exp[0]);
	}
}

