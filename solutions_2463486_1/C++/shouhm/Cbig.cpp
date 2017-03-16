#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int LIMIT = 25;

int L[LIMIT+10];

void DumpDownStack(int d) {
	for (int i = d; i >= 1; i --)
		printf("%d", L[i]);
}
void DumpUpStack(int d) {
	for (int i = 1; i <= d; i ++)
		printf("%d", L[i]);
}

void PutData(int d, int sum) {
	DumpDownStack(d);
	DumpUpStack(d);
	printf("\n");
	
	DumpDownStack(d);
	printf("0");
	DumpUpStack(d);
	printf("\n");
	
	if (sum + 1 < 10) {
		DumpDownStack(d);
		printf("1");
		DumpUpStack(d);
		printf("\n");
	}
	
	if (sum + 4 < 10) {
		DumpDownStack(d);
		printf("2");
		DumpUpStack(d);
		printf("\n");	
	}
}

void Search(int d, int sum) {
	if (d > LIMIT) {
		return;
	}
	for (int x = 0; x <= 2; x ++) {
		if (x == 0) {
			L[d] = x;
			Search(d + 1, sum);
		} else 
		if (x == 1 && (sum + 2 < 10)) {
			L[d] = x;
			PutData(d, sum + 2);
			if (sum < 9) 
				Search(d + 1, sum + 2);
		} else
		if (x == 2 && (sum + 8 < 10)) {
			L[d] = x;
			PutData(d, sum + 8);	
			if (sum < 9) 
				Search(d + 1, sum + 8);
		}
	}
}

int main() {
	freopen("num.txt", "w", stdout);
	printf("0\n");
	printf("1\n");
	printf("2\n");
	printf("3\n");
	Search(1, 0);
	return 0;
}

