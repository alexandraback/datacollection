#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <numeric>
#include <memory.h>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 
 
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;

	int t;

	cin >> t;
	int f = 0;

	while (t--) {
		f++;
		cout << "Case #" << f << ": ";

		cin >> s;

		deque <char> now;

		for (int i = 0; i < (int)s.size(); i++) {
			if (i == 0) {
				now.push_back(s[i]);
			} else if (s[i] >= now[0]) {
				now.push_front(s[i]);
			} else {
				now.push_back(s[i]);
			}
		}

		for (int i = 0; i < (int)s.size(); i++) {
			cout << now[i];
		}

		cout << endl;
	}

	return 0;
}
