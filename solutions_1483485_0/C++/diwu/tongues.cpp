#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define size 200

char buf[size];

int main() 
{ 

#ifdef FILEIO
	freopen("in.txt","r",stdin); 
	freopen("out.txt","w",stdout); 
#endif

	int l[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

	int T;
	char temp;
	scanf("%d",&T);
	scanf("%c",&temp);
	int num = 1;

	while(T-- > 0)
	{
		memset(buf,0,size);
		printf("Case #%d: ",num++);
		scanf("%[^\n]\n",buf);
		int i = 0;
		while(buf[i] != '\0')
		{
			if((buf[i] - 'a' >= 0)&&(buf[i] - 'z' <= 0))
			{
				printf("%c",l[buf[i] - 'a']);
			}
			else
				printf("%c",buf[i]);
			//printf("%c",buf[i]);
			i++;
		}
		printf("\n");
	}

#ifdef FILEIO
	fclose(stdin);
	fclose(stdout);
#endif  

	return 0; 
}
