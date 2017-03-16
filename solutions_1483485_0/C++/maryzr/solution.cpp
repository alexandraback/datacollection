#include <iostream>
using namespace std;

char a[26] = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
int t;
char s[105];

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	scanf("%d", &t);
	cin.getline(s, 105);

	for(int i=0; i<t; i++)
	{
		cin.getline(s, 105);
		printf("Case #%d: ", i + 1);

		for(int k=0; s[k]; k++)
		{
			if(s[k] >= 'a' && s[k] <= 'z') printf("%c", a[s[k] - 'a']);
			else printf("%c", s[k]);
		}
		printf("\n");	
	}
	
	return 0;
}