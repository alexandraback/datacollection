#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ifstream fin("A-large.in");
ofstream fout("out.txt");

int main() {
	int tests;
	fin >> tests;
	int n, m, k;
	for(int test = 0; test < tests; ++test) {
		fin >> n >> m >> k;
		int ans = n * (m / k) + (k - 1);
		if (m % k) ++ans;
		fout << "Case #" << test + 1 << ": " << ans << endl;
	}
	return 0;
}
