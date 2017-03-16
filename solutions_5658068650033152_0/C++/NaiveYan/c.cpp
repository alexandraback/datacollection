#include <cstdlib>
#include <fstream> 

using namespace std;

int main() {
	ifstream fin("c.in");
	ofstream fout("c.out");
	int t, n, m, k, x, y;
	fin >> t;
	for(x = 1; x <= t; x++) {
		fin >> n >> m >> k;
		y = rand() % (n * m - k + 1) + k;
		fout << "Case #" << x << ": " << y << "\n";
	}
	return 0;
}
