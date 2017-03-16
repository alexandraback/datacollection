#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 309;

char s[10][MAX] = {
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"our language is impossible to understand",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"there are twenty six factorial possibilities",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv",
	"so it is okay if you want to just give up"
	};

char mp[MAX], G[MAX];

int main()
{
	
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	memset(mp, '*', sizeof(mp));
	for(int i = 0; i < 5; i += 2)
	{
		int n = strlen(s[i]);
		for(int j = 0; j < n; j++)    mp[s[i][j]] = s[i+1][j];
	}
	
	mp['q'] = 'z';
	mp['z'] = 'q';
//	for(int i = 0; i < MAX; i++) if(mp[i] >= 'a' && mp[i] <= 'z') printf("%c -> %c\n", i, mp[i]);
	
	int T;    cin >> T;    gets(G);
	for(int cas = 1; cas <= T; cas ++)
	{
		gets(G);
		int n = strlen(G);
		
		printf("Case #%d: ", cas);
		for(int i = 0; i < n; i++)	putchar(mp[G[i]]);
		putchar('\n');	
	}
	
	//while(1);
	return 0;	
}
