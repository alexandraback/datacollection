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
	long N;	
	vector<long> cache;

public:
	long reverse(long n) {
		long val = 0;
		while (n != 0) {
			int digit = n % 10;
			n /= 10;
			val = val * 10 + digit;
		}
		return val;
	}
	void parseData() {
		string line;

		cin >> N;
		getline(cin, line);
	}


	long solve() {
		cache = vector<long>(N + 1, INT_MAX);
		cache[0] = 0;
		cache[1] = 1;
		for (long i = 2; i <= N; ++i) {
			long ri = reverse(i);
			if (i%10 != 0 && ri < i)
				cache[i] = min(cache[i - 1], cache[ri]) + 1;
			else
				cache[i] = cache[i - 1] + 1;
		}
		return cache[N];
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
		long res = so.solve();
		cout << "Case #" << i << ": " << res << endl;
	}
	return 0;
}

