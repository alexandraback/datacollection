#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <cmath>
#include <list>
#include <map>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
bool isPalindromic(long long x){
	int digitList[17];
	int numDigits = 0;
	long long y = x;
	while(y > 0){
		digitList[numDigits] = y % 10;
		numDigits ++;
		y /= 10;
	}
	
	for(int i=0;i<numDigits;i++){
		if(digitList[i] != digitList[numDigits - 1 - i]){
			return false;
		}
	}
	return true;
}
bool isFair(long long x){
	return isPalindromic(x) && isPalindromic(x * x);
}
long long floorSqrt(long long x){
	long long high = 10000101;
	long long low = 0;
	while(high - low > 1){
		long long mid = (high + low)/2;
		if(mid*mid <= x){
			low = mid;
		} else {
			high = mid;
		}
	}
	return low;
}
int fairCumulative[10000100];
int main(){
	fairCumulative[0] = 0;
	for(int i=1;i<10000100;i++){
		fairCumulative[i] = fairCumulative[i-1] + (int)(isFair(i));
	}
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		long long A, B;
		cin >> A >> B;
		int answer = fairCumulative[floorSqrt(B)] - fairCumulative[floorSqrt(A-1)];
		cout << "Case #" << (t+1) << ": " << answer << endl;
	}
}
