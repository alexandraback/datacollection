#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(){
	int T;
	ofstream cout("B-large.out");
	ifstream cin("B-large.in");
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int N;
		cin >> N;
		bool height[2501];
		for (int i = 0; i <= 2500; i++) {
			height[i] = false;
		}
		for (int i = 0; i < 2*N - 1; i++) {
			for (int j = 0; j < N; j++) {
				int h;
				cin >> h;
				height[h] = !height[h];
			}
		}
		cout << "Case #" << i + 1 << ":";
		for (int i = 1; i <= 2500; i++) {
			if (height[i]) {
				cout << " " << i;
			}
		}
		cout << endl;
	}
	return 0;
}