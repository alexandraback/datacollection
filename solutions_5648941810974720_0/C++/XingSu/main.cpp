#include <stdio.h>
#include <iostream>
#include <map>
#include <cstring>


using namespace std;
int tab[] = {0,2,8,3,4,5,1,6,7,9};
char num[][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char tabs[] = "ZWGHRFOXSI";
int ans[15] = {0};
char s[2010];


void gao()
{
	int i, j;
	int cnt;
	map<char, int> c;
	memset (ans, 0, sizeof(ans));
	for (i = 0; s[i]; i++)
		c[s[i]] ++;
	for (i = 0; i < 10; i++)
	{
		cnt = c[tabs[i]];
		for (j = 0; num[tab[i]][j]; j++)
			c[num[tab[i]][j]] -= cnt;
		ans[tab[i]] += cnt;
	}
	for (i = 0; i < 10; i++)
		for (j = 0; j < ans[i]; j++)
			printf ("%d", i);
	printf ("\n");
}


int main()
{
	int T;
	freopen ("A-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	scanf ("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf ("%s", s);
		printf ("Case #%d: ", cas);
		gao();
	}
	return 0;
}
