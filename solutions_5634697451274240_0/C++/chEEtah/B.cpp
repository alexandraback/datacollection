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
char s[1000];

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		scanf("%s", s);
		
		int cnt = 1;
		int n = strlen(s);
		for(int i = 1; i < n; i++) if (s[i] != s[i - 1]) cnt++;

		if (s[n - 1] == '+') cnt--;

		printf("%d\n", cnt);
	}
	return 0;
}