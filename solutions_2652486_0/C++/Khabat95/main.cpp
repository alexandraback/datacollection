#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>

using namespace std;

typedef set<int>::iterator SETIT;
typedef map<int, int>::iterator MAPIT;
typedef pair<int, int> PAIR;

void algo() {
	int r, n, m, k;
	cin >> r >> n >> m >> k;

	for(int i=0; i<r; ++i) {
		int prod[k];

		for(int j=0; j<k; ++j) {
			cin >> prod[j];
		}

		vector<int> res;
		map<int, int> res_map;
		map<int, int> j_map;
		int count = 0;
		for(int j=0; j<k; ++j) {
			vector<int> comb;
			j_map.clear();
			while(prod[j] != 1) {
				for(int l=m; l>1; --l) {
					double test = (double)prod[j] / (double)l;
					if(floor(test) == test) {
						comb.push_back(l);
						if(j_map.find(j) != j_map.end()) {
							j_map.find(j)->second++;
						}
						else {
							j_map.insert(PAIR(l, 1));
						}

						prod[j] = prod[j] / l;
					}
				}
			}
			if(comb.size() == n) {
				res = comb;
				break;
			}
			else {
				for(MAPIT it=j_map.begin(); it!=j_map.end(); ++it) {
					if(res_map.find(it->first) != res_map.end()) {
						if(res_map.find(it->first)->second < it->second) {
							count += it->second - res_map.find(it->first)->second;
							res_map.find(it->first)->second = it->second;
						}
					}
					else {
						count += it->second;
						res_map.insert(PAIR(it->first, it->second));
					}
				}
				if(count == n) {
					break;
				}
			}
		}

		if(res.size() == n) {
			for(int j=0; j<n; ++j) {
				cout << res[j];
			}
		}
		else {
			for(MAPIT it=res_map.begin(); it!=res_map.end(); ++it) {
				for(int j=0; j<it->second; ++j) {
					cout << it->first;
				}
			}
			for(int j=count; j<n; ++j) {
				cout << 2;
			}
		}
		cout << endl;
	}
}

int main() {
	int n_cases;
	cin >> n_cases;

	for(int i=0; i<n_cases; ++i) {
		cout << "Case #" << i+1 << ":" << endl;
		algo();
	}
}

