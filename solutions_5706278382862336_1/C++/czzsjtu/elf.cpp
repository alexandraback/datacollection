#include <fstream>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	long long a, b;
	int T;
	char c;

	fin >> T;
	for (int i=1; i<=T; i++) {
		fout << "Case #" << i << ": ";
		fin >> a;
		fin >> c;
		fin >> b;
		long long g = gcd(a, b);
		a = a/g;
		b = b/g;
		int ans = 1;
		while (a*2 < b) {
			a = a*2;
			ans++;
		}
		while (b%2 == 0)
			b = b/2;
		if (b != 1) ans = 0;
		if (ans == 0) 
			fout << "impossible" << endl;
		else
			fout << ans << endl;
	}
	fin.close();
	fout.close();
}
