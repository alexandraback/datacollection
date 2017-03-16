#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int st[6][6];
char str[222222];
void Prepare() {
	st[1][1] = 1; st[1][2] = 2; 	st[1][3] = 3; st[1][4] = 4;
	st[2][1] = 2; st[2][2] = -1; 	st[2][3] = 4; st[2][4] = -3;
	st[3][1] = 3; st[3][2] = -4; 	st[3][3] = -1; st[3][4] = 2;
	st[4][1] = 4; st[4][2] = 3; 	st[4][3] = -2; st[4][4] = -1;
}
int T, n, L, X;
long long shit;
int main() {
	Prepare();
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		scanf("%d%lld", &L, &shit);
		scanf("%s", str + 1);
		if (shit <= 30)
			while (shit >= 17) shit -= 4;
		else
			shit = 16 + shit % 4;
		X = shit;
		for (int i = 1; i <= L; i++)
			str[i] = (str[i]=='1')?1:(str[i]-'i'+2);
		for (int i = L + 1; i <= L * X; i++)
			str[i] = str[i - L];
		L *= X;
		int rc = 1, beg = 0, end = 0;
		for (int i = 1; i <= L; i++) {
			if (rc > 0)	rc = st[rc][str[i]];
			else rc = -st[-rc][str[i]];
			if (rc == 2 && !beg)
				beg = i;
		}
		if (rc != -1)
			printf("NO\n");
		else {
			rc = 1;
			for (int i = L; i >= 1; i--) {
				if (rc > 0) rc = st[str[i]][rc];
				else rc = -st[str[i]][-rc];
				if (rc == 4) {
					end = i;
					break;
				}
			}
			if (beg && end && beg < end)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
