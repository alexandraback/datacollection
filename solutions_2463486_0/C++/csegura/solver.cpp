#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long mypow(long long x, int n){
	long long current = 1;
	for (int i = 0; i < n; i++){
		current *= x;
	}
	return current;
}

int getDigits(long long current){
	int digits = 1;
	while(true){
		current /= 10;
		if (current == 0){
			return digits;
		} 
		digits++;
	}
}

int getDigit(long long current, int digit){
	return (current / mypow(10, (digit))) % 10;
}

void setDigit(long long &current, int digit, int value){
	current = current - getDigit(current, digit) * mypow(10, (digit)) + mypow(10, (digit)) * value;
}

long long firstPalyndrome(int nDigits){
	long long number = 0;
	setDigit(number, 0, 1);
	setDigit(number, nDigits - 1, 1);
	return number;
}

long long nextPalyndrome(long long current){
	int nDigits = getDigits(current);
	for (int i = nDigits / 2; i < nDigits; i++){
		int currentDigit = getDigit(current, i);
		if (currentDigit != 9){
			setDigit(current, i, currentDigit + 1);
			setDigit(current, nDigits - i - 1, currentDigit + 1);
			return current;
		} else {
			setDigit(current, i, 0);
			setDigit(current, nDigits - i - 1, 0);
		}
		
	}
	//Increase number of digits
	return firstPalyndrome(nDigits + 1);	
}

bool isPalyndrome(long long n){
	int nDigits = getDigits(n);
	for (int i = 0; i < nDigits/2; i++){
		if (getDigit(n, i) != getDigit(n, nDigits - i - 1)){
			return false;
		}
	}
	return true;
}

long long solve(long long A, long long B){
	long long count = 0;
	long long current = 1;
	while(true){
		if (current * current > B){
			break;	
		}
		if (isPalyndrome(current * current) && (current * current >= A)){
			count++;	
		}
		current = nextPalyndrome(current);
	}
	return count;
}

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		long long A, B;
		cin >> A >> B;
		cout << "Case #" << (i + 1) << ": " << solve(A, B) << endl; 
	}
}
