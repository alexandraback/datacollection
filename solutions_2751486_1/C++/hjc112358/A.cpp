#include <stdio.h>
#include <string.h>

int T,L;
char buf[1000005];
bool good[1000005];
int nextgood[1000005];

int main(int argc, char *argv[])
{
	int i,j,k;
	int nv;
	int len;
	int count;
	scanf("%d\n", &T);
	for (i=0;i<T;i++)
	{
		printf("Case #%d: ", i+1);
		scanf("%s %d\n", buf, &nv);
		len = strlen(buf);
		for (j=0;j<len-nv+1;j++)
		{
			good[j] = true;
			for (k=0;k<nv;k++)
			{
				switch(buf[j+k])
				{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					good[j] = false;
					k = nv;
					break;
				}
			}
		}
		for (j=len-nv+1;j<len;j++)
			good[j] = false;
		nextgood[len-1] = -1;
		for (j=len-2;j>=0;j--)
		{
			nextgood[j] = nextgood[j+1];
			if (good[j+1])
				nextgood[j] = j+1;
		}
		count = 0;
		for (j=0;j<len;j++)
		{
			if (good[j])
			{
				count += len-j-nv+1;
			}
			else
			{
				if (nextgood[j]>0)
				{
					count += len-nextgood[j]-nv+1;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}