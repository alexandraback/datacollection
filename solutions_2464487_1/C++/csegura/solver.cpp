#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <strings.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		long long r, t;
		cin >> r >> t;
		unsigned long long painted = 0;
		unsigned long long solution = (-2 * r + 1 + sqrt((2*r - 1) * (2*r - 1) + 4 * 2 * t)) / 4 - 10;
		solution = max(1ull, solution);
		while(true){
			unsigned long long used = (2 * r + 1 + 2 * (solution - 1)) * solution;
			if (used > t){
				cout << "Case #" << (i + 1) << ": " << solution - 1 << endl; 
				break;
			}
			solution++;
		}
		
	}
}
