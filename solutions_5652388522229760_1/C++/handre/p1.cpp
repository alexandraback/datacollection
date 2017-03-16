#define P1
#ifdef P1

#include <iostream>
#include <stdint.h>

inline int solve(uint64_t N){
	if (N == 0) return -1;
	else {
		
		bool seen[10];
		for(int i = 0; i < 10; i++) seen[i] = false;
		int unseenCnt = 10;
		
		int c, cN;
		for(c = 1, cN = N; unseenCnt; c++, cN = c*N){
			
			while(cN){
				int digit = cN % 10;
				if (!seen[digit]) {
					seen[digit] = true;
					unseenCnt--;
				}
				cN /= 10;
			}
		}
		return (c - 1)*N;
	}
}

int main(void){
	int testCases;
	std::cin >> testCases;
	
	for(int c = 1; c <= testCases; c++){
		bool seen[10];
		for(size_t i = 0; i < 10; i++) seen[i] = false;
		
		uint64_t N;
		std::cin >> N;
		int sol = solve(N);
		std::cout << "Case #" << c << ": ";
		if(sol == -1) std::cout << "INSOMNIA" << "\n";
		else std::cout << sol << "\n";
	}
}

#endif
