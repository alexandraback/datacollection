#include <stdio.h>
#include <strings.h>
#include <string.h>

char abc[256];

int main(){
	
	abc[121] = 'a';
	abc[110] = 'b';
	abc[102] = 'c';
	abc[105] = 'd';
	abc[99]  = 'e';
	abc[119] = 'f';
	abc[108] = 'g';
	abc[98]  = 'h';
	abc[107] = 'i';
	abc[117] = 'j';
	abc[111] = 'k';
	abc[109] = 'l';
	abc[120] = 'm';
	abc[115] = 'n';
	abc[101] = 'o';
	abc[118] = 'p';
	abc[122] = 'q';
	abc[112] = 'r';
	abc[100] = 's';
	abc[114] = 't';
	abc[106] = 'u';
	abc[103] = 'v';
	abc[116] = 'w';
	abc[104] = 'x';
	abc[97]  = 'y';
	abc[113] = 'z';
	abc[32] = ' ';

	int ndc;
	int caso;
	scanf("%d\n",&ndc);
	
	for(caso=0; caso<ndc; caso++){
		
		char frase[256];
		char c;
		bzero(frase,256);

		int i=0;
		for (i=0; ;i++){
			scanf("%c",&c);
			if (c < 97 || c > 122) {
				if (c != ' ') break;
			}
			frase[i] = c;
		}
		
		for (i=0; i<strlen(frase); i++){
			frase[i] = abc[frase[i]];
		}
				
		// imprimir resultado
		printf("Case #%d: %s\n",caso+1,frase);
	}
	return 0;
}
