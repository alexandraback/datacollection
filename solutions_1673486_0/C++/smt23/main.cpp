#include <iostream>
#include <fstream>

double error_exp(double *probs, int num_typed) {
	double c = 1;
	for(int i = 0; i < num_typed; ++i)
		c *= probs[i];

	return 1-c;
}

using namespace std;

double calc_exp(int t_key, double *probs, int num_typed) {
	double e = error_exp(probs,num_typed);
	return ((1-e)*(1+t_key-num_typed)+e*(2+2*t_key-num_typed)); 
}

double best_dec(int t_key, double *probs, int num_typed) {
	// If you press return and retype
	double best = 1 + t_key + 1;

	// If you continue
	for(int i = num_typed; i >=0; --i) {
		double val = (num_typed-i)+calc_exp(t_key,probs,i);
		if(val < best)
			best = val;
	}
	return best;
}

int main(int argc, char **argv) {

	ifstream in(argv[1]);
	ofstream out(argv[2]);

	int cases;
	in >> cases;

	for(int i = 0; i < cases; ++i) {
		int num_typed, total;
		in >> num_typed >> total;

		double *p = new double[num_typed];
		for(int j = 0; j < num_typed; ++j)
			in >> p[j];

		out.precision(10);
		out << "Case #" << i+1 << ": " << best_dec(total, p, num_typed);
		out << endl;
	}

	return 0;
}
