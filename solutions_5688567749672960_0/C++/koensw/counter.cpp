#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <climits>

#define MAX_N 1111111
int mp[MAX_N];

void solve(int c){
	int i;
	std::cin >> i;
	std::cout << "Case #" << c << ": " << mp[i] << std::endl;
}

int main(){
	for(int i=0; i<MAX_N; ++i){
		std::ostringstream os;
		os << i;
		mp[i] = INT_MAX;
	}
	mp[1] = 1;
	for(int i=1; i<MAX_N-5; ++i){
		std::ostringstream os;
		os << i;
		std::string res = os.str();
		std::string rev = std::string(res.rbegin(), res.rend());
		std::istringstream is(rev);
		int j;
		is >> j;
		
		mp[i+1] = std::min(mp[i+1], mp[i]+1);
		if(j > i && j < MAX_N) mp[j] = std::min(mp[j], mp[i]+1);
	}
	
	int T;
	std::cin >> T;
	for(int i=1; i<=T; ++i) solve(i);
}