#include <array>
#include <exception>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

#define f(i, N) for(unsigned i = 0; i < N; ++i)

using namespace std;

typedef long long value_type;
typedef vector<pair<value_type, value_type>> vecpair;
typedef map<char, int> Count;


Count count_chars(const string& s) {
	map<char, int> m;
	for (auto c : s) {
		++m[c];
	}
	return m;
}

vector<string> NUMBERS_VECTOR = {"ZERO","TWO","SIX","EIGHT","SEVEN","FIVE","FOUR","NINE", "THREE","ONE"};
map<string, int> NUMBERS_MAP = { {"ZERO", 0}, {"TWO", 2}, {"SIX", 6}, {"EIGHT", 8}, {"SEVEN", 7}, {"FIVE", 5}, {"FOUR", 4}, {"NINE", 9}, {"THREE",3}, {"ONE",1} };

int count_number(Count& count, const string& s) {
	vector<int> result;
	for (auto c : s) {
		result.push_back(count[c]);
	}
	auto it = min_element(result.begin(), result.end());
	return it == result.end() ? 0 : *it;
}

void remove(Count& count, const string& s, int number) {
	for (auto c : s) {
		count[c] -= number;
		if (count[c] < 0) {
			throw runtime_error("negative_count");
		}
	}
}

void print(Count& c) {
	for (auto cc : c) {
		cout << cc.first << " ->" << cc.second << endl;
	}
}

void test_count() {
	auto r = count_chars("WEIGHFOXTOURIST");
	print(r);
}

void test_count_number() {
	auto count = count_chars("OURNEONFOE");
	auto r = count_number(count, "ONE");
	cout << "Count(ONE)=" << r << endl;
}

void test_remove() {
	auto count = count_chars("SNIENIXOSOXE");
	print(count);
	auto r = count_number(count, "SIX");
	cout << "Count(SIX)=" << r << endl;
	remove(count, "SIX", r);
	print(count);
	r = count_number(count, "FOUR");
	cout << "Count(FOUR)=" << r << endl;
	remove(count, "FOUR", r);
	print(count);
}

void test() {
	//test_count();
	//test_count_number();
	test_remove();
}

vector<int> read(int N) {
	return vector<int>();
}

void solve(const string& input) {
	vector<int> result;
	Count count = count_chars(input);
	for (auto number : NUMBERS_VECTOR) {
		int occ = count_number(count, number);
		for (int i = 0; i < occ; ++i) {
			result.push_back(NUMBERS_MAP[number]);
		}

		remove(count, number, occ);
	}
	std::sort(begin(result), end(result));
	std::copy(begin(result), end(result), ostream_iterator<int>(cout, ""));
}

void loop(unsigned T) {
	string input;
	f(t, T) {
		cin >> input;
		cout << "Case #" << t + 1 << ": ";
		solve(input);
		cout << endl;
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