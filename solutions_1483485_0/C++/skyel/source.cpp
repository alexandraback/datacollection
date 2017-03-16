#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i,j,n,len;
	char buff[128],output[128],translate[256];
	FILE *original = fopen("file.in","r");
	FILE *modified = fopen("modified.in","r");
	memset(translate,0,256);
	fscanf (modified,"%d\n",&n);

	for(i = 0; i < n; ++i)
	{
		fgets(buff,128,original);
		fgets(output,128,modified);
		len = strlen(buff);
		for(j = 0; j < len; ++j)
		{
			if(translate[output[j]] == 0)
			{
				translate[output[j]] = buff[j];
			}
		}
	}
	translate['z'] = 'q';
	translate['q'] = 'z';
	scanf("%d\n",&n);
	for(i = 0; i < n; ++i)
	{
		memset(output,0,128 * sizeof(char));
		fgets(buff,128,stdin);
		len = strlen(buff);
		for (j = 0; j < len; ++j)
		{
			output[j] = translate[buff[j]];
		}
		printf("Case #%d: %s",i+1,output);
	}
	return 0;
}
