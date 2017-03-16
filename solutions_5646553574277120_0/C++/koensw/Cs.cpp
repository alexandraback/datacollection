#include <iostream>
#include <algorithm>

int total = 0;
int opts[7];
int coins[40];

void solve(int n){
	int C, D, V;
	std::cin >> C >> D >> V;
	
	for(int i=0; i<D; ++i){
		std::cin >> opts[i];
	}
	std::sort(opts, opts+D);
	
	int s = 0;
	int t = 0;
	for(int i=0; i<D; ++i){
		while(s+1 < opts[i]) {
			++t;
			//std::cout << s+1 << " ";
			s += s+1;
		}
		s += opts[i];
		if(s >= V) break;
	}
	while(s < V){
		++t;
		//std::cout << s+1 << " ";
		s += s+1;
	}
	//std::cout << std::endl;
	std::cout << "Case #" << n << ": " << t << std::endl;
}

int main(){
	int T;
	std::cin >> T;
	for(int i=0; i<T; ++i) solve(i+1);
}