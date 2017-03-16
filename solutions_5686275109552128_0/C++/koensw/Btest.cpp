#include <iostream>
#include <map>
#include <string>
#include <algorithm>

std::map<std::string, int> mp;

int dp(std::string s){
	if(s.empty()) return 0;
	if(mp.find(s) != mp.end()) return mp[s];
	std::string bs;
	for(int i=0; i<s.size(); ++i){
		if(s[i] == '1') break;
		bs += s[i]-1;
	}
	int b = dp(bs)+1;
	int k = s[0]-'0';
	for(int i=1; i<k;++i){
		std::string ns = s;
		if(k == 1) return mp[s] = b;
		ns[0] = k-i+'0';
		ns += i+'0';
		std::sort(ns.begin(), ns.end(), std::greater<char>());
		//std::cout << s << " " << ns << std::endl;
		b = std::min(b, dp(ns)+1);
	}
	return mp[s] = b;
}

void solve(int n){
	mp.clear();
	int N;
	std::cin >> N;
	std::string s;
	for(int i=0; i<N; ++i){
		int k;
		std::cin >> k;
		s+='0'+k;
	}
	std::sort(s.begin(), s.end(), std::greater<char>());
	std::cout << "Case #" << n << ": " << dp(s) << std::endl;
}

int main(){
	long long T;
	std::cin >> T;
	long long n = 1;
	while(T--) solve(n), ++n;
}