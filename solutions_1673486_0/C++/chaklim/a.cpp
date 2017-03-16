#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

double c[200];
double p[200];
double d[200][200];
double e[200];
string s[] = {"111", "110", "101", "011", "100", "010", "001", "000"};

int main() {
	int t;
	int a, b;
	cin >> t;
	for (int C = 1; C <= t; C++) {
		cin >> a >> b;
		memset(c, 0, sizeof c);
		memset(d, 0, sizeof d);
		memset(e, 0, sizeof e);
		
		for (int i = 0; i < a; i++)
			cin >> p[i];
		
		double exp = 1.0f + b + 1.0f;		// give up and press enter
		double t;
		for (int i = 0; i < 8; i++) {
			double prob = 1;
			for (int j = 0; j < 3; j++)
				prob *= (s[i][j] == '1'? p[j] : (1.0f - p[j]));
			c[i] = prob;
		}
		
		// find no of keystrokes
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= 3; j++) {	// no of backspace used
				int minimum = 10;
				for (int k = 0; k < 3; k++)
					if (s[i][k] == '0')
						minimum = min(minimum, k);
				
				if (a - minimum <= j) {	// all right
					d[i][j] += (2 * j + 1 + b - a);
				}
				else {
					d[i][j] += (2 * j + 1 + b - a + 1 + b);
				}
			}
		}
		
		/*for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 3; j++)
				cout << d[i][j] << ' ';
			cout << endl;
		}*/
		
		// get expected value
		for (int i = 0; i < 8; i++) {
			if (c[i] != 0) {
				double texp = 0.0f;
				for (int j = 0; j < 3; j++)
					e[j] += c[i] * d[i][j];
			}
		}
		
		for (int i = 0; i < a; i++) {
			exp = min(exp, e[i]);
		}
		
		printf("Case #%d: %.6f\n", C, exp);
	}
	
	
	return 0;
}