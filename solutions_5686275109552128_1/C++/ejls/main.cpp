#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

int main(){
	unsigned short T;
	std::cin >> T;
	std::array<short, 1001> plates;
	for(unsigned short t=1; t<=T; ++t){
		std::size_t n;
		std::cin >> n;
		for(std::size_t i=0; i<n; ++i)
			std::cin >> plates[i];
		std::sort(begin(plates), begin(plates)+n);

		short best=plates[n-1];
		auto cur=begin(plates), end=begin(plates)+n;
		for(short i=1; i<=plates[n-1]; ++i)
			best=std::min(best, std::accumulate(cur=std::find_if(cur, end, [=](short x){ return x>i; }), end, i, [=](short x, short y){ return x+(y-1)/i; }));

		std::cout << "Case #" << t << ": " << best << "\n";
	}
}
