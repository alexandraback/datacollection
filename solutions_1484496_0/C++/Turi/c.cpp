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
		int N;
		cin >> N;
		vector<int> S(N);
		for (int i = 0; i < N; i++)
			cin >> S[i];
		
		vector<int> T;
		T.reserve(N);

		cout << "Case #" << k + 1 << ": " << endl;;
		
		int two_to_N = 1 << N;
		int found = false;
		for (int i = 1; i < two_to_N && !found; i++){
			int j = i;
			
			int sum = 0, t = 0;
			while (j){
				if (j & 1) 
					sum += S[t];
				t++;
				j /= 2; 
			}
			
			if (sum % 2 != 0)
				continue;
			
			j = i;
			
			do {
				j = (j - 1) & i;
				
				t = 0;
				int k = j, part_sum = 0;
				while (k){
					if (k & 1) 
						part_sum += S[t];
					t++;
					k /= 2;
				}
				if (2 * part_sum == sum){
					found = true;
					k = j;
					t = 0;
					while (k){
						if (k & 1) 
							cout << S[t] << " ";
						t++;
						k /= 2;
					}
					cout << endl;
					k = i ^ j;
					t = 0;
					while (k){
						if (k & 1) 
							cout << S[t] << " ";
						t++;
						k /= 2;
					}
					cout << endl;
					
					break;
				}
			} while (j);
		}
		
		if (!found)
			cout << "Impossible" << endl;
	}
	return 0;
}
