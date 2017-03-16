#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef unsigned long long ull;

const int SIZE = 1000001;
int T;
int N;
string str;
int minLength[SIZE];

void calcDP() {
	int curCons = 0;
	minLength[str.length()] = SIZE;
	for( int i = str.length() - 1; i >= 0; i--) {
		if( str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ) {
			curCons = 0;
		} else {
			curCons++;
		}
		if( curCons >= N ) {
			minLength[i] = N;
		} else {
			minLength[i] = minLength[i+1]+1;
		}
	}
}

ull calcResult() {
	ull res = 0;
	for( size_t i = 0; i < str.length(); i++) {
		size_t end = i + minLength[i];
		if( end <= str.length() ) {
			res += str.length() - end + 1;
		}
	}
	return res;
}

int main() {
	scanf("%d", &T);
	for( int t = 0; t < T; t++) {
		cin>>str>>N;
		calcDP();
		ull result = calcResult();
		cout<<"Case #"<<t+1<<": "<<result<<endl;
	}
}
