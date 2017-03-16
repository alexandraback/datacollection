#include <iostream>
#include <cstdio>
#include <cstring>  
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>

using namespace std;
 
const int maxn = 1005;

char s[maxn], t[maxn];

int main() {
	int cases;
	scanf("%d", &cases);
	for (int o = 0; o < cases; ++o) {
		scanf("%s", s);
		int n = strlen(s);
		t[0] = s[0];
		for (int i = 1; i < n; ++i) {
			bool flag = 0;
			if (s[i] < t[0]) {
				flag = 0;
			} else if (s[i] > t[0]) {
				flag = 1;
			} else {
				for (int j = 0; j < i; ++j) {
					if (t[j] < t[j + 1]) {
						flag = 0;
						break;
					} else if (t[j] > t[j + 1]) {
						flag = 1; 
						break;
					}
				}
			}
			if (flag) {
				for (int j = i; j > 0; --j) {
					t[j] = t[j - 1];
				}
				t[0] = s[i];
			} else {
				t[i] = s[i];
			}
		}
		t[n] = 0;
		printf("Case #%d: %s\n", o + 1, t);
	}
	return 0;
}


