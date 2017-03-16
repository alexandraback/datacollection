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

using namespace std;

#define CODE_1 1
#define CODE_i 2
#define CODE_j 3
#define CODE_k 4

int charToCode[256];
int mult[5][5];

int main(){
	charToCode['i'] = CODE_i;
	charToCode['j'] = CODE_j;
	charToCode['k'] = CODE_k;

	mult[CODE_1][CODE_1] = CODE_1;
	mult[CODE_1][CODE_i] = CODE_i;
	mult[CODE_1][CODE_j] = CODE_j;
	mult[CODE_1][CODE_k] = CODE_k;
	mult[CODE_i][CODE_1] = CODE_i;
	mult[CODE_i][CODE_i] = -CODE_1;
	mult[CODE_i][CODE_j] = CODE_k;
	mult[CODE_i][CODE_k] = -CODE_j;
	mult[CODE_j][CODE_1] = CODE_j;
	mult[CODE_j][CODE_i] = -CODE_k;
	mult[CODE_j][CODE_j] = -CODE_1;
	mult[CODE_j][CODE_k] = CODE_i;
	mult[CODE_k][CODE_1] = CODE_k;
	mult[CODE_k][CODE_i] = CODE_j;
	mult[CODE_k][CODE_j] = -CODE_i;
	mult[CODE_k][CODE_k] = -CODE_1;


	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++){
		int L, X;
		cin >> L >> X;
		string str;
		cin >> str;
		bool canBeFirst[L * X];
		int current = CODE_1;
		for (int i = 0; i < L * X; i++){
			if (current < 0){
				current = - mult[-current][charToCode[(unsigned char)str[i % L]]];
			} else {
				current = mult[current][charToCode[(unsigned char)str[i % L]]];
			}
			if (current == CODE_i){
				canBeFirst[i] = true;
			} else {
				canBeFirst[i] = false;
			}
		}
		bool canBeLast[L*X];
		current = CODE_1;
		for (int i = L * X - 1; i >= 0; i--){
			if (current < 0){
				current = - mult[charToCode[(unsigned char)str[i % L]]][-current];
			} else {
				current = mult[charToCode[(unsigned char)str[i % L]]][current];
			}
			if (current == CODE_k){
				canBeLast[i] = true;
			} else {
				canBeLast[i] = false;
			}
		}
		bool found = false;
		for (int first = 0; first < L * X; first++){
			if (!canBeFirst[first]){
				continue;
			}
			int current = CODE_1;
			for (int second = first + 1; second < L * X - 1; second++){
				if (current < 0){
					current = - mult[-current][charToCode[(unsigned char)str[second % L]]];
				} else {
					current = mult[current][charToCode[(unsigned char)str[second % L]]];
				}
				if ((current == CODE_j) && (canBeLast[second + 1])){
					found = true;
					break;
				}
			}
			if (found){
				break;
			}
		}
		if (found){
			cout << "Case #" << (t+1) << ": YES" << endl;
		} else {
			cout << "Case #" << (t+1) << ": NO" << endl;
		}
	}
}
