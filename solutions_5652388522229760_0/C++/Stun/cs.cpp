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
#include <unordered_set>

using namespace std;

void process(long long x, std::unordered_set<int> & hash) {
	while (x > 0) {
		hash.emplace(x % 10);
		x /= 10;
	}	
}

long long solve(long long x) {
	assert(x > 0);
	std::unordered_set<int> hash;
	for (auto i = 1 ; ; ++i) {
		long long y = x * i;
		process(y, hash);
		if (hash.size() == 10) 
			return y;
	}
}

void test() {
	for (long long i = 1 ; i < 1000001 ; ++i) {
		std::cout << solve(i) << std::endl;
	}
}

int main(){
	int tcase;
	cin >> tcase;
	
	for(size_t casen = 0; casen < tcase; ++casen)
	{
		cout << "Case #" << casen + 1 << ": ";
		long long x;
		cin >> x;
		if (x > 0) std::cout << solve(x) << std::endl;
		else std::cout << "INSOMNIA" << std::endl;
	}
	return 0;
}
