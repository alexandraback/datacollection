#include <fstream>
#include <string>
#include <set>
using namespace std;

ifstream fin("C-small-attempt1.in");
ofstream fout("out.txt");

string first[1000];
string second[1000];
bool isFake[1000];
bool isTrue[1000];

int main() {
	int tests;
	fin >> tests;
	for (int test = 0; test < tests; ++test) {
		int n;
		fin >> n;
		int ans = 0;
		set<string> firsts, seconds;
		memset(isFake, 0, sizeof(isFake));
		memset(isTrue, 0, sizeof(isTrue));
		for (int i = 0; i < n; ++i) {
			fin >> first[i] >> second[i];
		}
		for (int i = 0; i < n; ++i) {
			bool isUnique = true;
			for (int j = 0; j < n; ++j) {
				if (i != j && first[i] == first[j]) {
					isUnique = false;
				}
			}

			if (isUnique) {
				isTrue[i] = true;
				firsts.insert(first[i]);
					seconds.insert(second[i]);
					++ans;
			} else {
				isUnique = true;
				for (int j = 0; j < n; ++j) {
				    if (i != j && second[i] == second[j]) {
					    isUnique = false;
				    }
			    }
				if (isUnique) {
					isTrue[i] = true;
					firsts.insert(first[i]);
					seconds.insert(second[i]);
					++ans;
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			int maxscore = 0;
			int pos = 0;
			for(int j = 0; j < n; ++j) {
				int curscore = 0;
				if (!isTrue[j] && firsts.find(first[j]) == firsts.end()) curscore++;
				if (!isTrue[j] && seconds.find(second[j]) == seconds.end()) curscore++;
				if (curscore > maxscore) {
					maxscore = curscore;
					pos = j;
				}
			}

			if (maxscore == 0) break; else {
				isTrue[pos] = true;
				firsts.insert(first[pos]);
				seconds.insert(second[pos]);
				++ans;
			}
		}

		fout << "Case #" << test + 1 << ": " << n - ans << endl;
	}

	return 0;
}
