#include <iostream>
#include <string>
#include <cmath>
#include <inttypes.h>
using namespace std;

int sign(int a){
	if (a >= 0)return 1;
	else return -1;
}
//Quaternion multiplier
int QM(int a, int b, int** Q){
	int sign = 1;
	if (a < 0){
		sign *= -1;
		a *= -1;
	}
	if (b < 0){
		sign *= -1;
		b *= -1;
	}
	switch (a){
	case 1:
		a = 0;
		break;
	case 'i':
		a = 1;
		break;
	case 'j':
		a = 2;
		break;
	case 'k':
		a = 3;
		break;
	}
	switch (b){
	case 1:
		b = 0;
		break;
	case 'i':
		b = 1;
		break;
	case 'j':
		b = 2;
		break;
	case 'k':
		b = 3;
		break;
	}
	return sign*Q[a][b];
}

void main(){
	//CHANGED THIS::::::::Create a map of a map to represent and easily access the quaternion matrix, an array would be quicker...
	//CONVERTED TO ARRAY much faster now
	int ** Q;
	Q = new int*[4];
	for (int q = 0; q < 4; q++)Q[q] = new int[4];
	Q[0][0] = 1;
	Q[0][1] = 'i';
	Q[0][2] = 'j';
	Q[0][3] = 'k';

	Q[1][0] = 'i';
	Q[1][1] = -1;
	Q[1][2] = 'k';
	Q[1][3] = -'j';

	Q[2][0] = 'j';
	Q[2][1] = -'k';
	Q[2][2] = -1;
	Q[2][3] = 'i';

	Q[3][0] = 'k';
	Q[3][1] = 'j';
	Q[3][2] = -'i';
	Q[3][3] = -1;
	

	int T;
	cin >> T;
	int64_t L, X;
	int xcount;
	string S,part;
	int target;
	int val;
	for (int t = 1; t <= T; t++){
		scanf_s("%" SCNd64, &L);
		scanf_s("%" SCNd64, &X);
		if (X > 12){//This is key for handling large values of X. Each repeated string will have the same value, if you multiply any quaternion value by itself 4 times, you get 1.
			X = 16 + (X % 4); //Want to ensure we have a full cycle of 4 strings for each of the 
		}
		cin >> S;
		target = 'i';
		val = 1;
		part = "";

		//Iterate through our string looking for I, J, and K in order by performing a kind of compound multiplication.
		while ((X > 0) || (part.length() != 0)){
			if (part.length() == 0){
				X--;
				part = S;
			}
			val = QM(val,part[0],Q);
			part.erase(0, 1);
			if ((val == target) || (val == -target)){
				switch ((char)target){
				case 'i':
					target = 'j';
					val = sign(val);
					break;
				case 'j':
					target = 'k';
					val = sign(val);
					break;
				case 'k':
					target = 1;
					val = sign(val);
					break;
				case 1:
					break;
				}
			}
		}
		cout << "Case #" << t << ": ";
		if (val == target)cout << "YES";
		else cout << "NO";
		cout << endl;

		
	}

}