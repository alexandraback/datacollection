#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int T;
	char buf[1000001];

	scanf("%d\n", &T);
	for (int cnt = 1 ; cnt <= T ; cnt++)
	{
		int ret = 0;
		int last = 0;
		int pre = -1;
		int l,len = 0;
		scanf("%s%d", buf, &l);
		for (int i = 0; buf[i] ; i++)
		{
			if (buf[i] == 'a'
				|| buf[i] == 'e'
				|| buf[i] == 'i'
				|| buf[i] == 'o'
				|| buf[i] == 'u')
			{
				len = 0;
			} 
			else
			{
				len++;
				if (len == l)
				{
					if (pre < 0)
						last = i - l + 2;
					else
						last += i - pre - l + 1;
					pre = i - l + 1;
				}else if (len > l) {
					last++;
					pre = i - l + 1;
				}
			}
			ret += last;
		}

		printf("Case #%d: %d\n", cnt, ret);
	}

	return 0;
}