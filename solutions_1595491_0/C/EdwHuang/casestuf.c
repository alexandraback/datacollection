#include <stdio.h>

int main(void)
{
	int cse = 0;
	char buf[256];
	while (fgets(buf, 256, stdin)) printf("Case #%d: %s", ++cse, buf);
	return 0;
}
