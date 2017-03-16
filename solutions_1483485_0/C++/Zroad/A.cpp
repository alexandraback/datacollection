/*
a b c d e f g h i j k l m n o p q r s t u v w x y z
y h e s o c v x d u i g l b k r z t n w j p f m a q
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;

const char map[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b',
                      'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
char s[110];
int T, tcase;

int main()
{
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	for (scanf("%d\n", &T), tcase = 1; tcase <= T; tcase ++)
	{
		gets(s);
		printf("Case #%d: ", tcase);
		for (int i = 0; s[i]; i ++)
		{
			if (isalpha(s[i]))  putchar(map[s[i] - 'a']);
				else  putchar(s[i]);
		}
		printf("\n");
	}
	return 0;
}
