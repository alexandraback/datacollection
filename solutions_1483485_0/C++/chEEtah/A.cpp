#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n;
int nt;

char maps[256];
char s[1000], z[1000];

int main()
{
	memset(maps, '?', sizeof maps);
	scanf("%d\n", &n);
	for(int i = 0; i < n; i++)
	{
		gets(s);
		gets(z);
		for(int j = 0; s[j]; j++) maps[s[j]] = z[j];
	}

	scanf("%d\n", &nt);
	
	for(int tt = 1; tt <= nt; tt++)
	{	
		printf("Case #%d: ", tt);
		
		gets(s);
		
		for(int i = 0; s[i]; i++) putchar(maps[s[i]]);
		puts("");
	}
	
	return 0;
}
