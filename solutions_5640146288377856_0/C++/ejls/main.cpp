#include <iostream>
#include <cmath>

int main(){
	unsigned short T;
	std::cin >> T;
	for(unsigned short t=1; t<=T; ++t){
		int R, C, W;
		std::cin >> R >> C >> W;
		int res = std::ceil(static_cast<double>(C)/W)+W-1;
		std::cout << "Case #" << t << ": " << res << "\n";
	}
}
