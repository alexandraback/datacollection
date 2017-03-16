#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long ll;

ifstream fin("c.in");
ofstream fout("c.out");

bool sqispal(int n) {
	stringstream ss;
	ss << ll(n)*n;
	string s;
	ss >> s;
	
	for (int i = 0, j = s.length()-1; i < j; ++i, --j) {
		if (s[i] != s[j])
			return false;
	}

	//stringstream ss1;
	//ss1 << n;
	//ss1 >> s;
	//int a = 0;
	//for (size_t i = 0; i < s.length(); ++i) {
		//a += (s[i]-'0')*(s[i]-'0');
	//}
	//assert(a < 10);
	//cout << n << '\n';

	return true;
}

int solve(int lo, int hi) {
	int ans = 0;
	if (lo <= 3 && 3 <= hi)
		++ans;

	for (int d1 = 1; d1 <= 2; ++d1) {
		int num = d1;
		if (sqispal(num) && lo <= num && num <= hi)
			++ans;
	}

	for (int d1 = 1; d1 <= 2; ++d1) {
		int num = 11*d1;
		if (sqispal(num) && lo <= num && num <= hi)
			++ans;
	}

	for (int d1 = 1; d1 <= 2; ++d1) {
		for (int d2 = 0; d2 <= 2; ++d2) {
			int num = 101*d1 + 10*d2;
			if (sqispal(num) && lo <= num && num <= hi)
				++ans;
		}
	}

	for (int d1 = 1; d1 <= 2; ++d1) {
		for (int d2 = 0; d2 <= 2; ++d2) {
			int num = 1001*d1 + 110*d2;
			if (sqispal(num) && lo <= num && num <= hi)
				++ans;
		}
	}

	for (int d1 = 1; d1 <= 2; ++d1) {
		for (int d2 = 0; d2 <= 2; ++d2) {
			for (int d3 = 0; d3 <= 2; ++d3) {
				int num = 10001*d1 + 1010*d2 + 100*d3;
				if (sqispal(num) && lo <= num && num <= hi)
					++ans;
			}
		}
	}

	for (int d1 = 1; d1 <= 2; ++d1) {
		for (int d2 = 0; d2 <= 2; ++d2) {
			for (int d3 = 0; d3 <= 2; ++d3) {
				int num = 100001*d1 + 10010*d2 + 1100*d3;
				if (sqispal(num) && lo <= num && num <= hi)
					++ans;
			}
		}
	}

	for (int d1 = 1; d1 <= 2; ++d1) {
		for (int d2 = 0; d2 <= 2; ++d2) {
			for (int d3 = 0; d3 <= 2; ++d3) {
				for (int d4 = 0; d4 <= 2; ++d4) {
					int num = 1000001*d1 + 100010*d2 + 10100*d3 + 1000*d4;
					if (sqispal(num) && lo <= num && num <= hi)
						++ans;
				}
			}
		}
	}

	return ans;
}

int main() {
	int n;
	fin >> n;
	ll a, b;
	for (int case_num = 1; case_num <= n; ++case_num) {
		fin >> a >> b;
		fout << "Case #" << case_num << ": ";
		fout << solve( sqrt(a-1)+1, sqrt(b) ) << '\n';
	}
	return 0;
}
