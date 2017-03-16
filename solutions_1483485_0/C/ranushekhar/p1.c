#include <stdio.h>

#define LOOKUP(c) gmap[(c) - 97]
main()
{
	int TC, TC1, inx;
	char instr[101];
	char gmap[26] = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
	scanf("%d",&TC);
	TC1 = TC;
	gets(instr);
	while(TC--) {
		gets(instr);
		printf("Case #%d: ", TC1 - TC);
		for (inx  = 0; instr[inx] != '\0' ; inx++) {
			if (instr[inx] != 32)
				instr[inx] = LOOKUP(instr[inx]);
		}
		printf("%s\n",instr);
	}
}
