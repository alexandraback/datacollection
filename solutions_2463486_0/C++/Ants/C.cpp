#include <iostream>
#include <string>

using namespace std;

long long pow10[19];

long long numAt(long long x, int i);
long long palinOdd(long long x);
long long palinEven(long long x);
int len(long long x);
bool isPalindrome(long long x);

int main(int argc, char** argv){
	
	long long p10 = 1;
	for (int i = 0; i <= 18; i++) {
		pow10[i] = p10;
		p10 *= 10;
	}
		
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		long long A, B;
		cin >> A >> B;	
		
		int count = 0;
		
		for (long long i = 1; true; i++) {
			long long pO = palinOdd(i);
			long long pE = palinEven(i);
			pO *= pO;
			pE *= pE;
			if (pE < A) continue;
			if (pO > B) break;
			if (pO >= A && isPalindrome(pO)) count++;
			if (pE <= B && isPalindrome(pE)) count++;
		}
		cout << "Case #" << t << ": " << count << endl; 
	}
	return 0;
}

long long numAt(long long x, int i) {
	return (x/pow10[i])%10;
}

long long palinOdd(long long x) {
	int l = len(x);
	long long palin = x*pow10[l-1];
	for (int i = 1; i < l; i++) {
		palin += pow10[l-i-1]*numAt(x,i);
	}
	return palin;
}
long long palinEven(long long x) {
	int l = len(x);
	long long palin = x*pow10[l];
	for (int i = 0; i < l; i++) {
		palin += pow10[l-i-1]*numAt(x,i);
	}
	return palin;
}

int len(long long x) {
	for (int i = 0; i < 19; i++) {
		if (x < pow10[i]) return i;
	}
	return 19;
}

bool isPalindrome(long long x) {
	int l = len(x);
	for (int i = 0; i < l/2; i++) {
		if (numAt(x, i) != numAt(x, l-1-i)) return false;
	}
	return true;
}
