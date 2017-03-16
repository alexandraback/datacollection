#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>

using namespace std;

const string s[10] = {"ZERO", "TWO", "SIX", "EIGHT", "FOUR", "THREE", "ONE", "FIVE", "NINE", "SEVEN"};
const int a[10] = {0, 2, 6, 8, 4, 3, 1, 5, 9, 7};
const string number[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main()
{
	ifstream ifs("a.in");
	ofstream ofs("a.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		string s;
		string res;
		ifs >> s;
		map<char, int> m;
		for (char ch : s) m[ch]++;

		for (int index : a) {
			bool good = true;
			while (good) {
				for (char ch : number[index]) {
					m[ch]--;
					if (m[ch] < 0) good = false;
				}
				if (good) {
					res += char('0' + index);
				} else {
					for (char ch : number[index]) {
						m[ch]++;
					}
				}
			}
		}
		sort(res.begin(), res.end());
		ofs << "Case #" << test+1 << ": " << res << endl;
	}
	return 0;
}
