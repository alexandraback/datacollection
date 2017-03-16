#include<iostream>
#include<map>
#include<vector>
using namespace std;

int T, C, D, V, d;


int main() {
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		map<int,bool> can;
		cin >> C >> D >> V;
		int sol = 0;
		can[0] = true;
		for(int i = 0; i < D; ++i) {
			cin >> d;
			for(int j = V; j >= 0; --j) {
				if (can[j]) can[j + d] = true;
			}
		}
		for(int i = 1; i <= V; ++i) {
			if (can[i]) continue;
			sol++;
			for(int j = V; j >= 0; --j)
				if (can[j]) can[j + i] = true;
		}
		cout << "Case #" << t << ": " << sol << endl;
		
		
	}
	return 0;
}