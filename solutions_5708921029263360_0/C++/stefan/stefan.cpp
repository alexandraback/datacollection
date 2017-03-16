//Author: Stefan Toman

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		int j, p, s, k;
		cin >> j >> p >> s >> k;
		vector<int> jp(j*p, 0), js(j*s, 0), ps(p*s, 0);
		stringstream r;
		int a = 0;
		for(int tj = 0; tj < j; tj++) {
			for(int tp = 0; tp < p; tp++) {
				for(int ts = 0; ts < s; ts++) {
					if(jp[tj*p+tp] < k && js[tj*s+ts] < k && ps[tp*s+ts] < k) {
						a++;
						jp[tj*p+tp]++;
						js[tj*s+ts]++;
						ps[tp*s+ts]++;				
						r << tj + 1 << " " << tp + 1 << " " << ts + 1 << endl;
					}
				}
			}
		}
		cout << "Case #" << i+1 << ": " << a << endl << r.str();
	}
	return 0;
}

