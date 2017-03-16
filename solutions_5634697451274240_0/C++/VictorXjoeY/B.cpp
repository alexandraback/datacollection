#include <bits/stdc++.h>

using namespace std;

string s;

void flip(int x){
	char aux;
	int i, j;

	for (i = 0, j = x; i <= j; i++, j--){
		aux = s[i];
		s[i] = s[j] == '+' ? '-' : '+';
		s[j] = aux == '+' ? '-' : '+';
	}
}

int main(void){
	int t, i, x, y, flips;

	ios::sync_with_stdio(false);

	cin >> t;

	for (i = 0; i < t; i++){
		cin >> s;

		flips = 0;

		y = s.size() - 1;

		while (y >= 0){
			x = 0;

			// Searching for the first occurrence of - from the right
			while (y >= 0 and s[y] == '+'){
				y--;
			}

			// Searching for the first occurrence of - from the left
			while (x < s.size() and s[x] == '+'){
				x++;
			}

			// If there are any + in the beginning and not all of the signs are +
			// Turning starting signs into -
			if (x > 0 and x < s.size()){
				flip(x - 1);
				flips++;
			}

			// Flipping at y
			if (y >= 0){
				flip(y);
				flips++;
			}
		}

		cout << "Case #" << i + 1 << ": " << flips << endl;
	}

	return 0;
}