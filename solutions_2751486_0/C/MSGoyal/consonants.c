#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a,b,i,n,count,aa,j,count1;
	long long int sum;
	char arr[1000001];
//	char **bb;
	scanf("%d",&a);
	for(b=1;b<=a;b++)
	{
		sum = 0;
		count=0;
		count1=0;
		scanf("%s %d",arr,&n);
		aa = strlen(arr);
	//	bb = (char**)malloc(sizeof(char*)*aa);
	//	for(i=0;i<aa;i++)
	//	{
	//		bb[i] = (char*)malloc(sizeof(char)*aa);
	//	}
		for(i=0;i<strlen(arr);i++)
		{
			count = 0;
			count1 = 0;
			for(j=i;j<aa;j++)
			{
				if(arr[j]=='a' || arr[j]=='i' || arr[j]=='e' || arr[j]=='o' || arr[j]=='u')
				{
					count=0;
					if(count1==1)
					{
					//	bb[i][j] = 'a';
						sum++;
					}
				}
				else
				{
					count++;
					if(count>=n)
					{
						count1 = 1;
					}
					if(count1==1)
					{
					//	bb[i][j] = 'a';
						sum++;
					}
				}
			}
		}
		printf("Case #%d: %lld\n",b,sum);
	//	free(bb);
	}
	return 0;
}
