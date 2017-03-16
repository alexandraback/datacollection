#include <fstream>
#include <string>
using namespace std;

long long int reduce(long long int P, long long int Q) {
	while (P > 0) {
		long long int tmp = P;
		P = Q % P;
		Q = tmp;
	}
	return Q;
}

int main(int argc, char** argv) {
	ifstream ifile(argv[1]);
	ofstream ofile(argv[2]);

	int T; ifile >> T;
	for (int tc = 1; tc <= T; tc++) {
		string line; ifile >> line;

		size_t p;
		p = line.find("/");

		long long int P;
		P = stoll(line.substr(0, p));
		long long int Q;
		Q = stoll(line.substr(p + 1));

		long long int lcf = reduce(P, Q);
		P /= lcf;
		Q /= lcf;

		long long int g = 0;

		long long int n = Q;
		while (n != 1) {
			if (n % 2 != 0) {
				g = -1;
				break;
			}
			n /= 2;
			g++;
		}

		if (g != -1 && P > Q / 2) g = 1;
		else {
			if (g != -1) {
				long long int corrector = 0;
				long long int tmp = 1;
				while (tmp < P) {
					tmp *= 2;
					tmp++;
					corrector++;
				}
				g -= corrector;
			}
		}

		ofile << "Case #" << tc << ": ";
		if (g != -1) ofile << g;
		else ofile << "impossible";
		ofile << endl;
	}

	return 0;
}