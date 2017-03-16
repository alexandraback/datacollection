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

static vector<char> res;

void algo() {
	int x, y;
	cin >> x >> y;

	int posx = 0;
	int posy = 0;
	int nb = 0;
	res.clear();
	while((posx != x) || (posy != y)) {
		int diffx = x - posx;
		int diffy = y - posy;

		nb++;

		if(abs(diffx) > abs(diffy)) {
			if(abs(diffx) >= nb) {
				if(diffx < 0) {
					res.push_back('W');
					posx -= nb;
				}
				else {
					res.push_back('E');
					posx += nb;
				}
			}
			else {
				if((nb - abs(diffx)) < (nb/2)) {
					if(diffx < 0) {
						res.push_back('W');
						posx -= nb;
					}
					else {
						res.push_back('E');
						posx += nb;
					}
				}
				else {
					if(diffx < 0) {
						res.push_back('E');
						posx += nb;
					}
					else {
						res.push_back('W');
						posx -= nb;
					}
				}
			}
		}
		else {
			if(abs(diffy) >= nb) {
				if(diffy < 0) {
					res.push_back('S');
					posy -= nb;
				}
				else {
					res.push_back('N');
					posy += nb;
				}
			}
			else {
				if((nb - abs(diffy)) < (nb/2)) {
					if(diffy < 0) {
						res.push_back('S');
						posy -= nb;
					}
					else {
						res.push_back('N');
						posy += nb;
					}
				}
				else {
					if(diffy < 0) {
						res.push_back('N');
						posy += nb;
					}
					else {
						res.push_back('S');
						posy -= nb;
					}
				}
			}
		}
	}

	if(res.size() > 500) {
		cerr << nb << endl;
	}
	else {
		for(int i=0; i<res.size(); ++i) {
			cout << res[i];
		}
		cout << endl;
	}
}

int main() {
	int n_cases;
	cin >> n_cases;

	for(int i=0; i<n_cases; ++i) {
		cout << "Case #" << i+1 << ": ";
		algo();
	}
}

