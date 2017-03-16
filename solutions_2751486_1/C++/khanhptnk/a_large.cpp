#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int ntest;
string s;
int k;

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
	freopen("input_large.txt", "r", stdin);
	freopen("output_large.txt", "w", stdout);
	cin >> ntest;
	for (int test = 0; test < ntest; test++) {
		cin >> s >> k;
		int cur = 0;
		int n = s.length();
		int last = -1;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if (!isVowel(s[i])) cur++;
			else cur = 0;
			if (cur >= k) 
				last = i - k + 1;
			if (last != -1) ans += last + 1;
			//cout << i << ' ' << last << endl;
		}
		cout << "Case #" << test + 1 << ": " << ans << endl;
	}
}
