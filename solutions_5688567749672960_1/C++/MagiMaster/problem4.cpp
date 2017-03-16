#include "problem4.h"

#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <array>
#include <string>
using namespace std;

void problem4(string filename) {
	ifstream infile(filename + ".in");
	ofstream outfile(filename + ".out");

	int small[10000] = { 0, 1 };
	for(int i = 2; i <= 9999; ++i) {
		small[i] = small[i - 1] + 1;
		if(i > 10 && (i % 10) > 0) {
			//int r = (i / 10) + 10 * (i % 10);
			int r = 99999;
			if(i < 10)
				r = i;
			else if(i < 100)
				r = (i / 10) + 10 * (i % 10);
			else if(i < 1000)
				r = (i / 100) + 10 * ((i / 10) % 10) + 100 * (i % 10);
			else if(i < 10000)
				r = (i / 1000) + 10 * ((i / 100) % 10) + 100 * ((i / 10) % 10) + 1000 * (i % 10);

			if(r < i)
				small[i] = min(small[i], small[r] + 1);
		}
	}

	int t;
	infile >> t;

	for(int z = 1; z <= t; ++z) {
		long long n;
		infile >> n;

		int test = -1, m;
		if(n < 10000) {
			test = small[n];
			m = n;
		}

		vector<int> cs;
		while(n > 0) {
			cs.push_back(n % 10);
			n /= 10;
		}

		long long c = 0;
		while(true) {
			if(cs.size() <= 2) {
				if(cs.size() == 1)
					c += small[cs[0]];
				else
					c += small[10 * cs[1] + cs[0]];
				break;
			}

			if(cs[0] == 0) {
				c += 1;
				for(int i = 0;; ++i) {
					if(cs[i] != 0) {
						if(i == cs.size() - 1 && cs[i] == 1)
							cs.pop_back();
						else
							cs[i] -= 1;
						break;
					}
					cs[i] = 9;
				}
			}

			for(long long i = 0, j = 1; i < cs.size() / 2; ++i, j *= 10) {
				if(i == 0) {
					c += cs[i] - 1;
					cs[i] = 1;
				} else {
					c += j * cs[i];
					cs[i] = 0;
				}
			}

			bool add = false;
			for(int i = 0, j = cs.size() - 1; i < j; ++i, --j) {
				if(cs[i] != cs[j])
					add = true;
				swap(cs[i], cs[j]);
			}
			if(add)
				c += 1;
			
			for(long long i = 0, j = 1; i < cs.size(); ++i, j *= 10) {
				if(i < cs.size() - 1)
					c += j * (cs[i] - 9);
				else
					c += j * cs[i];

				cs[i] = 9;
			}
			cs.pop_back();
		}

		//if(test > 0 && test != c)
		//	cout << m << " " << test << " " << c << endl;

		outfile << "Case #" << z << ": " << c << endl;
	}
}