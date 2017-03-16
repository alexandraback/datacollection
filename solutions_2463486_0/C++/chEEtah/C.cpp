#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;

char s[100];
int palin(int x)
{
	sprintf(s, "%d", x);
	int n = strlen(s);
	for(int i = 0; i < n; i++) if (s[i] != s[n - i - 1]) return false;
	return true;
}

int good(int x)
{
	if (!palin(x)) return 0;
	for(int i = 0; i <= x; i++) if (i * i == x && palin(i)) return true;
	return false;
}

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		int A, B;
		scanf("%d %d", &A, &B);

		int res = 0;
		for(int i = A; i <= B; i++) res += good(i);

		printf("%d\n", res);
	}
	return 0;
}