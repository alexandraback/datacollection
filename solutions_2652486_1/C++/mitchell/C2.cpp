#include <bitset>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <deque>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <complex>
#include <cstring>
#include <map>
#include <stack>
using namespace std;
long long prods[12];
int v2prods[12];
int v7(long long n){
	if(n % 7){
		return 0;
	}
	return v7(n/7) + 1;
}
int v5(long long n){
	if(n % 5){
		return 0;
	}
	return v5(n/5) + 1;
}
int v3(long long n){
	if(n % 3){
		return 0;
	}
	return v3(n/3) + 1;
}
int v2(long long n){
	if(n % 2){
		return 0;
	}
	return v2(n/2) + 1;
}
int rd(double d){
	return (int)(d + 0.5);
}
int pow3[7] = {1, 3, 9, 27, 81, 243, 729};
int main(){

	int T, R, N, M, K;
	cin >> T >> R >> N >> M >> K;
	cout << "Case #1:\n";
	for(int q=0;q<R;q++){
		int totalSeven = 0;
		int totalFive = 0;
		int totalThree = 0;
		int totalTwo = 0;
		int totalThreeTimesTwo = 0;
		int totalTwoTimesTwo = 0;
		for(int i=0;i<K;i++){
			cin >> prods[i];
			totalSeven += v7(prods[i]);
			totalFive += v5(prods[i]);
			totalThree += v3(prods[i]);
			totalTwo += v2(prods[i]);
			totalThreeTimesTwo += v2(prods[i]) * v3(prods[i]);
			totalTwoTimesTwo += v2(prods[i]) * v2(prods[i]);
		}
		double numSevens = totalSeven / 6.0;
		double numFives = totalFive / 6.0;
		double numSixes = 4.0 * ((totalThreeTimesTwo) / 12.0 - (totalThree / 12.0) * (totalTwo / 12.0));
		double numThrees = totalThree / 6.0 - numSixes;
		double varTwos = totalTwoTimesTwo / 12.0 - (totalTwo/12.0) * (totalTwo/12.0);
		double numTwos = 4.0 * (totalTwo / 12.0 - (varTwos - (numSixes / 4.0)));
		double numFours = varTwos - numTwos/2.0;
		if(rd(numSevens) >= 0 && rd(numFives) >= 0 && rd(numSixes) >= 0 && rd(numThrees) >= 0 && rd(numTwos) >= 0 && rd(numFours) >= 0 && rd(numSevens) + rd(numFives) + rd(numSixes) + rd(numThrees) + rd(numTwos) + rd(numFours) <= 12){
			for(int i=0;i<rd(numSevens);i++){
				cout << "7";
			}
			for(int i=0;i<rd(numFives);i++){
				cout << "5";
			}
			for(int i=0;i<rd(numSixes);i++){
				cout << "6";
			}
			for(int i=0;i<rd(numThrees);i++){
				cout << "3";
			}
			for(int i=0;i<rd(numTwos);i++){
				cout << "2";
			}
			for(int i=0;i<rd(numFours);i++){
				cout << "4";
			}
			for(int i=0;i<12 - (rd(numSevens) + rd(numFives) + rd(numSixes) + rd(numThrees) + rd(numTwos) + rd(numFours)); i++){
				cout << "8";
			}
			cout << endl;
		} else {
			cout << "876543287654" << endl;
		}
		
	}
}
