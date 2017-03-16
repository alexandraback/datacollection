#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

int main(){
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; i++){
		int A, B, K;
		cin >> A >> B >> K;
		int solution = 0;
		for (unsigned int j = 0; j < A; j++){
			for (unsigned int k = 0; k < B; k++){
				if ((j & k) < K){
					solution++;
				}
			}
		}
		cout << "Case #" << (i+1) << ": " << solution << endl;
	}
}
