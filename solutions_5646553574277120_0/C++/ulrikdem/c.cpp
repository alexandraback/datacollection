#include <iostream>
#include <vector>
using namespace std;

vector<bool> possible = {true};

void add(int coin) {
	for(int value = possible.size() - 1; value >= coin; --value) {
		if(possible[value - coin]) {
			possible[value] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test) {
		int one, count, max;
		cin >> one >> count >> max;
		possible.resize(1);
		possible.resize(max + 1);
		while(count--) {
			int coin;
			cin >> coin;
			add(coin);
		}
		count = 0;
		for(int coin = 1; coin <= max; ++coin) {
			if(!possible[coin]) {
				add(coin);
				++count;
			}
		}
		cout << "Case #" << test << ": " << count << '\n';
	}
	return 0;
}
