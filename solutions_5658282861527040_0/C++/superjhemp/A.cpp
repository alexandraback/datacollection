#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int A, B, K;

int solve1(int A, int B, int K){
	int cnt = 0;
	for (int i = 0; i < A; i++)
	for (int j = 0; j < B; j++)
		cnt += (i&j) < K;
	return cnt;
}

int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> A >> B >> K;
		printf("Case #%d: %d\n", t, solve1(A, B, K));
	}
	return 0;
}

