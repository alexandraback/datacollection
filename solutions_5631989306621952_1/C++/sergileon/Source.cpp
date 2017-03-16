#pragma comment(linker, "/STACK:134217728")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <complex>
#include <functional>
#include <cmath>
#include <time.h>

using namespace std;

typedef long long LL;

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out", "w", stdout);
	int t;
	scanf("%d",&t);
	int numberTest = 1;
	while (t--) {
		string s;
		cin >> s;
		printf("Case #%d: ", numberTest++);
		string res = "";
		res += s[0];
		for (int i = 1; i < s.size(); i++) {
			if (s[i] >= res[0]) {
				res = s[i] + res;
			}
			else {
				res += s[i];
			}
		}
		cout << res << endl;
	}
	return 0;
}