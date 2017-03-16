#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

ifstream in;
ofstream out;

int trace(int P, int Q) {
	if(P==1 && Q==1) return 1;
	if(P==0 && Q==1) return 1;
	int count=0;
	while(P<Q) {
		if(Q%2 == 1) return -1;
		Q /= 2;
		count ++;
	}
	if(P>Q) {
		int check = trace(P-Q,Q);
		if(check == -1) return -1;
	}
	return count;
}

int main() {
	freopen("A-small-attempt0.in","r", stdin);
	freopen("out.txt","w", stdout);
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++) {
		int P, Q;
		scanf("%d/%d", &P, &Q);
		printf("Case #%d: ", t);
		int count = trace(P,Q);
		if(count != -1) printf("%d\n", count);
		else puts("impossible");
	}
}
