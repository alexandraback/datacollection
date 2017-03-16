#include <stdio.h>
#include <string.h>
char trans[27] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 
	'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j',
   	'p', 'f', 'm', 'a', 'q'};
int main()
{
	int i,j,t;
	char g[102];
	scanf("%d\n", &t);
	for(i = 1; i <= t; i++) {
		scanf("%[^\n]%*c", g);
		//printf("%s", g);
		for(j = 0; j < strlen(g); j++) {
			if(g[j] != ' ') g[j] = trans[g[j] - 'a'];
		}
		printf("Case #%d: %s\n",i , g);
	}
	return 0;
}
