#include <set>
#include <iostream>

void rozloz(std::set<int>& cyfry, long long liczba) {
	while (liczba > 0) {
		cyfry.insert(liczba % 10);
		liczba = liczba / 10;
	}
}

int main() {
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		long long t;
		std::set<int> cyfry;

		std::cin >> t;
		if (t == 0) {
			std::cout << "Case #" << (i+1) << ": INSOMNIA" << std::endl;
			continue;
		}

		long long aktualna = t;

		rozloz(cyfry, aktualna);
		while (cyfry.size() < 10) {
			aktualna += t;
			rozloz(cyfry, aktualna);
		}
		std::cout << "Case #" << (i+1) << ": " << aktualna << std::endl;
	}
}