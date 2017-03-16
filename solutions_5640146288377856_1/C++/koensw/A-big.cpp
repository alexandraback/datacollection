#include <iostream>

int map[21][21];

void solve(int n){
	int R, C, W;
	std::cin >> R >> C >> W;
	for(int i=0; i<21; ++i){
		for(int j=0; j<21; ++j){
			map[i][j] = 0;
		}
	}
	int t = 0;
	int tk=W-1;
	bool hs = true;
	for(int i=0; i<R; ++i){
		for(int k=tk; k<C; k+=W){
			map[i][k] = 1;
			++t;
			if((i == 0 || i == R-1 || k == 0 || k == C-1) && hs){
				--t;
				hs = false;
			}
		}
		--tk;
		if(tk < 0) tk = W-1;
	}
	
	for(int i=0; i<R; ++i){
		for(int j=0; j<C; ++j){
			//std::cout << map[i][j];
		}
		//std::cout << std::endl;
	}
		
	//if(map[R-1][C-1]) --t;
	if(W < R && W != 1) ++t;
	
	std::cout << "Case #" << n << ": " << t+W << std::endl;
		
//	if(k == C-1+W) std::cout << "Case #" << n << ": " << t+W-1 << std::endl;
//	else std::cout << "Case #" << n << ": " << t+W << std::endl;
}

int main(){
	int T;
	std::cin >> T;
	for(int i=0; i<T; ++i) solve(i+1);
}