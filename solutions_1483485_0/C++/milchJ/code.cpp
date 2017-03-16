#include <cstdio>


char translate[30] = {
'y', //a
'h',	//b
'e',	//c
's',	//d
'o', // e
'c',	// f
'v',	//g
'x',	//h
'd',	//i
'u',	//j
'i',	//k
'g',	//l
'l',	//m
'b',	//n
'k',	//o
'r',	//p
'z',	//q
't',	//r
'n',	//s
'w',	//t
'j',	//u
'p',	//v
'f',	//w
'm',	//x
'a', // y
'q' // z
};

int main() {

	char buf[200];
	char word[200];
 	char c;
	int N;
	scanf("%d ", &N);
	for(int i=0; i<N; i++) {
		printf("Case #%d: ", i+1);
		while(scanf("%c", &c) && c!='\n') {
			if(c==' ') printf(" ");
			else printf("%c", translate[c-'a']);
		}
		printf("\n");
		/*gets(buf);
		while(sscanf(buf, "%s", &word)) {
			while
		}*/
	}


	return 0;
};
