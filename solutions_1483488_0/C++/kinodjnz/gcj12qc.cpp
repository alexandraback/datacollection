#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int digits(int x) {
	int d = 0;
	while (x > 0) {
		d++;
		x /= 10;
	}
	return d;
}

int rotate(int x, int d) {
	int a = x%10;
	x /= 10;
	for (int i = 0; i < d-1; i++) {
		a *= 10;
	}
	return x+a;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		int c = 0;
		for (int j = A; j < B; j++) {
			int d = digits(j);
			int y = j;
			set<int> s;
			for (int k = 0; k < d-1; k++) {
				y = rotate(y, d);
				if (j < y && y <= B)
					s.insert(y);
			}
			c += s.size();
		}
		printf("Case #%d: %d\n", i+1, c);
	}
}
