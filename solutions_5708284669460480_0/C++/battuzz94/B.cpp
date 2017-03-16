#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <iostream>
#include <limits>
#include <set>
#include <iomanip>
#include <cmath>

std::string keyboard, target;
int K, L, S;
long double m_val = 0;

int bordo(std::string s) {
	for (int i = s.length() - 1; i >= 1; --i)
		if (s.substr(0, i) == s.substr(s.length() - i, i))
			return i;
	return 0;
}

int next_match(int match, char c) {
	if (target.substr(0, match + 1) + c == target.substr(0, match + 2))
		return match + 1;
	return bordo(target.substr(0, match + 1) + c) - 1;
}

std::map<std::pair<int,int>, long double> memo;

long double dp(int pos, int match) {
	std::pair<int,int> conf(pos, match);
	if (memo.count(conf))
		return memo[conf];
	//std::cerr << pos << " " << match << std::endl;

	long double base = 0;
	if (match != -1 && match == L - 1)
		base = m_val;

	long double ans = 0;
	if (pos < S - 1) {
		for (char c: keyboard) {
			ans += base + dp(pos + 1, next_match(match, c));
		}
	} else {
		ans = base;
	}

	//std::cerr << pos << " " << match << " :: " << ans << std::endl;
	return memo[conf] = ans;
}

void testcase(int test_no) {
	std::cin >> K >> L >> S;
	std::cin >> keyboard >> target;

	// Se target contiene caratteri non presenti in keyboard è una noia
	std::set<char> chars(keyboard.begin(), keyboard.end());
	bool trivial = false;
	for (char c: target)
		if (!chars.count(c))
			trivial = true;
	if (trivial) {
		std::cout << "Case #" << test_no << ": 0.0" << std::endl;
		return;
	}

	memo.clear();
	m_val = 1.0;
	for (int i = 0; i < S; i++)
		m_val /= K;

	auto bordo_target = bordo(target);
	//std::cerr << "il bordo di " << target << " ha lunghezza " << bordo_target << std::endl;

	// Massimo numero di ripetizione di target in una stringa 
	int n_banane = 0;
	while (n_banane * (L - bordo_target) + bordo_target <= S)
		++n_banane;
	--n_banane;

	//std::cerr << "n_banane = " << n_banane << std::endl;
	//std::cerr << "dp = " << dp(-1, -1) << std::endl;

	std::cout << "Case #" << test_no << ": " << std::fixed << std::setprecision(10) << fabs(double(n_banane)) - dp(-1, -1) << std::endl;
}

int main() {
	int T;
	std::cin >> T;

	for (int t = 1; t <= T; ++t)
		testcase(t);
}