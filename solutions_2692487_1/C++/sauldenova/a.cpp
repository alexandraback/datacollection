//a.cpp
//By λKT345

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 102;
const int MAXSIZE = 1E6 + 2;

#define TR(container, it) \
	for(typeof(container.begin()) it = container.begin(); it != container.end(); ++it)

int N, A, maxVal;
int sizes[MAXN];
int mem[MAXN][MAXSIZE];

pii calcDist(int a, int b) {
	if(a == 1) {
		return make_pair(a, MAXSIZE + 1);
	}
	int newA = a, currPot = 1, count = 0;
	while(newA - (currPot - 1) <= b) {
		currPot *= 2; newA *= 2; count++;
	}
	return make_pair(newA - (currPot - 1), count);
}

int dynamic(int place, int currSize) {
	if(currSize > maxVal) {
		return 0;
	}
	if(mem[place][currSize] == -1) {
		if(place >= N) {
			mem[place][currSize] = 0;
		} else {
			if(currSize == 1) {
				mem[place][currSize] = dynamic(place + 1, currSize) + 1;
			} else {
				pii calc = calcDist(currSize, sizes[place]);
				mem[place][currSize] = min(dynamic(place + 1, currSize) + 1,
										   dynamic(place + 1, calc.first + sizes[place]) + calc.second);
			}
		}
	}
	return mem[place][currSize];
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t) {
		scanf("%d%d", &A, &N);
		maxVal = -1;
		for(int i = 0; i < N; ++i) {
			scanf("%d", sizes + i);
			maxVal = max(maxVal, sizes[i]);
		}
		for(int i = 0; i <= N; ++i) {
			for(int j = 0; j <= maxVal; ++j) {
				mem[i][j] = -1;
			}
		}
		sort(sizes, sizes+N);
		printf("Case #%d: %d\n", t, dynamic(0, A));
	}
	return 0;
}
