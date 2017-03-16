#include <bits/stdc++.h>
using namespace std;

//typedef unsigned long long int ull;
typedef unsigned __int128 ull;

string print_uint128(ull n) {
  if (n == 0)  return "0";

  char str[40] = {0}; // log10(1 << 128) + '\0'
  char *s = str + sizeof(str) - 1; // start at the end
  while (n != 0) {
    if (s == str) return "-1"; // never happens

    *--s = "0123456789"[n % 10]; // save last digit
    n /= 10;                     // drop it
  }
  return string(s);
}

/*
string to_str(ull n) {
	ull base = 1;
	string answer = 0;
	for (ull r = 0; r < 32; r++, base *= 10UL) {
		bool digit = (bool)(n & (1UL << r));	
		answer += (digit ? "1" : "0");
	}
	return answer;
}

ostream& operator <<(ostream& os, ull a) {
	os << to_str(a);
	return os;
}
*/

string to_binary(ull n, int length) {
	bitset<32> x(n);
	stringstream ss;
	ss << x;
	return ss.str().substr(32 - length);
}

ull to_base(ull n, int b) {
	if (b == 2) return n;
	ull base = 1;
	ull answer = 0;
	for (ull r = 0; r < 32; r++, base *= b) {
		answer += base * ((bool)(n & (1UL << r)));
	}
	return answer;
}

ull factor(ull n) {
	if (n % 2 == 0) return 2;
	for (int d=3; d*d <= n; d += 2) { 
		if (n % d == 0) return d;
	}
	return 0;  // indicates no divisors found
}

vector<ull> jamcoin(ull coin) {
	vector<ull> answer;
	for (int b=2; b <= 10; b++) {
		ull f = factor(to_base(coin, b));
		if (f == 0) return vector<ull>();  // return empty
		answer.push_back(f);
	}
	return answer;
}

void solve(int c, int N, int J) {
	cout << "Case #" << c << ":" << endl;
	vector<pair<ull, vector<ull>>> answer;
	for (ull coin = (1ULL << (N-1)) + 1; coin < (1ULL << N) && (int)answer.size() < J; coin += 2) {
		vector<ull> factors = jamcoin(coin);
		if (!factors.empty()) answer.emplace_back(coin, move(factors));
	}
	for (const auto& ans : answer) {
		cout << to_binary(ans.first, N);
		//for (int i=0; i<9; i++) cout << " (" << to_base(ans.first, i+2) << ") " << ans.second[i];
		for (int i=0; i<9; i++) cout << ' ' << print_uint128(ans.second[i]);
		cout << '\n';
	}
}

int main() {
	int T, N, J;
	cin >> T;
	for (int c = 1; c <= T; c++) {
		cin >> N >> J;
		solve(c, N, J);
	}
}
