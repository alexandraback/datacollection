#include <array>
#include <exception>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

#define f(i, N) for(unsigned i = 0; i < N; ++i)

using namespace std;

typedef long long value_type;
typedef vector<pair<value_type, value_type>> vecpair;


vector<int> read(int N) {
	return vector<int>();
}

enum class Bigger { Unknown, C, J};

bool both_q(char c, char j) {
	return c == '?' && j == '?';
}

bool c_q_j_d(char c, char j) {
	return c == '?' && j != '?';
}

inline bool c_d_j_q(char c, char j) {
	return c != '?' && j == '?';
}

inline int to_value(char c) {
	return c - '0';
}

void solve_a(const string& C, const string& J) {
	vector<int> C_res, J_res;
	auto who = Bigger::Unknown;
	for (int i = 0; i < C.size(); ++i) {
		if (both_q(C[i], J[i])) {
			if (who == Bigger::Unknown) {
				C_res.push_back(0);
				J_res.push_back(0);
			}
			else if (who == Bigger::C) {
				C_res.push_back(0);
				J_res.push_back(9);
			}
			else { // Bigger::J
				C_res.push_back(9);
				J_res.push_back(0);
			}
		} else if (c_q_j_d(C[i], J[i])) {
			J_res.push_back(to_value(J[i]));
			if (who == Bigger::Unknown) {
				C_res.push_back(to_value(J[i]));
			}
			else if (who == Bigger::C) {
				C_res.push_back(0);
			}
			else { // Bigger::J
				C_res.push_back(9);
			}
		} else if (c_d_j_q(C[i], J[i])) {
			C_res.push_back(to_value(C[i]));
			if (who == Bigger::Unknown) {
				J_res.push_back(to_value(C[i]));
			}
			else if (who == Bigger::C) {
				J_res.push_back(9);
			}
			else { // Bigger::J
				J_res.push_back(0);
			}
		} else { // both digit
			if (who == Bigger::Unknown) { // try to decide
				if (C[i] < J[i]) {
					who = Bigger::J;
				}
				else if (J[i] < C[i]) {
					who = Bigger::C;
				}
			}
			C_res.push_back(to_value(C[i]));
			J_res.push_back(to_value(J[i]));
		}
	}
	std::copy(begin(C_res), end(C_res), ostream_iterator<int>(cout, ""));
	cout << " ";
	std::copy(begin(J_res), end(J_res), ostream_iterator<int>(cout, ""));
	cout << endl;
}

bool can_generate(int n, const string& input) {
	for (int i = input.size() - 1; i >= 0; --i) {
		if (input[i] == '?' || (input[i] - '0' == n % 10)) {
			n /= 10;
			continue;
		}
		return false;
	}
	return true;
}

vector<int> possibilites(const string& s) {
	int max = s.size() == 3 ? 1000 : (s.size() == 2 ? 100 : 10);
	vector<int> result;
	for (int i = 0; i < max; ++i) {
		if (can_generate(i, s)) {
			result.push_back(i);
		}
	}
	return result;
}

pair<int, int> get_min(const vector<int>& c, const vector<int>& j) {
	int min_diff = 1000;
	int min_c = 1000;
	int min_j = 1000;
	for (auto c1 : c) {
		for (auto j1 : j) {
			int diff = abs(c1 - j1);
			if (diff < min_diff) {
				min_diff = diff;
				min_c = c1;
				min_j = j1;
			} else if (diff == min_diff) {
				if (c1 < min_c) {
					min_c = c1;
					if (j1 < min_j) {
						min_j = j1;
					}
				}
			}
		}
	}
	return{ min_c,min_j };
}

void print_int(int num, int size) {
	cout.width(size);
	cout.fill('0');
	cout << num;
}

void test() {
	cout << can_generate(102, "1?2") << endl;
	cout << can_generate(102, "1??") << endl;
	cout << can_generate(102, "???") << endl;
	cout << can_generate(102, "?3?") << endl;
	auto r1 = possibilites("?98");
	auto r2 = possibilites("??1");
	//copy(begin(r2), end(r2), ostream_iterator<int>(cout, "\n")); cout << endl;
	auto p = get_min(r1, r2);
	cout << p.first << ", " << p.second << endl;
	print_int(p.first, 3);
	cout << " ";
	print_int(p.second, 3);
}

void solve(const string& C, const string& J) {
	auto pos_c = possibilites(C);
	auto pos_j = possibilites(J);
	auto p = get_min(pos_c, pos_j);
	print_int(p.first, C.size());
	cout << " ";
	print_int(p.second, J.size());
	cout << endl;
}

void loop(unsigned T) {
	string C;
	string J;
	f(t, T) {
		std::cin >> C;
		std::cin >> J;
		cout << "Case #" << t + 1 << ": ";
		solve(C, J);
	}
}

int main() {
	try {
		//test();
		unsigned T = 0;
		cin >> T;
		loop(T);
	}
	catch (const std::exception& e) {
		cout << "Exception: " << e.what() << endl;
	}
	catch (...) {
		cout << "Unknown failure!" << endl;
	}
}