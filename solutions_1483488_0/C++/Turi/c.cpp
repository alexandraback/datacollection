#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int b[2000001];

int main(int argc, char *argv[]){
	unsigned int T;

	if (argc >= 2){
		freopen(argv[1], "r", stdin);
		string outstr(argv[1]);
		int dot_pos = outstr.find_last_of('.');
		outstr = outstr.substr(0, dot_pos) + ".out";
		freopen(outstr.c_str(), "w", stdout);
	}

	cin >> T;
	for (unsigned int k = 0; k < T; k++){
		int A, B, result = 0;
		cin >> A >> B;

		for (int i = 0; i < 2000001; i++)
			b[i] = -1;

		int digits = 0, tmp = A, m = 1;
		while(tmp > 0) {
			digits++;
			tmp /= 10;
			m *= 10;
		}
		m /= 10;
		//cerr << digits << " digits; m = " << m << endl;
		
		for (int n = A; n <= B; n++){
			for (int i = 0, t = n; i < digits; i++){
				t = t / 10 + (t % 10) * m;
				//cerr << "t is " << t << endl;
				if (t > n && t <= B && b[t] != n){
					b[t] = n;
					//cout << "(" << n << ", " << t << ")" << endl;
					++result;
				}
			}
		}
		
		cout << "Case #" << k+1 << ": " << result << endl;
	}
	return 0;
}
