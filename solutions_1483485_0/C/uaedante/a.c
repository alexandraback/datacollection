#include <stdio.h>
#include <memory.h>
const char become[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k',
                'r','z','t','n','w','j','p','f','m','a','q'};

int main()
{
	int n, cc;
	char message[1024];
	scanf("%d\n", &n);
	for (cc = 1; cc <= n; cc++) {
		memset(message, 0, sizeof(message));
		gets(message);
		int i;
		for (i = 0; message[i]; i++)
			if (message[i] >= 'a' && message[i] <= 'z')
			message[i] = become[message[i] - 'a'];
		printf("Case #%d: ", cc);
		puts(message);
	}
	return 0;
}
