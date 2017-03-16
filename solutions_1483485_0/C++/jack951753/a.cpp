#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char hash[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char s[500];
void doit()
{
	gets(s);
	for(char *a=s;*a;a++)
		if(*a==' ')
			printf("%c",*a);
		else
			printf("%c",hash[*a-'a']);
	printf("\n");
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d\n",&T);
	for(int i=1;i<=T;i++)
		printf("Case #%d: ",i),doit();
	return 0;
}