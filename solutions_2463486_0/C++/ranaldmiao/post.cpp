#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string s[10005];
char str[105], str_a[105], str_b[105];
int n, fn;
bool cmp (string a, string b) {
	if (a.length() != b.length()) return a.length() < b.length();
	else {
		int l = a.length();
		for (int i = 0; i < l; ++i) {
			if (a[i] != b[i]) return a[i] < b[i];
		}
		return false;
	}
}
int main () {
	FILE* f = fopen("num7.txt", "r");
	fscanf(f, "%d", &fn);
	for (int i = 0; i <fn; ++i) {
		fscanf(f, "%s", str);
		s[i] = string(str);
	}
	fclose(f);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s %s", str_a, str_b);
		int a = lower_bound(s, s+fn, string(str_a), cmp)-s-1;
		int b = upper_bound(s, s+fn, string(str_b), cmp)-s-1;
		printf("Case #%d: %d\n", i+1, b-a);
	}
}