#include <cstdio>
#include <cstring>

char mapping[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i',
	'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main() {
	int ntests;
	char line[200];
	
	scanf("%d\n", &ntests);
	for (int i = 1; i <= ntests; i++) {
		gets(line);
		printf("Case #%d: ", i);
		for (int j = 0; line[j]; j++) {
			if (line[j] == ' ') putchar(' ');
			else putchar(mapping[line[j] - 'a']);
		}
		printf("\n");
	}
	return 0;
}