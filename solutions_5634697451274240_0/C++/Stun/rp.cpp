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
#include <unordered_map>

using namespace std;

void trim(string & str) {
	while(!str.empty()) {
		if (str.back() != '+')
			return;
		str.pop_back();
	}
}

unordered_map<string, int> cache;
char flip(char x) {
	return (x == '+')?'-':'+';
}

int solve(string str) {
	trim(str);
	const auto it = cache.find(str);
	if (it != cache.end()) return it->second;
	auto iit = cache.emplace(str, 100000);
	// flip
	string f(str.size(), ' ');
	for (size_t i = 0 ; i < str.size() ; ++i)
		f[i] = flip(str[str.size()-i-1]);
	int s1 = solve(f);
	
	// convert
	for (size_t i = 0 ; i < str.size() ; ++i)
		f[i] = flip(str[i]);
	int s2 = solve(f);
	iit.first->second = std::min(s1, s2)+1;
	return std::min(s1, s2)+1;
}

int main(){
	int tcase;
	cin >> tcase;
	
	cache.emplace("", 0);
	string in;
	for(size_t casen = 0; casen < tcase; ++casen)
	{
		
		cout << "Case #" << casen + 1 << ": ";
		cin >> in;
		std::cout << solve(in) << std::endl;
	}
	

	return 0;
}
