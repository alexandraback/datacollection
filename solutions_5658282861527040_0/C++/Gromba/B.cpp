#include <stdlib.h>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <list>
#include <complex>
using namespace std;

typedef unsigned long long ui64;
typedef long long i64;

int win(int a, int b){
	return a & b;
}

void JeMoeder(int caseNr) {
	cout << "Case #" << caseNr << ": ";
	int A, B, K;
	cin >> A >> B >> K;
	int answer = 0;
	for(int i = 0; i < A; i++){
		for(int j = 0; j < B; j++){
			if(win(i,j) < K){
				answer++;
			}
		}
	}
	cout << answer << endl;
}

int main() {
	int runs; cin >> runs;
	for(int i = 1; i <= runs; i++){
		JeMoeder(i);
	}
	return 0;
}
