#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

fstream in, out;

int t;
long long a, b;

int last_pal[10000001];
vector<int> digits;
set<int> palin;

bool is_palindrome(long long i) {
	digits.clear();
	long long temp = i;
	while (temp > 0) {
		digits.push_back(temp % 10);
		temp /= 10;
	}
	for (int i = 0; i < digits.size() / 2; i++) {
		if (digits[i] != digits[digits.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}

void cache_palindromes() {
	int last = 1;
	for (int i = 1; i <= 10000001; i++) {
		if (is_palindrome(i)) {
			last = i;
			palin.insert(i);
		}
		last_pal[i] = last;
	}
}

int main() {
	in.open("C-large-1.in", fstream::in);
	out.open("probc-large1.out", fstream::out);

	cache_palindromes();

	in >> t;

    for (int i = 0; i < t; i++) {
		in >> a >> b;

		long long ans = 0;
		int max = (int)sqrt(b);
		int min;
		if (sqrt(a) == (int)(sqrt(a))) {
			min = (int)sqrt(a);
		} else {
			min = (int)(sqrt(a) + 1);
		}
		set<int>::iterator itr = palin.find(last_pal[max]);
		set<int>::iterator itr_end = palin.find(last_pal[min]);
		if (palin.count(min) > 0) {
			--itr_end;
		}
		while (itr != itr_end) {
			if (is_palindrome(((long long)(*itr)) * ((long long)(*itr)))) {
				ans++;
			}
			--itr;
		}

		out << "Case #" << i + 1 << ": " << ans << endl;
	}
    
	in.close();
	out.close();

	return 0;
}
