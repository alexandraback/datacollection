#include <iostream>

typedef int64_t Z;

Z E, R;
int T, N;
Z v[10000];

Z parsa(int a, int b, Z alux, Z lopux) {
	if(a == b) {
		return 0;
	}
	Z maks = -1;
	int maksi = -1;
	for(int i = a; i < b; ++i) {
		if(v[i] > maks) {
			maks = v[i];
			maksi = i;
		}
	}
	
	Z alq = std::min(E, alux + (maksi - a) * R);
	Z lobbu = std::max(0L, std::min(E, lopux - (b - maksi) * R));
	Z vasen = parsa(a, maksi, alux, alq);
	Z oikea = parsa(maksi + 1, b, std::min(lobbu + R, E), lopux);
	Z taa = (alq - lobbu) * v[maksi];
	return vasen + oikea + taa;
}

int main() {
	std::cin >> T;
	for(int tcase = 0; tcase < T; ++tcase) {
		std::cin >> E >> R >> N;
		for(int i = 0; i < N; ++i) {
			std::cin >> v[i];
		}
		
		std::cout << "Case #" << tcase + 1 << ": " << parsa(0, N, E, 0) << "\n";
	}
	
	return 0;
}
