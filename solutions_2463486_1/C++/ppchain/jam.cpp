#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

long long fsnum[100];
int fsl;
int val[9] = {0, 1, 10, 100, 1000};

int rev(int x)
{
	int ret = 0;
	while (x) {
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	return ret;
}

long long rev(long long x)
{
	long long ret = 0;
	while (x) {
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	return ret;
}

void gernerate()
{
	//int cnt = 0;
	for (int i = 0; i < 7; ++i) {
		int l = val[i / 2], r = val[i / 2 + 1];
		int t = (i & 1) ? 100 : 10, z = (i & 1) ? 11 : 1;
		long long num, tmp;
		for (int j = l; j < r; ++j) {
			for (int k = (i < 2) ? 1 : 0, x = (i < 2) ? z : 0; k < 10; ++k, x += z) {
				num = ((long long)(j) * t + x) * r + rev(j);
				tmp = num * num;
				if (tmp == rev(tmp)) {
					//printf("%lld ", tmp);
					fsnum[fsl++] = tmp;
				}
			}
		}
		//printf("\n");
	}
	//printf("%d\n", cnt);
}

int main() 
{
	freopen("C-large-1.in", "r", stdin);
	freopen("jam.out", "w", stdout);
	gernerate();
	/*
	printf("fsl = %d\n", fsl);
	for (int i = 0; i < fsl; ++i) {
		printf("%lld ", fsnum[i]);
	}
	printf("\n");
	*/
	int ncas;
	scanf("%d", &ncas);
	long long left, right;
	int le, re;
	for (int cas = 1; cas <= ncas; ++cas) {
		scanf("%lld%lld", &left, &right);
		le = (lower_bound(fsnum, fsnum + fsl, left) - fsnum);
		re = (upper_bound(fsnum, fsnum + fsl, right) - fsnum) - 1;
		re -= le;
		printf("Case #%d: %d\n", cas, (re < 0) ? 0 : (re + 1));
	}
	//system("pause");
	return 0;
}
