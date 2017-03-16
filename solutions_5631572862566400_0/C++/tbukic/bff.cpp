#include <iostream>
#include <string>

bool insert(int current, int * bff, int * count, bool * inside) {
	if (inside[current]) {
		--count[current];
		return true;
	}
	
	inside[current] = true;
	--count[current];
	if (
		count[bff[current]] > 0 &&
		insert(bff[current], bff, count, inside)
	) {
		return true;
	}
	
	inside[current] = false;
	++count[current];
	return false;
}

int main() {
	int t;
	std::cin >> t;
	
	int n, children;
	
	for (int i = 0; i < t; ++i) {
	
		std::cin >> n;
		int bff[n], count[n];
		
		for (int i = 0; i < n; ++i) {
			std::cin >> bff[i];
			--bff[i];
			++count[bff[i]];
		}
		
		bool inside[n];
		for (int i = 0; i < n; ++i) {
			inside[i] = false;
		}
		
		for (int i = 0; i < n; ++i) {
			if (count[i] >= 2) {
				count[i] = 2;
			}
		}
		
		for (int slf = 1; slf >= 0; --slf) {
		for (int frnd = 1; frnd >= 0; --frnd) {
		for (int i = 0; i < n; ++i) {
			if (!inside[i] && count[i] > slf && count[bff[i]] > frnd) {
				insert(i, bff, count, inside);
			}
		}
		}}
		
		children = 0;
		
		for (int i = 0; i < n; ++i) {
			if (inside[i]) {
				++children;
			}
		}
		
		std::cout << "Case #" << i + 1 << ": " << children;
		
		std::cout << std::endl;
	}

	return 0;
}
