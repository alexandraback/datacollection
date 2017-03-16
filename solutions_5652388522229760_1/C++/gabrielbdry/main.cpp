#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char** argv) {
	ifstream file("txt.in");

	if (file.is_open()) {
		string out = "";
		int tests;
		file >> tests;
		for (int i = 1; i <= tests; ++i) {
			unsigned long long int n;
			file >> n;
			if (n == 0) {
				out += "Case #" + to_string(i) + ": INSOMNIA\n";
			}
			else {
				set<char> numbers;
				int it = 1;
				while (numbers.size() < 10) {
					string tmp = to_string(n);
					for (int j = 0; j < tmp.length(); ++j) {
						numbers.insert(tmp[j]);
					}
					if (numbers.size() == 10) {
						out += "Case #" + to_string(i) + ": " + tmp + '\n';
						break;
					}
					n *= (it + 1);
					n /= it;
					++it;
				}
			}
		}

		ofstream ofile("txt.out");
		ofile.clear();
		ofile << out;
	}

	return 0;
}