#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool is_palindrome(long long number) {
	vector<int> digits;

	while (number > 0) {
		digits.push_back(number%10);
		number/=10;
	}

	for (int i = 0; i < digits.size()/2; ++i) {
		if (digits[i] != digits[digits.size()-1-i]) {
			return false;
		}
	}
	
	return true;
}

long long to_long_long(const vector<int>& digits) {
	long long result = digits[0];

	for (int i = 1; i < digits.size(); ++i) {
		result *= 10;
		result += digits[i];
	}
	
	return result;
}

long long prefix_to_palindromes(long long prefix, long long& palindrome1, long long& palindrome2) {
	vector<int> prefix_digits;

	while (prefix > 0) {
		prefix_digits.push_back(prefix%10);
		prefix/=10;
	}

	reverse(prefix_digits.begin(), prefix_digits.end());

	vector<int> digits1(prefix_digits),digits2(prefix_digits);

	for (int i = prefix_digits.size()-1; i >= 0; --i) {
		digits1.push_back(prefix_digits[i]);
	}

	for (int i = prefix_digits.size()-2; i >= 0; --i) {
		digits2.push_back(prefix_digits[i]);
	}

	palindrome1 = to_long_long(digits1);
	palindrome2 = to_long_long(digits2);
}

set<long long> roots;

void generate_root_palindromes() {
	for (long long prefix = 1; prefix < 9999; ++prefix) {

		long long candidate1, candidate2;
		prefix_to_palindromes(prefix, candidate1, candidate2);

		if (is_palindrome(candidate1*candidate1)) {
			roots.insert(candidate1);

			//			cerr << prefix << ":" << candidate1 << ":" << candidate1*candidate1 << endl;
		}
		if (is_palindrome(candidate2*candidate2)) {
			roots.insert(candidate2);

			//			cerr << prefix << ":" << candidate2 << ":" << candidate2*candidate2 << endl;
		}
	} 
}

int main(void) {
	generate_root_palindromes();
	
	int T;

	cin >> T;

	for (int i = 0; i < T; ++i) {
		long long A,B;
		cin >> A >> B;

		int count = 0;
		for (set<long long>::iterator itr = roots.begin(); itr != roots.end(); ++itr) {
			long long root = *itr;
			long long palindrome = root*root;

			if (palindrome >= A && palindrome <= B) {
				++count;
			}
		}

		cout << "Case #" << i+1 << ": " << count << endl;
	}
}
