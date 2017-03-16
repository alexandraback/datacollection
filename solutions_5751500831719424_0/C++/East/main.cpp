#include<stdio.h>
#include<string.h>

int abs(int n)
{
	return n<0?-n:n;
}

void GetBaseString(char* str, char* base, int freq[])
{
	base[0] = str[0];
	freq[0] = 1;
	int length = 1;
	for(int i=1; str[i]!=NULL; i++)
	{
		if(str[i] == base[length-1])
			freq[length-1]++;
		else
		{
			freq[length] = 1;
			base[length] = str[i];
			++length;
		}
	}
	base[length] = NULL;
}

char str[105][105];
char base[105][105];
int freq[105][105];

int diff(char *str1, char* str2)
{
	GetBaseString(str1, base[0], freq[0]);
	GetBaseString(str2, base[1], freq[1]);
	if(strcmp(base[0], base[1])!=0)
		return -1;
	int length = strlen(base[0]);
	int res = 0;
	for(int i=0;i<length;i++)
		res+=abs(freq[0][i]-freq[1][i]);
	return res;
}

void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T, N;
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%s", str[i]);
		int res = diff(str[0], str[1]);
		if(res==-1)
			printf("Case #%d: Fegla Won\n", cs);
		else
			printf("Case #%d: %d\n", cs, res);
	}
}