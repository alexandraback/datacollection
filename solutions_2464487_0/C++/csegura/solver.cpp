#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <strings.h>
#include <stdlib.h>

using namespace std;

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		long long r, t;
		cin >> r >> t;
		long long painted = 0;
		while (true){
			t -= (r + 1) * (r + 1) - r*r;
			r += 2;
			if (t < 0){
				break;
			} else {
				painted++;
			}
		}
		cout << "Case #" << (i + 1) << ": " << painted << endl; 
	}
}
