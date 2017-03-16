#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

char	c[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
int N;
char	line[999];

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	scanf("%d", &T); gets(line);
	for (int t = 1; t <= T; ++ t)
	{
		printf("Case #%d: ", t);
		for (char ch = getchar(); ch != '\n'; ch = getchar())
			if (ch == ' ') printf(" ");
			else	printf("%c", c[ch - 'a']);
		printf("\n");
	}
	return 0;
}
	
