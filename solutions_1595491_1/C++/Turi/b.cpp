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
		int N, S, p, result = 0;;
		cin >> N >> S >> p;
		for (int i = 0; i < N; i++){
			int t;
			cin >> t;
			
			if (t >= p + max(p-1, 0) + max(p-1, 0))
				result++;
			else if (t >= p + max(p-2, 0) + max(p-2, 0)){
				if (S > 0){
					--S;
					result++;
				}
			}
		}
		
		cout << "Case #" << k+1 << ": " << result << endl;
	}
	return 0;
}
