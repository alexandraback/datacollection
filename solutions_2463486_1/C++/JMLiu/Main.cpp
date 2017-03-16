#include <iostream>
#include <cstdio>
#include <cstring>

__int64 ans[100];

bool StrIs(char *p) {
	int len = strlen(p);
	for (int i = 0 ; i < len / 2 ; i ++)
		if (p[i] != p[len - i - 1]) {
			delete []p;
			return false;
		}
	delete []p;
	return true;
}

bool IntIs(__int64 a) {
	char *p = new char[16];
	sprintf(p, "%I64d", a);
	return StrIs(p);
}

char *CreateStr1(__int64 a) {//直接反转
	char *p = new char[16];
	sprintf(p, "%I64d", a);
	int len = strlen(p);
	int j;
	for (int i = len, j = len - 1; j >= 0 ; i ++, j --)
		p[i] = p[j];
	p[len * 2] = '\0';
	return p;
}

char *CreateStr2(__int64 a) {//中间留一个翻转
	char *p = new char[16];
	sprintf(p, "%I64d", a);
	int len = strlen(p);
	int j;
	for (int i = len, j = len - 2 ; j >= 0 ; i ++, j --)
		p[i] = p[j];
	p[(len - 1) * 2 + 1] = '\0';
	return p;
}

__int64 StrToInt(char *p) {
	int len = strlen(p);
	__int64 j = 1LL, a = 0LL;
	for (int i = len - 1 ; i >= 0 ; i --) {
		a += j * __int64(p[i] - '0');
		j *= 10;
	}
	return a;
}

int fun() {
	int j = 0;
	for (__int64 i = 1LL ; i < 10000LL ; i ++) {
		__int64 temp = StrToInt(CreateStr2(i));
		temp *= temp;
		if (IntIs(temp)) {
			ans[j] = temp;
			j ++;
		} 
		if (i < 1000) {
			temp = StrToInt(CreateStr1(i));
			temp *= temp;
			if (IntIs(temp)) {
				ans[j] = temp;
				j ++;
			}
		}
	}
	return j;
}

void sortAns(int n) {
	for (int i = 0 ; i < n ; i ++)
		for (int j = i + 1 ; j < n ; j ++)
			if (ans[i] > ans[j]) std::swap(ans[i], ans[j]);
	return ;
}

int main() {
	freopen("C-large-1.in","r",stdin);freopen("C-large-1.out","w",stdout);
	int num = fun();
	sortAns(num);
	ans[num] = 100000000000001;
	int T;
	scanf("%d", &T);
	int c = T;
	while (T --) {
		__int64 a, b;
		int ai, bi;
		bool flaga = false, flagb = false;
		scanf("%I64d %I64d", &a, &b);
		for (int i = 0 ; i < num ; i ++) {
			if (a == ans[i]){ 
				flaga = true;
				ai = i;
			}else if (a > ans[i] && a < ans[i + 1]) {
				flaga = false;
				ai = i;
			}
			if (b == ans[i]) {
				flagb = true;
				bi = i;
			}else if (b > ans[i] && b < ans[i + 1]){
				flagb = false;
				bi = i;
			}
		}
		if (flaga) printf("Case #%d: %d\n", c - T, bi - ai + 1);
		else printf("Case #%d: %d\n", c - T, bi - ai);
	}
	//system("pause");
	return 0;
}