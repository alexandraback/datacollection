#include <iostream>
#include <algorithm>

#define MAX 1000001

int T;
int A, N;

int seq[MAX];

int solve(int sz, int j){
	//std::cout << sz << std::endl;
	if(j == N) return 0;
	else if(sz > MAX) return 0;
	else if(seq[j] < sz) return solve(sz+seq[j], j+1);
	else if(sz == 1) return N-j;
	else return std::min(solve(sz+(sz-1), j)+1, N-j);
}

int main(){
	std::cin >> T;
	
	for(int p=0; p<T; ++p){
		std::cin >> A >> N;
		for(int i=0; i<N; ++i){
			std::cin >> seq[i];
		}
		std::sort(seq, seq+N);
		
		std::cout << "Case #" << p+1 << ": " << solve(A, 0) << std::endl;
	}
}
