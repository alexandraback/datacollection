#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

using namespace std;

bool isok(char* s, int l) {
	for (int i = 0; i < l; i++) {
		if (s[i] != '+') {
			return false;
		}
	}
	return true;
}

void flip(char* s, int l) {
	int i;
	for (i = l - 1; i > -1; i--) {
		if (s[i] == '-') 
			break;
	}
	for (int k = 0; k < i+1; k++) {
		s[k] = s[k] == '-' ? '+' : '-';
	}
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int tt;
	scanf("%d", &tt);
	for (int qq = 1; qq <= tt; qq++) {
		printf("Case #%d: ", qq);
		char s[101];
		memset(s, 0, sizeof(s));
		scanf("%s", s);
		int l = strlen(s);
		int i = 0;
		while (!isok(s, l)) {
			flip(s, l);
			i++;
		}
		
		printf("%d\n", i);
	}
	return 0;
}
