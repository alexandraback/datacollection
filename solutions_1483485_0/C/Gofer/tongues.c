#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char table[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

void make_table() {
	unsigned int T, i, j;
	char ans[100];
	char str[100];
	
	FILE *fp = fopen("input.txt","r");
	FILE* fpA = fopen("ans.txt", "r");
	
	fscanf(fp, "%d\r\n", &T);
	for(i=0; i<T; ++i) {
		for(j=0; 1; ++j) {
			fscanf(fp, "%c", &str[j]);
			if(str[j] == '\n') break;
		}
		str[j] = '\0';
		
		for(j=0; 1; ++j) {
			fscanf(fpA, "%c", &ans[j]);
			if(ans[j] == '\n') break;
		}
		ans[j] = '\0';
		
		for(j=0; str[j] != '\0'; ++j) {
			table[(str[j] - 'a')] = ans[j];
		}
		printf("%s\n%s\n", str, ans);
	}
	
	fclose(fp);
	fclose(fpA);
	
	for(i=0; i<26; ++i) {
		printf("%c -> %c\t", i+'a', table[i]);
		//printf("\'%c\', ", table[i]);
		if((i+1) % 7 == 0) putchar('\n');
	}
}

void translate(char* buf, const char* str) {
	unsigned int i;
	
	for(i=0; str[i] != '\0'; ++i) {
		if(str[i] == ' ') buf[i] = ' ';
		else buf[i] = table[(str[i] - 'a')];
	}
	buf[i] = '\0';
}

int main(int argc, char** argv) {
	unsigned int T, i, j;
	char str[1000], buf[1000];
	
	//FILE *fp = fopen("input.txt","r");
	FILE *fp = fopen("A-small-attempt0.in","r");
	fscanf(fp, "%d\r\n", &T);
	for(i=0; i<T; ++i) {
		for(j=0; 1; ++j) {
			fscanf(fp, "%c", &str[j]);
			if(str[j] == '\n') break;
		}
		str[j] = '\0';
		translate(buf, str);
		printf("Case #%d: %s\n", i+1, buf);
	}
	fclose(fp);
	
	return EXIT_SUCCESS;
}
