#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	ifstream fin("C-small-attempt1.in"); ofstream fout("output.txt");

	int t, n, ans;
	string s1, s2;
	fin >> t;

	for (int k = 1; k <= t; k++) {
		fin >> n;
		ans = 0;
		vector<string> vec1, vec2;
		map<string, int> m1, m2;
		
		for (int i = 0; i < n; i++) {
			fin >> s1 >> s2;
			vec1.push_back(s1);
			vec2.push_back(s2);
			m1[s1]++;
			m2[s2]++;

			if (m1[vec1[i]] > 1 && m2[vec2[i]] > 1) {
				ans++;
			}
		}

		fout << "Case #" << k << ": " << ans << endl;
	}

	fin.close(); fout.close();
	return 0;
}