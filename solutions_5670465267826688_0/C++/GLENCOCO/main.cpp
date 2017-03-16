#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <inttypes.h>
using namespace std;

int sign(int a){
	if (a >= 0)return 1;
	else return -1;
}
//Quaternion multiplier
int QM(int a, int b, map <char, map<char, int>> Q){
	int sign = 1;
	if (a < 0){
		sign *= -1;
		a *= -1;
	}
	if (b < 0){
		sign *= -1;
		b *= -1;
	}
	return sign*Q[a][b];
}

void main(){
	//Create a map of a map to represent and easily access the quaternion matrix, an array would be quicker...
	map <char, map<char, int>> Q;
	Q[1][1] = 1;
	Q[1]['i'] = 'i';
	Q[1]['j'] = 'j';
	Q[1]['k'] = 'k';

	Q['i'][1] = 'i';
	Q['i']['i'] = -1;
	Q['i']['j'] = 'k';
	Q['i']['k'] = -'j';

	Q['j'][1] = 'j';
	Q['j']['i'] = -'k';
	Q['j']['j'] = -1;
	Q['j']['k'] = 'i';

	Q['k'][1] = 'k';
	Q['k']['i'] = 'j';
	Q['k']['j'] = -'i';
	Q['k']['k'] = -1;
	

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