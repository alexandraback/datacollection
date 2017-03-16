#include <cstdio>
#include <cstring>

using namespace std;

char a0[] = "a zoo ejp mysljylc kd kxveddknmc re jsicpdrysi";
char a1[] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
char a2[] = "de kr kd eoya kw aej tysr re ujdr lkgc jvq";

char b0[] = "y qee our language is impossible to understand";
char b1[] = "there are twenty six factorial possibilities";
char b2[] = "so it is okay if you want to just give upz";

int map[256];

int main() {
	for (int i = 0; i < 256; i++) map[i] = -1;
	for (int i = 0; i < strlen(a0); i++) map[a0[i]] = b0[i];
	for (int i = 0; i < strlen(a1); i++) map[a1[i]] = b1[i];
	for (int i = 0; i < strlen(a2); i++) map[a2[i]] = b2[i];
	
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++) {
	printf("Case #%d: ", i);
	char buff[100000];
	gets(buff);
	for (int i = 0; i < strlen(buff); i++) {
		printf("%c", map[buff[i]]);
	}
	printf("\n");
	}
}