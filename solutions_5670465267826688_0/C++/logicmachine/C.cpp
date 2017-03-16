#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// 0, 1, i, j, k
static inline int multiply(int x, int y){
	int sign = 1;
	if(x < 0){ sign *= -1; x = -x; }
	if(y < 0){ sign *= -1; y = -y; }
	static const int TABLE[5][5] = {
		{  0,  0,  0,  0,  0 },
		{  0,  1,  2,  3,  4 },
		{  0,  2, -1,  4, -3 },
		{  0,  3, -4, -1,  2 },
		{  0,  4,  3, -2, -1 }
	};
	return sign * TABLE[x][y];
}
static inline int c2i(int c){
	switch(c){
		case 'i': return 2;
		case 'j': return 3;
		case 'k': return 4;
	}
	return 1;
}
static inline int fastpow(int x, ll y){
	int z = 1;
	while(y){
		if(y & 1){ z = multiply(z, x); }
		x = multiply(x, x);
		y >>= 1;
	}
	return z;
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int case_num = 1; case_num <= T; ++case_num){
		int n;
		ll x;
		string s;
		cin >> n >> x >> s;
		string prefix, suffix;
		bool accept_prefix = false, accept_suffix = false;
		for(int i = 0, cur = 1; cur != 2 && i < n * 9; ++i){
			if(i % n == 0){ --x; }
			cur = multiply(cur, c2i(s[i % n]));
			if(cur == 2){
				accept_prefix = true;
				prefix = s.substr(i % n + 1);
				break;
			}
		}
		for(int i = 0, cur = 1; cur != 4 && i < n * 9; ++i){
			if(i % n == 0){ --x; }
			cur = multiply(c2i(s[n - 1 - i % n]), cur);
			if(cur == 4){
				accept_suffix = true;
				suffix = s.substr(0, n - 1 - i % n);
				break;
			}
		}
		if(x == -1){
			const int a = n - prefix.size(), b = suffix.size();
			if(a <= b){
				x = 0;
				prefix = prefix.substr(0, b - a);
				suffix = "";
			}
		}
		int reduce = 1;
		for(int i = 0; i < n; ++i){
			reduce = multiply(reduce, c2i(s[i]));
		}
		reduce = fastpow(reduce, max<ll>(0, x));
		for(int i = prefix.size() - 1; i >= 0; --i){
			reduce = multiply(c2i(prefix[i]), reduce);
		}
		for(int i = 0; i < suffix.size(); ++i){
			reduce = multiply(reduce, c2i(suffix[i]));
		}
		bool accept = (x >= 0);
		if(!accept_prefix){ accept = false; }
		if(!accept_suffix){ accept = false; }
		if(reduce != 3){ accept = false; }
		cout << "Case #" << case_num << ": ";
		cout << (accept ? "YES" : "NO") << endl;
	}
	return 0;
}

