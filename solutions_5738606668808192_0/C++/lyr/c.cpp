#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

int n, J;
char s[40];
vector<int> v;

void makeJ() {//Ã¿´Î+2
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] == '0') {
			s[i] = '1';
			break;
		} 
		else s[i] = '0';
	}
}

int main() {
	int T;
	int kase = 0;
	scanf("%d", &T);
	printf("Case #1: \n");
	int num = 0;
	scanf("%d%d", &n, &J);
	s[0] = '1';
	for (int i = 1; i < n - 1; i++) s[i] = '0';
	s[n-1] = '1';
	while (true) {
		bool flag2 = true;
		for (int i = 2; i <= 10; i++) {
			bool flag = true;
			int tmp;
			for (int k = 2; k < 1000; k++) {
				tmp = 0;
				for (int j = 0; j < n; j++) {
					tmp = tmp * i + (s[j] == '1' ? 1 : 0);
					tmp %= k;
				}
				if (tmp == 0) {
					v.push_back(k);
					flag = false;
					break;
				}
			}
			if (flag) {
				v.clear();
				flag2 = false;
				break;
			}
		}
		if (flag2) {
			num++;
			printf("%s", s);
			for (int i = 0; i < v.size(); i++) {
				printf(" %d", v[i]);
			}
			printf("\n");
			if (num == J) break;
			v.clear();
		}
		makeJ();
	}
	return 0;
}
