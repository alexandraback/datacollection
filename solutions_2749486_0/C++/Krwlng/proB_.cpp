#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

void conduct() {
	int x, y, i;
	scanf("%d%d", &x, &y);
	for (i=0; i<abs(x); ++i) {
		if (x<0) printf("EW"); else printf("WE");
	}
	for (i=0; i<abs(y); ++i) {
		if (y<0) printf("NS"); else printf("SN");
	}
	printf("\n");
}

int main() {
	int time; scanf("%d", &time);
	for (int i=1; i<=time; ++i) {
		printf("Case #%d: ", i);
		conduct();
	}
	return 0;
}
