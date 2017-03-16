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

inline bool isGood(const vector<int> &s, int N, int X, unsigned int i, double y_i){
	double f = 1 - y_i;
	double P = s[i] + X * y_i;
	for (unsigned int j = 0; j < s.size(); j++)
		if (j != i && s[j] < P)
			f -= (P - s[j]) / (double)X;
	return f >= 0;
}

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
		unsigned int N, X = 0;
		cin >> N;
		vector<int> s(N);
		for (unsigned int i = 0; i < N; i++){
			cin >> s[i];
			X += s[i];
		}
		
		cout << "Case #" << k + 1 << ": ";
		cout.precision(10);
		
		for (unsigned int i = 0; i < N; i++){
			double start = 0;
			double end = 1;
			while (end - start > 0.000000001) {
				double m = (start + end) / 2;
				
				if (isGood(s, N, X, i, m))
					start = m;
				else
					end = m;
			}
			cout << start*100 << " ";
		}
		
		cout << endl;
	}
	return 0;
}
