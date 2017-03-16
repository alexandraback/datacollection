#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <conio.h>
#include <functional>
#include <math.h>
#include <algorithm>
#include <time.h>
using namespace std;
char S[1005];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int runs = 1;
	int T; for (scanf("%d", &T); T--;) {
		scanf("%s", S);
		string a = "";
		for (int i = 0; S[i]; i++) {
			string b = a + S[i];
			string c = S[i] + a;
			if (b > c) a = b;
			else a = c;
		}
		printf("Case #%d: %s\n", runs++, a.c_str());
	}
	return 0;
}