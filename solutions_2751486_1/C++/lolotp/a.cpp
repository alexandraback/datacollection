#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 1000010
char s[MAX];
int T;
int n;
string vowels = "aeiou";
int consCount[MAX];

int main() {
	scanf("%d",&T);
	
	for (int tc = 1; tc <= T; tc++) {
		scanf("%s %d",s, &n);
		int len = strlen(s);
		memset(consCount , 0, sizeof consCount);
		for (int i = 0; i < len; i++) {
			if (!(vowels.find_first_of(s[i]) != string::npos)) {
				consCount[i] = (i > 0 ? consCount[i-1] : 0) + 1;
			}
		}
		long long res = 0;
		int rightBorder = len;
		for (int i = len-1; i >= 0; i--) {
			if (consCount[i] >= n) {
				res += (long long)(i-n+2) * (long long)(rightBorder-i);
				rightBorder = i;
			}
		}
		printf("Case #%d: %lld\n", tc,res); 		
	}
	
	return 0; 
}
