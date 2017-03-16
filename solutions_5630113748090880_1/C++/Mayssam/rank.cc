
#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>

using namespace std;

int main() {

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
	int N, H;
	int tab[2501] = {0};
	cin >> N;
	for (int j = 0; j < N*(2 * N - 1); j++) {
	    cin >> H;
	    tab[H]++;
	}
	cout << "Case #" << 1+i << ": ";
	for (int h = 1; h <= 2500; h++) {
	    if (tab[h] % 2) cout << h << " ";
	}
	cout << endl;

    }

    return 0;
}


