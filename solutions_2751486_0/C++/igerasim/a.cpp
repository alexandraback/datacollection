#include <iostream>
#include <vector>
#include <algorithm>
#include <hash_map>
#include <string>
#include <map>

using namespace std;
using namespace stdext;

typedef __int64 ll;
typedef unsigned __int64 ull;

int T, n;
string name;

inline bool isVow(char ch) {
	return ch == 'a' ||
		ch == 'e' ||
		ch == 'i' ||
		ch == 'o' ||
		ch == 'u';
}

bool good(int start, int len) {
	if (len < n) return false;
	if (start + len > name.size()) return false;
	int count = 0;
	for (int i = start; i < start + len; ++i) {
		if (isVow(name[i])) {
			count = 0;
		} else {
			count++;
			if (count == n) return true;
		}
	}
	return false;
}

int solve() {
	int count = 0;
	for (int i = 0; i <= name.size(); ++i) {
		for (int len = 0; len <= name.size(); ++len) {
			if (good(i, len)) ++count;
		}
	}
	return count;
}

int main(int argc, char* argv[]) {
    cin >> T;
    for (int t_ = 0; t_ != T; ++t_) {
		cin >> name >> n;
        cout << "Case #" << (t_ + 1) << ": " << solve() << "\n";
    }
    return 0;
}
