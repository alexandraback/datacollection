#include <iostream>
#include <string>
#include <map>

int next[4][4] =
{{0, 1, 2, 3},
 {1, 0, 3, 2},
 {2, 3, 0, 1},
 {3, 2, 1, 0}};
bool neg[4][4] = 
{{0, 0, 0, 0},
 {0, 1, 0, 1},
 {0, 1, 1, 0},
 {0, 0, 1, 1}};

std::map<char, int> cnv;
 
int solve(int n){
	int L, X;
	std::cin >> L >> X;
	std::string s;
	std::cin >> s;
	std::string ns = s;
	for(int i=0; i<X-1; ++i){
		s += ns;
	}
	
	std::pair<int, bool> c = std::make_pair(0, false);
	int st = 0;
	for(int i=0; i<s.size(); ++i){
		std::pair<int, bool> n;
		int j = cnv[s[i]];
		n.first = next[c.first][j];
		n.second = (c.second != neg[c.first][j]);
		if(st == 0 && n.first == 1 && n.second == false) st = 1;
		else if(st == 1 && n.first == 3 && n.second == false) st = 2;
		c = n;
	}
	if(st == 2 && c.first == 0 && c.second == true) st = 3;
	
	if(st == 3) std::cout << "Case #" << n << ": YES" << std::endl;
	else std::cout << "Case #" << n << ": NO" << std::endl;
}

int main(){
	cnv['i'] = 1;
	cnv['j'] = 2;
	cnv['k'] = 3;
	long long T;
	std::cin >> T;
	long long n = 1;
	while(T--) solve(n), ++n;
}