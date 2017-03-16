#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int map[26] = {24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 8, 6, 11, 1, 10, 17, 25, 19, 13, 22, 9, 15, 5, 12, 0, 16};

int main ()
{
	//freopen("data.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tc;		scanf("%d", &tc);	getchar();
	for (int T =1; T<= tc; T++)
	{
		char s[200];	gets(s);
		printf("Case #%d: ", T);
		for (int i = 0; s[i] != '\0'; i++)
			if (s[i] == ' ')	printf(" ");
			else	printf("%c", char('a' + map[s[i]-'a']));
		printf("\n");
	}
}
