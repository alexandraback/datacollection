//Dan Johnson
//Google Code Jam
//Qualifying Round 2012
//Problem A
//Speaking in Tongues
#include <stdio.h>
char conversion[255];

//Ideally this would be done statically, but there's no need, and IT's easier to implement this way
void set_up_array(void) {
//auto generated from sample input (see generator.py)
conversion['a'] = 'y';
conversion['c'] = 'e';
conversion['b'] = 'h';
conversion['e'] = 'o';
conversion['d'] = 's';
conversion['g'] = 'v';
conversion['f'] = 'c';
conversion['i'] = 'd';
conversion['h'] = 'x';
conversion['k'] = 'i';
conversion['j'] = 'u';
conversion['m'] = 'l';
conversion['l'] = 'g';
conversion['o'] = 'k';
conversion['n'] = 'b';
conversion['p'] = 'r';
conversion['s'] = 'n';
conversion['r'] = 't';
conversion['u'] = 'j';
conversion['t'] = 'w';
conversion['w'] = 'f';
conversion['v'] = 'p';
conversion['y'] = 'a';
conversion['x'] = 'm';

//manually fill in missing values based on hint
conversion['z'] = 'q';
conversion['q'] = 'z';
conversion[' '] = ' ';
}


#define BUF_SIZE 256
int main() {
	set_up_array();
	int n;
	scanf("%d\n", &n);
	int i;
	char buffer[BUF_SIZE]; //bigger than 100 characters
	for(i = 0; i < n; ++i) {
		fgets(buffer, BUF_SIZE, stdin);
		buffer[BUF_SIZE - 1] = '\0'; //just in case...
		char* tmp_buf = buffer;
		printf("Case #%d: ", i + 1);
		while (*tmp_buf && *tmp_buf != '\n') {
			printf("%c", conversion[*tmp_buf]);
			++tmp_buf;
		}
		printf("\n");
	}
}
