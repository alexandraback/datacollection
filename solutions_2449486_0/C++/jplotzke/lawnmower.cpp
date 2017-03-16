#include <cstdio>
#include <iostream>
using namespace std;

const int N = 10;
const char HT = 2;

bool is_poss(const char grid[N][N], const int & len, const int & wid){
	for (char ht = HT; ht >= 1; --ht){
		bool ok[N][N] = {false};
		for (int y = 0; y < len; ++y){
			for (int x = 0; x < wid; ++x){
				if (ok[y][x] || grid[y][x] > ht) continue;
				ok[y][x] = true;
				for (int z = 0; z < wid; ++z){
					if (grid[y][z] > ht){
						ok[y][x] = false; break;
					}
				}
				if (ok[y][x]){
					for (int z = 0; z < wid; ++z) ok[y][z] = true;
					continue;
				}

				ok[y][x] = true;
				for (int z = 0; z < len; ++z){
					if (grid[z][x] > ht){
						ok[y][x] = false; break;
					}
				}
				if (ok[y][x]){
					for (int z = 0; z < ht; ++z) ok[z][x] = true;
					continue;
				}
				return false;
			}
		}
	}
	return true;
}

int main(){
	freopen("lawnmower.in", "r", stdin);
	freopen("lawnmower.out", "w", stdout);
	int run, len, wid, num; char grid[N][N], max_ht = 1;
	cin >> run;
	for (int a = 1; a <= run; ++a){
		cin >> len >> wid;
		for (int y = 0; y < len; ++y){
			for (int x = 0; x < wid; ++x){
				cin >> num;
				grid[y][x] = char(num);
				if (grid[y][x] > max_ht) max_ht = grid[y][x];
			}
		}
		cout << "Case #" << a << ": " << (is_poss(grid, len, wid) ? "YES" : "NO") << endl;
	}
	return 0;
}
