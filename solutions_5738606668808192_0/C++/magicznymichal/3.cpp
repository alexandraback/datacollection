#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <map>

bool pierwsza(unsigned long long liczba, unsigned long long* wynik) {
	for (int i = 2; i*i <= liczba; ++i) {
		if (liczba % i == 0) {
			(*wynik) = i;
			return false;
		}
	}
	return true;
}

struct swiadkowie {
	unsigned long long liczby[9];
};

unsigned long long zamien(unsigned long long base, std::string liczba) {
	unsigned long long res = 0;
	for (char c : liczba) {
		res *= base;
		res += (c - '0');
	}
	return res;
}

int main() {
	srand(time(NULL));
	
	std::set<std::string> liczby;
	std::map<std::string, swiadkowie> szczegoly;

	while (liczby.size() < 50) {
		std::string liczba = "1";
		for (int i = 0; i < 14; ++i) {
			if (rand() % 2 == 0)
				liczba = liczba + "0";
			else
				liczba = liczba + "1";
		}
		liczba = liczba + "1";

		bool ok = true;
		swiadkowie dzielniki;
		for (int i = 2; i <= 10; ++i) {
			unsigned long long zamieniona = zamien(i, liczba);
			if (pierwsza(zamieniona, dzielniki.liczby + i - 2)) {
				ok = false;
				break;
			}
		}

		if (!ok) {
			// std::cout << "Nie ok: " << liczba << std::endl;
			continue;
		}

		liczby.insert(liczba);
		szczegoly[liczba] = dzielniki;
	}

	std::cout << "Case #1:" << std::endl;
	for (auto& p : szczegoly) {
		std::cout << p.first;
		for (int i = 0; i < 9; ++i)
			std::cout << " " << p.second.liczby[i];
		std::cout << std::endl;
	}
}