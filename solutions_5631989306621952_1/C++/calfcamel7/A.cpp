#include <stdio.h>
#include <vector>
#include <string.h>

char str[10050];
char ans[20100];
int headx;
int main()
{
	int _T;
	scanf("%d",&_T);
	for(int CAS = 1; CAS <= _T; CAS++)
	{
		scanf("%s",str);
		int n = strlen(str);
		int l = 10050;
		int r = 10050;
		headx = 65;
		for(int i = 0; i < n; i++)
		{
			int tmp = str[i];
			//headx = str[i];
			//printf("%d %d %d\n", str[i], headx, tmp);
			if(tmp >= headx)
			{
				//puts("????????");
				headx = tmp;
				//printf("headx = %d\n", headx);
				ans[--l] = str[i];
			}
			else
			{
				ans[r++] = str[i];
			}
		}
		printf("Case #%d: ", CAS);
		for(int i = l; i < r; i++)
		{
			putchar(ans[i]);
		}
		puts("");
	}
}