
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;


void dfs(string& src, int l, int r, string& ans, int st, int ed) {
	if (l > r) return;
	int mi = r;
	for (int i = r; i >= l; i--) {
		if (src[i] > src[mi]) mi = i;
	}
	ans[st] = src[mi];
	dfs(src, l, mi - 1, ans, st + 1, st + mi - l);
	int t = st + mi - l + 1;
	for (int j = mi + 1; j <= r; j++) {
		ans[t++] = src[j];
	}
}

void solve(ifstream& fin, ofstream& fout) {
	string s;
	getline(fin, s);
	string ans = s;
	dfs(s,0,s.length()-1, ans, 0, ans.length()-1);
	fout << ans << endl;
}

int main(int argc, char *argv[])
{
	const char* inn;
	if (argc < 2) {
		inn = "a.in";
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
	string s;
	getline(fin, s);
	for (int cs = 1; cs <= t; cs++) {
		fout << "Case #" << cs << ": ";
		solve(fin, fout);
	}
	fout.close();

	return 0;
}