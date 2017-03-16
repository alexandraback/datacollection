#include <iostream>
#include <string>
#include <map>

long long next[4][4] =
{{0, 1, 2, 3},
 {1, 0, 3, 2},
 {2, 3, 0, 1},
 {3, 2, 1, 0}};
bool neg[4][4] = 
{{0, 0, 0, 0},
 {0, 1, 0, 1},
 {0, 1, 1, 0},
 {0, 0, 1, 1}};

std::map<char, long long> cnv;
 
void solve(long long n){
	long long L, X;
	std::cin >> L >> X;
	std::string s;
	std::cin >> s;
	
	//if(n == 5) std::cout << L << " " << X << std::endl;
	//if(n == 5) std::cout << s << std::endl;
	if(X < 100){
		std::string ns = s;
		for(long long i=0; i<X-1; ++i){
			s += ns;
		}
		
		std::pair<long long, bool> c = std::make_pair(0, false);
		long long st = 0;
		for(long long i=0; i<s.size(); ++i){
			std::pair<long long, bool> n;
			long long j = cnv[s[i]];
			n.first = next[c.first][j];
			n.second = (c.second != neg[c.first][j]);
			if(st == 0 && n.first == 1 && n.second == false) st = 1;
			else if(st == 1 && n.first == 3 && n.second == false) st = 2;
			c = n;
		}
		if(st == 2 && c.first == 0 && c.second == true) st = 3;
		
		if(st == 3) std::cout << "Case #" << n << ": YES" << std::endl;
		else std::cout << "Case #" << n << ": NO" << std::endl;
	}else{
		std::pair<long long, bool> c = std::make_pair(0, false);
		bool st1 = false; bool st2 = false; bool st3 = false;
		for(long long i=0; i<s.size(); ++i){
			std::pair<long long, bool> n;
			long long j = cnv[s[i]];
			n.first = next[c.first][j];
			n.second = (c.second != neg[c.first][j]);
			if(n.first == 1 && n.second == false) st1 = true;
			else if(st1 == true && n.first == 3 && n.second == false) st2 = true;
			c = n;
		}
		std::pair<long long, bool> opt[4];
		opt[0] = c;
		for(long long i=1; i<4; ++i){
			opt[i].first = next[opt[i-1].first][c.first];
			if(!c.second) opt[i].second = (opt[i-1].second != neg[opt[i-1].first][c.first]);
			else opt[i].second = (opt[i-1].second == neg[opt[i-1].first][c.first]);
		}
		if(opt[(X-1)%4].first == 0 && opt[(X-1)%4].second == true) st3 = true;
		for(long long j=0; j<4; ++j){
			c = opt[j];
			for(long long i=0; i<s.size(); ++i){
				std::pair<long long, bool> n;
				long long j = cnv[s[i]];
				n.first = next[c.first][j];
				n.second = (c.second != neg[c.first][j]);
				if(n.first == 1 && n.second == false) st1 = true;
				else if(n.first == 3 && n.second == false) st2 = true;
				c = n;
			}
		}
		
		//if(n == 5) std::cout << st1 << " " << st2 << " " << st3 << std::endl;
		if(st1 && st2 && st3) std::cout << "Case #" << n << ": YES" << std::endl;
		else std::cout << "Case #" << n << ": NO" << std::endl;
	}
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