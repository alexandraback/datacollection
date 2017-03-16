#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ep(...) fprintf(stderr, __VA_ARGS__)
int main(int argc, char **argv) {
	int cases = 0;
	const char *map = "eojupr  mlyasnlgcekidsxmvpnbrtidbhtwayhxwffcokujgvzqqz";
	int maplen = strlen(map);
	char buf[110];
	scanf("%d\n", &cases);
	
	/*
	char bits[256];
	memset(&bits, 0, 256);
	
	while(cases--) {
		char bufgood[110];
		gets(&buf[0]);
		gets(&bufgood[0]);
		ep("Str: %s\n", &buf[0]);
		ep("Str: %s\n", &bufgood[0]);
		for(int i = 0; i < strlen(&buf[0]); ++i) {
			char src = buf[i];
			char tar = bufgood[i];
			if(bits[(int)src] == (char)0) {
				printf("%c%c", src, tar);
				bits[(int)src] = (char)1;
			}
		}
	}
	*/
	for(int cas = 0; cas < cases; ++cas) {
		gets(&buf[0]);
		int len = strlen(&buf[0]);
		for(int i = 0; i < len; ++i) {
			for(int j = 0; j < maplen; j += 2) {
				if(map[j] == buf[i]) {
					buf[i] = map[j + 1];
					break;
				}
			}
		}
		printf("Case #%d: %s\n", cas + 1, buf);
	}

	exit(0);
}