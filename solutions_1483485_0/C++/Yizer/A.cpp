#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const char cheat[26]= {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w',
'j','p','f','m','a','q'};

int main()
{
	int nCase;
	char buffer[1024];
	scanf("%d",&nCase);
	getchar();
	for (int nc=0;nc<nCase;nc++) {
		gets(buffer);
		int len = strlen(buffer);
		for (int i=0;i<len;i++) 
			if (buffer[i] != ' ') {
			buffer[i] = cheat[buffer[i]-'a'];	
		}
		printf("Case #%d: %s\n",nc+1,buffer);
	}
    return	0;
}
