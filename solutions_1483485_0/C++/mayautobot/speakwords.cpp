#include<stdio.h>
#include<string.h>
int main()
{
	char arr[200];
	int test,j,i;
	char prr[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	scanf("%d",&test);
	gets(arr);
	for(j=0;j<test;j++)
	{
		gets(arr);
		//printf("\n%d",strlen(arr));
		for(i=0;i<strlen(arr);i++)
		{
			if(arr[i]>=97 && arr[i]<=122)
			{
				arr[i]=prr[arr[i]-97];
			}
		}
		printf("Case #%d: %s\n",j+1,arr);
	}
	return 0;
}
