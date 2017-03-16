#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)

const int MAXL = 500 + 5;
int desX, desY, resLen;
char res[MAXL];

int main() {
	int test;	scanf("%d", &test);
	for (int ti = 1; ti <= test; ti++) {
		scanf("%d %d", &desX, &desY);

		resLen = 0;
		for (int i = 1; i <= abs(desX); i++) {
			res[resLen++] = desX > 0 ? 'W' : 'E';
			res[resLen++] = desX > 0 ? 'E' : 'W';
		}
		for (int i = 1; i <= abs(desY); i++) {
			res[resLen++] = desY > 0 ? 'S' : 'N';
			res[resLen++] = desY > 0 ? 'N' : 'S';
		}
		res[resLen] = '\0';
		printf("Case #%d: %s\n", ti, res);
	}
	return 0;
}
