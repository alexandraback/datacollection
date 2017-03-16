#include <iostream>

void solve(int n){
	int R, C, W;
	std::cin >> R >> C >> W;
	int t = 0;
	int k= W-1;
	for(; k<C; k+=W) ++t;
	if(k == C-1+W) std::cout << "Case #" << n << ": " << t+W-1 << std::endl;
	else std::cout << "Case #" << n << ": " << t+W << std::endl;
}

int main(){
	int T;
	std::cin >> T;
	for(int i=0; i<T; ++i) solve(i+1);
}