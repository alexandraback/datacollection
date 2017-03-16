#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<double> VD;

int main() {
	int T;
	cout.precision(5);
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int y, z;
		y = z = 0;
		int N;
		cin >> N;
		VD naomi(N);
		VD ken(N);
		for (int i = 0; i < N; i++) cin >> naomi[i];
		for (int i = 0; i < N; i++) cin >> ken[i];
		sort(naomi.begin(),naomi.end());
		sort(ken.begin(),ken.end());
		vector<bool> used(N,false);
		int aux = N-1;
		for (int i = 0; i < N; i++) {
			bool found = false;
			for (int j = 0; j < N and not found; j++) {
				if (naomi[i] > ken[j] and not used[j]) {
					used[j] = true;
					found = true;
					y++;
				}
			}
			if (not found) {
				while (used[aux]) aux--;
				used[aux] = true;
			}
		}
		used = vector<bool> (N,false);
		for (int i = 0; i < N; i++) {
			bool found = false;
			for (int j = 0; j < N and not found; j++) {
				if (ken[j] > naomi[i] and not used[j]) {
					used[j] = true;
					found = true;
				}
			}
			for (int j = 0; j < N and not found; j++) {
				if (not used[j]) {
					z++;
					used[j] = true;
					found = true;
				}
			}
		}
		/*
		cout << "N";
		for (int i = 0; i < N; i++) cout << " " << fixed << naomi[i];
		cout << endl;
		cout << "K";
		for (int i = 0; i < N; i++) cout << " " << fixed << ken[i];
		cout << endl;
		*/
		cout << "Case #" << x << ": " << y << " " << z << endl;
	}
}