#include<cstdio>
#include<cstring>
#include<cstdlib>
int main()
{
	int t,i,l,ca=0;
	scanf("%d",&t);
	int AB[26]={25,8,5,19,15,3,22,24,4,21,9,7,12,2,11,18,26,20,14,23,10,16,6,13,1,17};
	while(t--)
	{
		ca++;
		char ch[105]={'\0'};
		getchar();
		scanf("%[^\n]",ch);
		l=strlen(ch);
		for(i=0;i<l;i++)
		{
			if(ch[i]!=' ')
			{
				ch[i]=AB[ch[i]-'a']+'a'-1;
			}
		}
		//printf("Hi\n");
		printf("Case #%d: %s\n",ca,ch);
	}
	return 0;
}