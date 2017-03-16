#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;

int t[1111];
int good[111];
int almost[111];

void doit() {
	int n, s, p;
	scanf("%d%d%d", &n, &s, &p);
	for (int i=0;i<n;i++) scanf("%d", &t[i]);
	int r1 = 0;
	int r2 = 0;
	for (int i=0;i<n;i++) {
		int a1 = t[i] / 3;
		int a2 = (t[i] + 2) / 3;
		good[i] = a2 >= p;
		if (good[i])
			r1++;
		else
		if (t[i] >= 2) {
			int ma = (t[i] - 2)/3 + 2; 
			if (ma >= p)
				r2++;
		}
	}

	int res = r1 + min(r2, s);
	printf("%d", res);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++){
		printf("Case #%d: ", i+1);
		doit();
		printf("\n");
	}

	return 0;
}
