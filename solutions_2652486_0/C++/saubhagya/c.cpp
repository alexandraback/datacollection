#include <fstream>
#include <vector>
#define MAX 130
using namespace std;

ifstream in("input_c.txt");
ofstream out("output_c.txt");

int p[15], R, N, M, K;
vector <int> product[MAX];
vector <int> guess;

void fill_products() {
	for (int i = 8; i < 126; i++) {
		product[i].clear();
	}
	
	for (int i = 2; i <= 5; i++) {
		for (int j = 2; j <= 5; j++) {
			for (int k = 2; k <= 5; k++) {
				product[i].push_back(i * 100 + j * 10 + k);
			}
		}
	}
	
	for (int i = 2; i <= 5; i++) {
		for (int j = 2; j <= i; j++) {
			for (int k = 2; k <= 5; k++) {
				product[i * j].push_back(i * 100 + j * 10 + k);
			}
		}
	}
	
	for (int i = 2; i <= 5; i++) {
		for (int j = 2; j <= i; j++) {
			for (int k = 2; k <= j; k++) {
				product[i * j * k].push_back(i * 100 + j * 10 + k);
			}
		}
	}
}

void fill_guess(int p) {
	if (!guess.size()) {
		for (int i = 0; i < product[p].size(); i++) {
			guess.push_back(product[p][i]);
		}
	}
	else {
		int computed, first, second, third;

		for (int i = 0; i < guess.size(); i++) {

				first = guess[i] / 100;
				second = guess[i] / 10 - first * 10;
				third = guess[i] - first * 100 - second * 10;
				
				if (!(first * second * third == p || first * second == p || first * third == p || second * third == p || first == p || second == p || third == p)) {
					guess.erase(guess.begin() + i);
				}

		}
	}
}

long compute() {
	guess.clear();
	for (int i = 0; i < K; i++) {
		if (p[i] != 1) {
			fill_guess(p[i]);
		}
	}
	if (guess.size()) {
		return guess[0];
	}
	return 222;
}

int main() {
	int t;
	in >> t;
	in >> R >> N >> M >> K;
	out << "Case #1:" << endl;
	
	fill_products();

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < K; j++) {
			in >> p[j];
		}
		out << compute() << endl;
	}
	return 0;
}
