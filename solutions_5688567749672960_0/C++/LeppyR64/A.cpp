#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int D[1000001];

int rev(int x) {
	int y = 0;
	while(x) {
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}

int main() {
	D[1] = 1;
	for(int i = 1; i <= 1000000; i++) {
		int x = rev(i);
		if(D[i + 1] == 0) 
			D[i + 1] = D[i] + 1;
		if(D[x] == 0)
			D[x] = D[i] + 1;
		D[i + 1] = min(D[i + 1], D[i] + 1);
		D[x] = min(D[x], D[i] + 1);
	}
	
	int T, N; 
	cin >> T;
	for(int Z = 1; Z <= T; Z++) {
		cin >> N;
		cout << "Case #" << Z << ": " << D[N] << endl;
	}
}