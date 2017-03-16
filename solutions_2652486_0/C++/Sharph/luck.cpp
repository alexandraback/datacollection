#include <iostream>
#include <array>
#include <algorithm>
#include <random>
#include <map>

typedef std::array<int, 3> Luvut;
typedef std::array<int, 7> Tulot;

int main() {
	std::mt19937 rng(5);
	std::uniform_int_distribution<int> dist(0, 1);
	int tmp;
	std::cin >> tmp >> tmp >> tmp >> tmp >> tmp;
	
	std::map<Tulot, std::map<Luvut, int>> asd;
	Luvut luvut;
	for(luvut[0] = 2; luvut[0] <= 5; ++luvut[0]) {
	for(luvut[1] = 2; luvut[1] <= 5; ++luvut[1]) {
	for(luvut[2] = 2; luvut[2] <= 5; ++luvut[2]) {
		Luvut sluvut = luvut;
		std::sort(sluvut.data(), sluvut.data() + 3);
		for(int test = 0; test < 10000; ++test) {
			Tulot tulot;
			for(int i = 0; i < 7; ++i) {
				int tulo = 1;
				for(int j = 0; j < 3; ++j) {
					if(dist(rng)) tulo *= sluvut[j];
				}
				tulot[i] = tulo;
			}
			std::sort(tulot.data(), tulot.data() + 7);
			asd[tulot][sluvut]++;
		}
	}
	}
	}
	
	std::cout << "Case #1:\n";
	for(int i = 0; i < 100; ++i) {
		Tulot tulot;
		for(int j = 0; j < 7; ++j) {
			std::cin >> tulot[j];
		}
		std::sort(tulot.data(), tulot.data() + 7);
		std::map<Luvut, int> &freq = asd[tulot];
		int parsa = -1;
		Luvut parsaluvut;
		for(const std::pair<Luvut, int> &p : freq) {
			if(p.second > parsa) {
				parsa = p.second;
				parsaluvut = p.first;
			}
		}
		for(int j = 0; j < 3; ++j) {
			std::cout << parsaluvut[j];
		}
		std::cout << "\n";
	}
	
	return 0;
}
