#include      <algorithm>
#include      <cmath>
#include      <cstdarg>
#include      <cstdio>
#include      <cstdlib>
#include      <iomanip>
#include      <iostream>
#include      <iterator>
#include      <limits>
#include      <list>
#include      <map>
#include      <set>
#include      <vector>
#define endl '\n'
#define each(c, e) for (typeof(c.begin()) e = c.begin(); e != c.end(); ++e)
typedef long long ll;
using namespace std;

bool isVowel(char ch) {
	ch = tolower(ch);
   return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
bool isConsonat(char ch) {
	return !isVowel(ch);
}

void augment(const string &str, int i, int n, set< pair<int, int> > &setHad) {
	for (int j = 0; j <= i - n + 1; j += 1) {
		for (int k = i; k < (int) str.length(); k += 1) {
			setHad.insert(make_pair(j, k));
		}
	}
}

ll solve() {
	int n;
	string str;
	set< pair<int, int> > setHad;
	cin >> str >> n;

	int inSeq = 0;
	for (int i = 0; i <= (int) str.length(); i += 1) {
		if (isVowel(str[i])) inSeq = 0;
		else inSeq += 1;
		if (inSeq >= n) {
			augment(str, i, n, setHad);
		}
	}

	return setHad.size();
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t += 1) {
		cout << "Case #" << t << ": " << solve() << endl;
	}
	return 0;
}
