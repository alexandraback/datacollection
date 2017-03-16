#include <iostream> 
#include <cmath>
using namespace std;

void solve_case(int T){
	string c, j;
	cin >> c >> j;
	long long int maxC = 0, currC = 0, minC = 0;
	long long int maxJ = 0, currJ = 0, minJ = 0;
	long long int base = 0;

	for (int i = c.size() - 1; i >= 0; i--){
		base = pow(10, c.size() - 1 - i);
		if (c[i] == '?' && j[i] == '?'){
			if ((currJ - currC) <= (base + minJ - maxC) &&
				(currJ - currC) <= (base + minC - maxJ) &&
				(currC - currJ) <= (base + minJ - maxC) &&
				(currC - currJ) <= (base + minC - maxJ)){
				maxC += 9 * base;
				maxJ += 9 * base;
			} else if ((base + minJ - maxC) <= (base + minC - maxJ)){
				currJ = base + minJ;
				currC = maxC;
				maxC += 9 * base;
				maxJ += 9 * base;
			} else {
				currC = base + minC;
				currJ = maxJ;
				maxC += 9 * base;
				maxJ += 9 * base;
			}
		} else if (c[i] == '?'){
			if (((currJ - currC) < (base + minJ - maxC) || j[i] == '0') &&
				((currJ - currC) <= (base + minC - maxJ) || j[i] == '9') &&
				((currC - currJ) < (base + minJ - maxC) || j[i] == '0') &&
				((currC - currJ) <= (base + minC - maxJ) || j[i] == '9')){
				currC += (int)(j[i] - '0') * base;
				currJ += (int)(j[i] - '0') * base;
				maxC += 9 * base;
				maxJ += (int)(j[i] - '0') * base;
				minJ += (int)(j[i] - '0') * base;
			} else if (j[i] != '0' && (minJ - maxC) <= (minC - maxJ)){
				currC = ((int)(j[i] - '0') - 1) * base + maxC;
				currJ = (int)(j[i] - '0') * base + minJ;
				maxC += 9 * base;
				maxJ += (int)(j[i] - '0') * base;
				minJ += (int)(j[i] - '0') * base;
			} else {
				currC = ((int)(j[i] - '0') + 1) * base + minC;
				currJ = (int)(j[i] - '0') * base + maxJ;
				maxC += 9 * base;
				maxJ += (int)(j[i] - '0') * base;
				minJ += (int)(j[i] - '0') * base;
			}
		} else if (j[i] == '?'){
			if (((currJ - currC) <= (base + minJ - maxC) || c[i] == '9') &&
				((currJ - currC) < (base + minC - maxJ) || c[i] == '0') &&
				((currC - currJ) <= (base + minJ - maxC) || c[i] == '9') &&
				((currC - currJ) < (base + minC - maxJ) || c[i] == '0')){
				currC += (int)(c[i] - '0') * base;
				currJ += (int)(c[i] - '0') * base;
				maxJ += 9 * base;
				maxC += (int)(c[i] - '0') * base;
				minC += (int)(c[i] - '0') * base;
			} else if (c[i] != '0' && (minC - maxJ) <= (minJ - maxC)){
				currJ = ((int)(c[i] - '0') - 1) * base + maxJ;
				currC = (int)(c[i] - '0') * base + minC;
				maxJ += 9 * base;
				maxC += (int)(c[i] - '0') * base;
				minC += (int)(c[i] - '0') * base;
			} else {
				currJ = ((int)(c[i] - '0') + 1) * base + minJ;
				currC = (int)(c[i] - '0') * base + maxC;
				maxJ += 9 * base;
				maxC += (int)(c[i] - '0') * base;
				minC += (int)(c[i] - '0') * base;
			}
		} else {
			if (j[i] == c[i]){
				currC += (int)(c[i] - '0') * base;
				currJ += (int)(j[i] - '0') * base;
			} else if (j[i] > c[i]){
				currC = (int)(c[i] - '0') * base + maxC;
				currJ = (int)(j[i] - '0') * base + minJ;
			} else {
				currC = (int)(c[i] - '0') * base + minC;
				currJ = (int)(j[i] - '0') * base + maxJ;
			}
			maxC += (int)(c[i] - '0') * base;
			maxJ += (int)(j[i] - '0') * base;
			minC += (int)(c[i] - '0') * base;
			minJ += (int)(j[i] - '0') * base;
		}
	}

	string outC = "", outJ = "";
	char tmp;
	for (int i = 0; i < c.size(); i++){
		tmp = '0' + currC % 10;
		outC = tmp + outC;
		currC = currC/10;
		tmp = '0' + currJ % 10;
		outJ = tmp + outJ;
		currJ = currJ/10;
	}


	cout << "Case #" << T << ": " << outC << " " << outJ << endl;
}

// void solve_case(int T){
// 	string c, j;
// 	cin >> c >> j;

// 	bool jbig = false;
// 	bool cbig = false;
// 	for (int i = 0; i < c.size(); i++){
// 		if (!(jbig || cbig)){
// 			if (c[i] == '?' && j[i] == '?'){
// 				c[i] = '0';
// 				j[i] = '0';
// 			} else if (c[i] == '?'){
// 				c[i] = j[i];
// 			} else if (j[i] == '?'){
// 				j[i] = c[i];
// 			} else {
// 				if (c[i] > j[i]){
// 					cbig = true;
// 				}
// 				if (j[i] > c[i]){
// 					jbig = true;
// 				}
// 			}
// 		} else if (jbig){
// 			if (c[i] == '?'){
// 				c[i] = '9';
// 			}
// 			if (j[i] == '?'){
// 				j[i] = '0';
// 			}
// 		} else if (cbig){
// 			if (c[i] == '?'){
// 				c[i] = '0';
// 			}
// 			if (j[i] == '?'){
// 				j[i] = '9';
// 			}
// 		}
// 	}

// 	cout << "Case #" << T << ": " << c << " " << j << endl;
// }

int main() {
  	int t;
  	cin >> t; 
  	for (int i = 1; i <= t; i++) {
  	  solve_case(i);
  	}
  	return 0;
}