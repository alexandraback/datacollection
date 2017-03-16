#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <time.h>
#include <bitset>
#include <list>
#include <assert.h>
#include <time.h>
using namespace std;

bool finding(int A, int B) {
	bool logic = false;
	while(A != 0) {
		if(A % 10 == B) {
			logic = true;
			break;
		}
		A /= 10;
	}
	return logic;
}

int X[10] = {0,0,0,0,0,0,0,0,0,0};

int main() {
	int T, N;
	cin >> T;
	for(int y = 0; y < T; ++y) {
		memset(X, 0, sizeof(X));
		cin >> N;
		if(N == 0) {
			printf("Case #%d: INSOMNIA\n", y+1);
		} else {
			int M = N;
			int counter = 0;
			while(counter != 10) {
				for(int i = 0; i < 10; ++i) {
					if(X[i] == 0) {
						if(finding(N,i)){
							X[i] = 1;
							counter++;
						}
					}
				}
				N += M;
			}
			N -= M;

			printf("Case #%d: %d\n", y+1, N);
		}
	}
}