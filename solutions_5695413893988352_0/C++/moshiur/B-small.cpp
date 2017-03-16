#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;


bool match(int x, char p[], int len) {
	for (int i=len-1;i>=0;--i) {
		int d = x%10; x/=10;
		if (p[i]=='?' || (p[i]-'0')==d) {
		} else {
			return false;
		}
	}

	return true;
}

bool better(int x, int y, int X, int Y) {
	if (abs(x-y) < abs(X-Y)) return true;

	if (abs(x-y)==abs(X-Y) && x < X) return true;
	if (abs(x-y)==abs(X-Y) && x == X && y < Y) return true;

	return false;
}

void Print(int ans, int len) {
	int buf[100];
	for (int j=0;j<len;++j){buf[j] = ans%10; ans/=10;};
	printf(" ");
	for (int j=len-1;j>=0;--j) printf("%d", buf[j]);
}

int main() {
	int T;scanf("%d",&T);
	for(int t=1;t<=T;++t){
		char C[5], J[5]; scanf("%s%s",C,J);
		int len = strlen(C);

		int lo = 0, hi = 999;
		if (len==2) hi=99;
		if (len==1) hi=9;

		int ans_C = -1, ans_J = -1;

		for (int i=lo;i<=hi;++i)for(int j=lo;j<=hi;++j){
			if (match(i,C,len) && match(j, J, len)) {
				if (ans_C == -1) {
					ans_C = i; ans_J = j;
				} else if (better(i,j, ans_C, ans_J)) {
					ans_C = i; ans_J = j;
				}
			}
		}

		printf("Case #%d:", t); Print(ans_C, len); Print(ans_J, len); puts("");
	}
	return 0;
}

