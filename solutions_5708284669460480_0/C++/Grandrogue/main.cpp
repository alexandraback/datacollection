#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream fin("B-small-attempt4.in");
ofstream fout("out.txt");

int main() {
	int tests;
	fin >> tests;
	int n, m, k;
	string s1, s2;
	for(int test = 0; test < tests; ++test) {
		int a[7], it = 0;
		fin >> n >> m >> k;
		fin >> s1;
		fin >> s2;
		for(int i = 0; i < k; i++)
			a[i] = 0;
		int maxBananas = 0;
		int allBananas = 0;
		double ans = 0;
		bool flag = true;
		while (flag) {
			++it;
			string s = "";
			int curBananas = 0;
			for(int i = 0; i < k; ++i) {
				s += s1[a[i]];
			}
			int found = s.find(s2);
			while(found != string::npos) {
				++curBananas;
				found = s.find(s2, found + 1);
			}
			maxBananas = max(maxBananas, curBananas);
			allBananas += curBananas;
			int j = k - 1;
			while(j >= 0 && a[j] == n - 1) {
				a[j] = 0;
				--j;
			}
			if(j == -1) flag = false; else
			    ++a[j];
		}
		fout << "Case #" << test + 1 << ": " << (double)maxBananas - (double)allBananas / (double)it << endl;
	}
	return 0;
}
