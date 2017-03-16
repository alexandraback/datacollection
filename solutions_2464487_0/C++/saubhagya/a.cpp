#include <cmath>
#include <fstream>

using namespace std;

ifstream in("input_a.txt");
ofstream out("output_a.txt");

double r, a;

int main() {
	unsigned long long t;
	in >> t;
	
	for (unsigned long long i = 0; i < t; i++) {
		in >> r >> a;
		out << "Case #" << (i + 1) << ": " << (unsigned long long)((unsigned long long)(sqrt(8 * a + (2 * r - 1) * (2 * r - 1)) + 1 - 2 * r) / 4) << endl;
	}
	return 0;
}
