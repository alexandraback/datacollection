#include <iostream>
#include <algorithm>

long long total = 0;
long long opts[7];
long long coins[40];

void solve(long long n){
	long long C, D, V;
	std::cin >> C >> D >> V;
	
	for(long long i=0; i<D; ++i){
		std::cin >> opts[i];
	}
	std::sort(opts, opts+D);
	
	long long s = 0;
	long long t = 0;
	for(long long i=0; i<D; ++i){
		while(s+1 < opts[i]) {
			++t;
			s += C*(s+1);
		}
		s += C*opts[i];
		if(s >= V) break;
	}
	while(s < V){
		++t;
		s += C*(s+1);
	}
	//std::cout << std::endl;
	std::cout << "Case #" << n << ": " << t << std::endl;
}

int main(){
	long long T;
	std::cin >> T;
	for(long long i=0; i<T; ++i) solve(i+1);
}