#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>

#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

string uniq = "ZOWTFVXSGE";
int order[] = {0, 8, 2, 6, 7, 5, 3, 4, 1, 9};
int count_char[512];
string name[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		for (int i = 0; i < 512; ++i)
			count_char[i] = 0;
		string ans = "";
		string S;
		cin >> S;

		for (char i : S) {
			count_char[i]++;
		}


		for (int j = 0; j < 10; ++j) {
			char i = order[j];
//			fprintf(stderr, "%d\n", i);
			int num = count_char[uniq[i]];
			if (num > 0)
				ans += string(num, i + '0');
			for (auto c : name[i]) {
//				cout << c;
				count_char[c] -= num;
			}
//			cout << endl;

		}


		sort(ans.begin(), ans.end());

		cout << "Case #" << t << ": " << ans << endl;
	}
}
