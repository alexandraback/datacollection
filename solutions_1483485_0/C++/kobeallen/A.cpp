#include<iostream>
using namespace std;

int main()
{
	freopen("A-small.in","r",stdin);
	freopen("output.txt","w+",stdout);
	int i,len,j;
	int hash[26]={24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};	
	int cas;
	char str[110];
	scanf("%d",&cas);
	getchar();
	for(j=1;j<=cas;j++)
	{
		memset(str,0,sizeof(str));		
		gets(str);		
		len=strlen(str);
		printf("Case #%d: ",j);
		for(i=0;i<len;i++)
		{
			if(str[i]!=' ')
				printf("%c", hash[str[i]-'a']+'a');
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}