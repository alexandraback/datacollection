#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	ifstream ifile(argv[1]);
	ofstream ofile(argv[2]);

	int T; ifile >> T;
	for (int tc = 1; tc <= T; tc++) {
		string line; ifile >> line;

		size_t p;
		p = line.find("/");

		int P;
		P = stoi(line.substr(0, p));
		int Q;
		Q = stoi(line.substr(p + 1));

		int g = 0;

		int n = Q;
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
				int corrector = 0;
				int tmp = 1;
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