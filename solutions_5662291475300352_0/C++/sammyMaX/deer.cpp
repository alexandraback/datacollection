#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;

ifstream fin("c.in");
ofstream fout("c.out");

int solve() {
	int n;
	fin >> n;
	if (n == 1) {
		ll sd, num, fp;
		fin >> sd >> num >> fp;
		if (num == 1) return 0;
		// now num = 2
		if ((360 - sd) * (fp + 1) >= fp * (720 - sd)) return 1;
		else return 0;
	}
	// n = 2
	ll s1, p1, s2, p2;
	fin >> s1 >> n >> p1 >> s2 >> n >> p2;
	if (p1 == p2) return 0;

	if (p1 > p2) swap(p1, p2), swap(s1, s2); // 1 is faster
	if ((720 - s1) * p1 <= (360 - s2) * p2) return 1;
	return 0;
}

int main() {
	int a;
	fin >> a;
	for (int i = 0; i < a; i++)
		fout << "Case #" << i+1 << ": " << solve() << '\n';
}
