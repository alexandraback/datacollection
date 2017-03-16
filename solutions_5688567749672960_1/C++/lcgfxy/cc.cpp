// practice.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <algorithm>
#include <deque>
#include <string>
#include <unordered_map>

using namespace std;


class CC {
private:
	long long N;
	vector<long long> cache;
	vector<int> bits;

public:
	long long reverse(long long n) {
		long long val = 0;
		while (n != 0) {
			int digit = n % 10;
			n /= 10;
			val = val * 10 + digit;
		}
		return val;
	}
	void split(long long n) {
		while (n != 0) {
			int digit = n % 10;
			bits.insert(bits.begin(), digit);
			n /= 10;
		}
	}
	long long num(const vector<int>& n) {
		long long val = 0;
		for (int d : n) {
			val = val * 10 + d;
		}
		return val;
	}
	void parseData() {
		string line;

		cin >> N;
		getline(cin, line);
	}

	long long solve(const vector<int>& n) {
		if (n.size() == 1) return n.front();
		long long count = 0;
		int order = 1;
		if (n.back() != 1) count += n.back() - 1;
		if (n.front() != 1) count += n.front();

		for (int i = 1, j = n.size() - 2; i <= j; ++i, --j) {
			order *= 10;
			if (n[i] != 0) count += n[i] * order + 1;
			if (i != j && n[j] != 0) count += n[j] * order;
		}
		vector<int> tmp;
		for (int i = 0; i < n.size() - 1; ++i)
			tmp.push_back(9);
		count += solve(tmp) + 2;
		return count;
	}

	long long solve() {
		if (N == 0) return 0;
		if (N % 10 != 0) {
			split(N);
			return solve(bits);
		}
		else {
			split(N - 1);
			return solve(bits) + 1;
		}
	}

};

int main(int argc, char* argv[])
{
	string line;
	int count;

	cin >> count;
	getline(cin, line);

	for (int i = 1; i <= count; ++i) {
		CC so;
		so.parseData();
		long long res = so.solve();
		cout << "Case #" << i << ": " << res << endl;
	}
	return 0;
}

