#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>

using std::pair;
using std::stringstream;
using std::next_permutation;
using std::sqrt;
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::set;
using std::swap;
using std::random_shuffle;
using std::queue;
using std::sin;
using std::cos;
using std::make_pair;
using std::cos;
using std::cerr;

typedef long long ll; 
typedef pair<ll, ll> pll;
const long double PI = 3.14159265358979323846;  
vector<string> a(4);

bool xwin() {
	for (int i = 0; i < 4; ++i) {
		bool ans = true;
		for (int j = 0; j < 4; ++j) {
			if (!((a[i][j] == 'T') || (a[i][j] == 'X'))) {
				ans = false;
				break;
			}
		}
		if (ans)
			return true;
	}
	for (int i = 0; i < 4; ++i) {
		bool ans = true;
		for (int j = 0; j < 4; ++j) {
			if (!((a[j][i] == 'T') || (a[j][i] == 'X'))) {
				ans = false;
				break;
			}
		}
		if (ans)
			return true;
	}
	bool ans = true;
	for (int j = 0; j < 4; ++j) {
		if (!((a[j][j] == 'T') || (a[j][j] == 'X'))) {
			ans = false;
			break;
		}
	}
	if (ans)
		return true;
	ans = true;
	for (int j = 0; j < 4; ++j) {
		if (!((a[j][3 - j] == 'T') || (a[j][3 - j] == 'X'))) {
			ans = false;
			break;
		}
	}
	if (ans)
		return true;
	return false;
}

bool owin() {
	for (int i = 0; i < 4; ++i) {
		bool ans = true;
		for (int j = 0; j < 4; ++j) {
			if (!((a[i][j] == 'T') || (a[i][j] == 'O'))) {
				ans = false;
				break;
			}
		}
		if (ans)
			return true;
	}
	for (int i = 0; i < 4; ++i) {
		bool ans = true;
		for (int j = 0; j < 4; ++j) {
			if (!((a[j][i] == 'T') || (a[j][i] == 'O'))) {
				ans = false;
				break;
			}
		}
		if (ans)
			return true;
	}
	bool ans = true;
	for (int j = 0; j < 4; ++j) {
		if (!((a[j][j] == 'T') || (a[j][j] == 'O'))) {
			ans = false;
			break;
		}
	}
	if (ans)
		return true;
	ans = true;
	for (int j = 0; j < 4; ++j) {
		if (!((a[j][3 - j] == 'T') || (a[j][3 - j] == 'O'))) {
			ans = false;
			break;
		}
	}
	if (ans)
		return true;
	return false;
}

bool end() {
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (a[i][j] == '.')
				return false;
	return true;
}

string solve() {
	for (int i = 0; i < 4; ++i)
		cin >> a[i];
	if (xwin())
		return "X won";
	if (owin())
		return "O won";
	if (end())
		return "Draw";
	return "Game has not completed";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	//scanf("%d\n", &t);
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << i + 1 << ": " << solve() << endl;
		std::cerr << i << endl;
	}
	return 0;
}
