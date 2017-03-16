#include <iostream>
#include <string>

using namespace std;
//#define DEBUG

string square(string A, int pullup) {
	string s = "";
	int digits = A.length();
	if(digits*2-1 > pullup) {
		for(int i=0; i<pullup; i++) {
			s += '9';
		}
		return s;
	}
	int *x = new int[digits*2], *y = new int[digits];
	for(int i=0; i<digits; i++) {
		x[i] = 0;
	}
	for(int i=0; i<digits; i++) {
		y[i] = A[i] - '0';
	}
	for(int i=0; i<digits; i++) {
		for(int j=0; j<digits; j++) {
			x[i+j] += y[i]*y[j];
		}
	}
	for(int i=digits*2-1; i<pullup; i++) {
		s += '0';
	}
	for(int i=0; i<digits; i++) {
		if(x[i] > 9) {
			cout << "WTF!!!   " << A << endl;
			for(int i=0; i<digits; i++) {
				cout << x[i] << endl;
			}
		}
		s += ('0'+x[i]);
	}
	for(int i=1; i<digits; i++) {
		s += ('0'+x[digits-1-i]);
	}
	//cout << s << endl;
	delete []x;
	delete []y;
	return s;
}

long long zxcv(string A) {
	int digits2 = A.length();
	long long ans = 0;
	if(digits2 > 1 || A[0] >= '9') {
		ans++; // 9 = 3*3
	}
	if(digits2 > 1 || A[0] >= '4') {
		ans++; // 4 = 2*2
	}
	if(digits2 > 1 || A[0] >= '1') {
		ans++; // 1 = 1*1
	}
	long long ones = 0;
	for(int digits = digits2/2; digits <= digits2/2+1; digits++) {
		for(int a=0; a<digits/2; a++) {
			for(int b=a+1; b<digits/2; b++) {
				for(int c=b+1; c<digits/2; c++) {
					for(int d=c+1; d<digits/2; d++) {
						string test = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
						test[a] = '1';
						test[b] = '1';
						test[c] = '1';
						test[d] = '1';
						test[digits-a-1] = '1';
						test[digits-b-1] = '1';
						test[digits-c-1] = '1';
						test[digits-d-1] = '1';
#ifdef DEBUG
						cout << test.substr(a,digits-2*a) << "^2 = " << square(test.substr(a,digits-2*a),digits2) << endl;
#endif
						if(square(test.substr(a,digits-2*a),digits2) <= A) ones++;
						if(digits%2 == 1) {
							test[digits/2] = '1';
#ifdef DEBUG
							cout << test.substr(a,digits-2*a) << "^2 = " << square(test.substr(a,digits-2*a),digits2) << endl;
#endif
							if(square(test.substr(a,digits-2*a),digits2) <= A) ones++;
						}
					}
					string test = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
					test += '\0';
					test[a] = '1';
					test[b] = '1';
					test[c] = '1';
					test[digits-a-1] = '1';
					test[digits-b-1] = '1';
					test[digits-c-1] = '1';
#ifdef DEBUG
					cout << test.substr(a,digits-2*a) << "^2 = " << square(test.substr(a,digits-2*a),digits2) << endl;
#endif
					if(square(test.substr(a,digits-2*a),digits2) <= A) ones++;
					if(digits%2 == 1) {
						test[digits/2] = '1';
#ifdef DEBUG
						cout << test.substr(a,digits-2*a) << "^2 = " << square(test.substr(a,digits-2*a),digits2) << endl;
#endif
						if(square(test.substr(a,digits-2*a),digits2) <= A) ones++;
					}
				}
				string test = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
				test += '\0';
				test[a] = '1';
				test[b] = '1';
				test[digits-a-1] = '1';
				test[digits-b-1] = '1';
#ifdef DEBUG
				cout << test.substr(a,digits-2*a) << "^2 = " << square(test.substr(a,digits-2*a),digits2) << endl;
#endif
				if(square(test.substr(a,digits-2*a),digits2) <= A) ones++;
				if(digits%2 == 1) {
					test[digits/2] = '1';
#ifdef DEBUG
					cout << test.substr(a,digits-2*a) << "^2 = " << square(test.substr(a,digits-2*a),digits2) << endl;
#endif
					if(square(test.substr(a,digits-2*a),digits2) <= A) ones++;

					test[digits/2] = '2';
#ifdef DEBUG
					cout << test.substr(a,digits-2*a) << "^2 = " << square(test.substr(a,digits-2*a),digits2) << endl;
#endif
					if(square(test.substr(a,digits-2*a),digits2) <= A) ones++;
				}
			}
			string test = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
			test += '\0';
			test[a] = '1';
			test[digits-a-1] = '1';
#ifdef DEBUG
			cout << test.substr(a,digits-2*a) << "^2 = " << square(test.substr(a,digits-2*a),digits2) << endl;
#endif
			if(square(test.substr(a,digits-2*a),digits2) <= A) ones++;
			if(digits%2 == 1) {
				test[digits/2] = '1';
#ifdef DEBUG
				cout << test.substr(a,digits-2*a) << "^2 = " << square(test.substr(a,digits-2*a),digits2) << endl;
#endif
				if(square(test.substr(a,digits-2*a),digits2) <= A) ones++;

				test[digits/2] = '2';
#ifdef DEBUG
				cout << test.substr(a,digits-2*a) << "^2 = " << square(test.substr(a,digits-2*a),digits2) << endl;
#endif
				if(square(test.substr(a,digits-2*a),digits2) <= A) ones++;
			}
			test = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
			test += '\0';
			test[a] = '2';
			test[digits-a-1] = '2';
#ifdef DEBUG
			cout << test.substr(a,digits-2*a) << "^2 = " << square(test.substr(a,digits-2*a),digits2) << endl;
#endif
			if(square(test.substr(a,digits-2*a),digits2) <= A) ones++;
			if(digits%2 == 1) {
				test[digits/2] = '1';
#ifdef DEBUG
				cout << test.substr(a,digits-2*a) << "^2 = " << square(test.substr(a,digits-2*a),digits2) << endl;
#endif
				if(square(test.substr(a,digits-2*a),digits2) <= A) ones++;
			}
		}
	}
	return ans+ones;
}

string minusminus(string A) {
	for(int i=A.length()-1; i>=0; i--) {
		if(A[i]!='0') {
			A[i]--;
			return A;
		} else {
			A[i] = '9';
		}
	}
	return A;
}

int main() {
	int T;
	cin >> T;
	for(int i=1; i<=T; i++) {
		string A, B;
		cin >> A >> B;
		cout << "Case #" << i << ": " << zxcv(B) - zxcv(minusminus(A)) << endl;
	}
	return 0;
}