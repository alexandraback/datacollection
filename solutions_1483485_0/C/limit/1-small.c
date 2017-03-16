#include<stdio.h>
#include<string.h>

char inp[101];
char output[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

void convert()
{
  int i,max;
  max=strlen(inp);
  for(i=0;i<max;i++)
  {
     if(inp[i]==' ')
     	printf(" ");
     else
        printf("%c",output[(inp[i]-'a')]);
  }
  printf("\n");
  return;
}

int main()
{
	int test,i;
	char useless;
	scanf("%d",&test);
	scanf("%c",&useless);
	for(i=1;i<=test;i++)
	{
		gets(inp);
		printf("Case #%d: ",i);
		convert();
	}
	return 0;
}
