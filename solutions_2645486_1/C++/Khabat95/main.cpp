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
	int e, r, n;
	cin >> e >> r >> n;

	int v[n];
	for(int i=0; i<n; ++i) {
		cin >> v[i];
	}

	long long res = 0;
	if(e == r) {
		for(int i=0; i<n; ++i) {
			res += (v[i]*e);
		}
	}
	else {
		int cur_e = e;
		int cycles = ceil((double)e / (double)r);
		int diff = cycles*r - e;
		for(int i=0; i<n; ++i) {
			bool max = true;
			bool second_max = true;
			int max_id = i;
			for(int j=1; j<cycles; ++j) {
				if(i+j < n) {
					if(v[i+j] > v[i]) {
						if(v[i+j] > v[max_id]) {
							max_id = i+j;
							if(max == false) {
								second_max = false;
								break;
							}
						}
						max = false;
					}
				}
			}

			if(max) {
				res += ((long long)cur_e* (long long)v[i]);
				cur_e = 0;
			}
			else {
				if((cur_e+r) > e) {
					res += ((long long)((long long)cur_e+(long long)r-(long long)e)*(long long)v[i]);
					cur_e -= ((long long)cur_e+(long long)r-(long long)e);
				}

				if(second_max) {
					if(((long long)cur_e + ((long long)max_id-(long long)i)*(long long)r) > e) {
						res += (((long long)cur_e + ((long long)max_id-(long long)i)*(long long)r-(long long)e)*(long long)v[i]);
						cur_e -= ((long long)cur_e + ((long long)max_id-(long long)i)*(long long)r-(long long)e);
					}
				}
			}

			cur_e += r;
		}
	}

	cout << res << endl;
}

int main() {
	int n_cases;
	cin >> n_cases;

	for(int i=0; i<n_cases; ++i) {
		cout << "Case #" << i+1 << ": ";
		algo();
	}
}

