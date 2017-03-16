
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
using namespace std;




void solve(ifstream& fin, ofstream& fout) {

	int n; 
	fin >> n;
	map<int, int> m;
	for ( int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < n; j++) {
			int k;
			fin >> k;
			m[k] ++;
		}

	}
	
	vector<int> ans;
	for (auto&c : m) {
		if (c.second & 1) {
			ans.push_back(c.first);
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.size() != n) std::cerr << "invalid" << endl;
	for (int i = 0; i < n; i++) {
		fout << ans[i];
		if (i == n - 1) fout << endl; else fout << " ";
	}
}

int main(int argc, char *argv[])
{
	const char* inn;
	if (argc < 2) {
		inn = "b.in";
	}
	else {
		inn = argv[1];
	}
	string in = inn;
	string out = in.replace(in.find(".in"), in.length(), ".out");
	ifstream fin(inn);
	ofstream fout(out);

	int t;
	fin >> t;
	
	for (int cs = 1; cs <= t; cs++) {
		fout << "Case #" << cs << ": ";
		solve(fin, fout);
	}
	fout.close();

	return 0;
}