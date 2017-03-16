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
typedef unsigned long long ll;
using namespace std;

bool isVowel(char ch) {
	ch = tolower(ch);
   return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
bool isConsonat(char ch) {
	return !isVowel(ch);
}

ll inter(const pair<int, int> &pt1, const pair<int, int> &pt2) {
	if (pt1.first <= pt2.first && pt2.first <= pt1.second) {
		return min(pt1.second, pt2.second) - pt2.first + 1;
	}

	return 0;
}

ll solve() {
	int n;
	string str;
	set< pair< pair<int, int>, pair<int, int> > > setIntervals;
	cin >> str >> n;

	int inSeq = 0;
	for (int i = 0; i <= (int) str.length(); i += 1) {
		if (isVowel(str[i])) inSeq = 0;
		else inSeq += 1;
		if (inSeq >= n) {
			setIntervals.insert(make_pair(make_pair(0, i - n + 1), make_pair(i, str.length() - 1)));
		}
	}

	ll result = 0;
	each(setIntervals, it) {
		result += (it->first.second - it->first.first + 1) * (it->second.second - it->second.first + 1);
	}


	each(setIntervals, it1) {
		set< pair< pair<int, int>, pair<int, int> > >::iterator it2 = it1;
		++it2;
		for (; it2 != setIntervals.end(); ++it2) {
			ll rem = inter(it1->first, it2->first) * inter(it1->second, it2->second);
			result -= rem;
			if (rem) break;
		}
	}

	return result;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t += 1) {
		cout << "Case #" << t << ": " << solve() << endl;
	}
	return 0;
}
