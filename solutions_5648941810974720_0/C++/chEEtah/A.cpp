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

char s[3000];
int cnt[100];

int res[10];

void go(int d, char c, char *s)
{
	int times = cnt[c - 'A'];
	for(int i = 0; s[i]; i++) cnt[s[i] - 'A'] -= times;
	res[d] += times;
}

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		scanf("%s", s);

		memset(cnt, 0, sizeof cnt);
		memset(res, 0, sizeof res);

		for(int i = 0; s[i]; i++) cnt[s[i] - 'A']++;
		
		go(0, 'Z', "ZERO");
		go(2, 'W', "TWO");
		go(8, 'G', "EIGHT");
		go(3, 'H', "THREE");
		go(6, 'X', "SIX");
		go(7, 'S', "SEVEN");
		go(5, 'V', "FIVE");
		go(4, 'F', "FOUR");
		go(1, 'O', "ONE");
		go(9, 'I', "NINE");

		for(int i = 0; i < 26; i++) assert(cnt[i] == 0);

		for(int i = 0; i < 10; i++)
			while(res[i] > 0)
			{
				printf("%d", i);
				res[i]--;
			}
		puts("");
	}
	return 0;
}