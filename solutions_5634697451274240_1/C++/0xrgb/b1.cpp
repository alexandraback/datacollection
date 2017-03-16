#include <iostream>
#include <string>
#include <etc/cppformat/format.cc>

using namespace std;

int solve(string);

int main() {
	ios::ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for(int i = 1 ; i <= tc ; ++i) {
		string x;
		cin >> x;
		cout << fmt::format("Case #{}: {}", i, solve(x)) << endl;
	}

	return 0;
}

int solve(string pan) {
	bool isMinus = true;
	int ans = 0;

	for(auto it = pan.rbegin() ; it != pan.rend() ; ++it) {
		if( isMinus && *it == '-' ) {
			++ans;
			isMinus = false;
		} else if( !isMinus && *it == '+' ) {
			++ans;
			isMinus = true;
		}
	}

	return ans;
}
