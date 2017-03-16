#include <iostream>
#include <vector>

int main(){
	int T;
	std::cin >> T;
	for(int t=1; t<=T; ++t){
		int N;
		std::cin >> N;
		std::cout << "Case #" << t << ":";
		std::vector<int> v(2501, 0);
		for(int i=0; i<N*(2*N-1); ++i){
			int x;
			std::cin >> x;
			v[x]++;
		}
		for(int i=1; i<2500; ++i)
			if(v[i]%2==1)
				std::cout << " " << i;
		std::cout << '\n';
	}
}
