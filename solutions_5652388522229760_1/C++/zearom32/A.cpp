#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
#include <set>
#include <string>
using namespace std;


long long count(long long k) {
	if (k == 0) return -1;
	int t = 1;
	set<int> u;
	while (1) {
		long long w = k * t;
		while (w) {
			u.insert(w % 10);
			w = w / 10;
		}
		if (u.size() >= 10) return k * t;
		t++;
	}
}

void solve(ifstream& fin, ofstream& fout) {
	long long k;
	fin >> k;
	int ans = count(k);
	if (ans == -1) 
		fout << "INSOMNIA" << endl;
	else fout << ans << endl;

}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		return 1;
		cout << "no input file" << endl;
	}
	string in = argv[1];
	string out = in.replace(in.find(".in"), in.length(), ".out");
	ifstream fin(argv[1]);
	ofstream fout(out);

	int t;
	fin >> t;

	for (int cs = 1; cs <= t;cs++) {
		fout << "Case #" << cs << ": ";
		solve(fin, fout);
	}
	fout.close();

	return 0;
}