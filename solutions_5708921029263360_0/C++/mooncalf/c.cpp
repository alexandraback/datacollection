#include <iostream>

using namespace std;

int main() 
{
	int tests;
	cin >> tests;
	
	for (int i = 0; i < tests; ++i) {
		int jp[11][11] = {0};
		int js[11][11] = {0};
		int ps[11][11] = {0};
		bool good[11][11][11] = {0};
		int j, p, s, k;
		cin >> j >> p >> s >> k;
		cout << "Case #" << i + 1 << ": ";
		int total = 0;
		for (int x = 1; x <= j; ++x) {
			for (int y = 1; y <= p; ++y) {
				for (int z = 1; z <= s; ++z) {
					if (jp[x][y] + 1 <= k && js[x][z] + 1 <= k && ps[y][z] + 1 <= k) {
						++jp[x][y];
						++js[x][z];
						++ps[y][z];
						++total;
						good[x][y][z] = 1;
					}
				}
			}
		}
		cout << total << endl;
		for (int x = 1; x <= j; ++x) {
			for (int y = 1; y <= p; ++y) {
				for (int z = 1; z <= s; ++z) {
					if (good[x][y][z]) {
						cout << x << " " << y << " " << z << endl;
					}
					
				}
			}
		}
				
		
	}
	
	return 0;
}