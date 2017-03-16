#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <bitset>
#include <time.h>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <assert.h>

using namespace std;

int t;
int j, p, s, k;
int cube[11][11][11];
int jp[11][11];
int js[11][11];
int ps[11][11];

void clear() {
	memset(cube, 0, sizeof(int) * 11 * 11 * 11);
	memset(jp, 0, sizeof(int) * 11 * 11);
	memset(js, 0, sizeof(int) * 11 * 11);
	memset(ps, 0, sizeof(int) * 11 * 11);
}

int main() {
	ifstream fin("C-small-attempt0.in", ifstream::in);  // TODO
	ofstream fout("result.out", ofstream::out);
	fin >> t;
	//cin >> t;
	for (int i = 0; i < t; ++i) {
		clear();
		//cin >> j >> p >> s >> k;
		fin >> j >> p >> s >> k;
		
		int limit = j * p * s;
		if (limit > j * p * k) {
			limit = j * p * k;
		}

		int cnt = 0;
		vector<int> res;
		while (cnt <= limit) {
			bool find = false;
			int min_lar = 100, min_sum = 100;
			int min_l = 1, min_m = 1, min_n = 1;
			for (int l = 1; l <= j; ++l) {
				for (int m = 1; m <= p; ++m) {
					for (int n = 1; n <= s; ++n) {
						if (cube[l][m][n]) {
							continue;
						}
						if (jp[l][m] >= k || js[l][n] >= k || ps[m][n] >= k) {
							continue;
						}
						if (!find)
							find = true;
						int lar = max(jp[l][m], max(js[l][n], ps[m][n]));
						int sum = jp[l][m] + js[l][n] + ps[m][n];
						if (lar < min_lar) {
							min_lar = lar;
							min_sum = sum;
							min_l = l;
							min_m = m;
							min_n = n; 
						}
						else if (lar == min_lar && sum < min_sum){
							min_sum = sum;
							min_l = l;
							min_m = m;
							min_n = n;
						}
					}
				}
			}
			if (find) {
				//cout << min_l << ", " << min_m << ", " << min_n << endl;
				cube[min_l][min_m][min_n] = 1;
				jp[min_l][min_m]++;
				js[min_l][min_n]++;
				ps[min_m][min_n]++;

				res.push_back(min_l);
				res.push_back(min_m);
				res.push_back(min_n);
				cnt++;
			}
			else {
				break;
			}
		}

		cout << "Case #" << (i + 1) << ": " << cnt << endl;
		fout << "Case #" << (i + 1) << ": " << cnt << endl;
		for (int x = 0; x < cnt; ++x) {
			cout << res[x * 3] << " " << res[x * 3 + 1] << " " << res[x * 3 + 2] << endl;
			fout << res[x * 3] << " " << res[x * 3 + 1] << " " << res[x * 3 + 2] << endl;
		}
	}
	return 0;
}
