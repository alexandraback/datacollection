#include <iostream>
#include <vector>
#include <string>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

BigInteger precalculated[70] = {1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002, 10000001, 10011001, 10100101, 10111101, 11000011, 11011011, 11100111, 11111111, 20000002, 100000001, 100010001, 100020001, 100101001, 100111001, 100121001, 101000101, 101010101, 101020101, 101101101, 101111101, 110000011, 110010011, 110020011, 110101011, 110111011, 111000111, 111010111, 111101111, 111111111, 200000002, 200010002};

BigInteger mypow(BigInteger x, BigInteger n){
	BigInteger current = 1;
	for (BigInteger i = 0; i < n; i++){
		current *= x;
	}
	return current;
}

BigInteger getDigits(BigInteger current){
	BigInteger digits = 1;
	while(true){
		current /= 10;
		if (current == 0){
			return digits;
		} 
		digits++;
	}
}

BigInteger getDigit(BigInteger current, BigInteger digit){
	return (current / mypow(10, (digit))) % 10;
}

bool isPalyndrome(BigInteger n){
	BigInteger nDigits = getDigits(n);
	for (BigInteger i = 0; i < nDigits/2; i++){
		if (getDigit(n, i) != getDigit(n, nDigits - i - 1)){
			return false;
		}
	}
	return true;
}

BigInteger solve(BigInteger A, BigInteger B){
	BigInteger count = 0;
	BigInteger current = 1;
	for (int i = 0; i < 70; i++){
		if ((precalculated[i]*precalculated[i] >= A) && (precalculated[i] * precalculated[i] <= B)){
			count++;
		}
	}
	return count;
}

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		BigInteger A, B;
		string Astr, Bstr;
		A = 0;
		B = 0;
		cin >> Astr >> Bstr;
		for (int j = 0; j < Astr.size(); j++){
			A = A * 10 + (Astr[j] - '0');
		}
		for (int j = 0; j < Bstr.size(); j++){
			B = B * 10 + (Bstr[j] - '0');
		}
		cout << "Case #" << (i + 1) << ": " << solve(A, B) << endl; 
	}
}
