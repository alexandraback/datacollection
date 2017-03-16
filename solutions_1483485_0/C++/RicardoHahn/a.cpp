#include <stdio.h>

#define MAX 400

int main()
{
	char map[MAX];
	char G[MAX];
	/*
	 * This values have been found analyzing the statement and the given
	 * exameples
	 */
	for(int i=0; i<256;++i)
		map[i] = i;
	map[97] = 'y';
	map[98] = 'h';
	map[99] = 'e';
	map[100] = 's';
	map[101] = 'o';
	map[102] = 'c';
	map[103] = 'v';
	map[104] = 'x';
	map[105] = 'd';
	map[106] = 'u';
	map[107] = 'i';
	map[108] = 'g';
	map[109] = 'l';
	map[110] = 'b';
	map[111] = 'k';
	map[112] = 'r';
	map[113] = 'z';
	map[114] = 't';
	map[115] = 'n';
	map[116] = 'w';
	map[117] = 'j';
	map[118] = 'p';
	map[119] = 'f';
	map[120] = 'm';
	map[121] = 'a';
	map[122] = 'q';

	int t, tcnt;
	gets(G);
	sscanf(G,"%d",&t);
	for(tcnt=1; tcnt<=t; ++tcnt)
	{
		gets(G);
		printf("Case #%d: ",tcnt);
		for(int i=0; G[i]; ++i)
			printf("%c",map[G[i]]);
		printf("\n");
	}


	return 0;
}
