#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

string str;

int main() {
	int tests;
	scanf("%d", &tests);
	for (int testCount = 1; testCount <= tests; testCount++) {
		static char buffer[1111];
		scanf("%s", buffer);
		str = "";
		for (int i = 0; buffer[i]; i++) {
			str = max(str + buffer[i], buffer[i] + str);
		}
		printf("Case #%d: %s\n", testCount, str.c_str());
	}
}
