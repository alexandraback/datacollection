#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>
#include <sstream>

using namespace std;

long long llpow(long long base, long long exp) {
	// naive version
	long long ret = 1;
	while (exp-- > 0) {
		ret *= base;
	}
	return ret;
}

string solve() {
	int K, C, S;
	stringstream ss;
	cin >> K >> C >> S;
	if (C == 1) {
		if (S < K) 
			return "IMPOSSIBLE";
		for (size_t i = 1 ; i < K ; ++i)
			ss << i << " ";
		ss << K;
		return ss.str();
	}
	
	const int need = K / 2 + K % 2;
	if (S < need) return "IMPOSSIBLE";
	
	long long s = std::min(2, K);
	ss << s;
	long long chunk = llpow(K, C-1);
	long long size = chunk * K;
	for (int i = 1 ; i < need ; ++i) {
		long long space = s * chunk;
		s += 2;
		s = std::min(s, (long long)K);
		long long ans = space + s;
		ss << " " << ans;
		assert(ans <= size);
		assert(s != K || i + 1 == need);
		assert(i+1 != need || s == K);
	}
	return ss.str();
}

int main(){
	int tcase;
	cin >> tcase;
	
	for(size_t casen = 0; casen < tcase; ++casen)
	{
		
		cout << "Case #" << casen + 1 << ": ";
		cout << solve() << endl;
	}
	

	return 0;
}
