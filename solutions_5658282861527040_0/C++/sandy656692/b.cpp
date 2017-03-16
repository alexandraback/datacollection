#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int N = 110;
char s[N][N];
int top[N];
int len[N];
int num[N];
char ch[N];

int main() {
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; ++test) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int ans = 0;
		for (int i = 0; i < a; ++i)
			for (int j = 0; j < b; ++j) 
				if ((i & j) < c) ++ans;
		printf("Case #%d: ", test);
		printf("%d\n", ans);
	}
	return 0;
}