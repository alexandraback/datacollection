#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int map[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q',};
int main()
{
	int n;
	int cas=0;
	char s[200];
	cin>>n;
	gets(s);
	while (n--)
	{
		gets(s);
		printf("Case #%d: ",++cas); 
		for (int i=0;i<strlen(s);i++)
			if (s[i]!=' ') putchar(map[s[i]-'a']);
			else putchar(' ');
		putchar(10);
	}
	return 0;
}
