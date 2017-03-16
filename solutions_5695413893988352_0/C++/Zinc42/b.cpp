#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;
char s1[4];
char s2[4];
char s3[4];
char s4[4];
int fitness()
{
	return abs(atoi(s1)-atoi(s2));
}
char ss[] = {'0','1','2','3','4','5','6','7','8','9'};
void solve()
{
	char *s[6];
	int num=0;
	for(int i=0;i<strlen(s1);i++)
		if(s1[i]=='?')
		{
			s[num]=&s1[i];
			num++;
		}
	for(int i=0;i<strlen(s2);i++)
		if(s2[i]=='?')
		{
			s[num]=&s2[i];
			num++;
		}
	int *k = new int[num]();
	int min = INT_MAX;

	for(int i=0;i<pow(10,num+1);i++)
	{
		int t=0;
		int temp=i;
		while(temp && t<num)
		{
			*s[t]=ss[temp%10];
			temp/=10;
			t++;
		}
		while(t<num)
		{
			*s[t]=ss[0];
			t++;
		}
		int check = fitness();
		if(check < min)
		{
			min =check;
			strcpy(s3,s1);
			strcpy(s4,s2);

		}
		if(check==min)
		{
			if(atoi(s1)<atoi(s3))
			{
				
			strcpy(s3,s1);
			strcpy(s4,s2);
			}
			else if(atoi(s1)==atoi(s3) && atoi(s2)<atoi(s4))
			{
			strcpy(s3,s1);
			strcpy(s4,s2);
			}
		}
	}

}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		memset(s1,0,4*sizeof(char));
		memset(s2,0,4*sizeof(char));
		memset(s3,0,4*sizeof(char));
		memset(s4,0,4*sizeof(char));
		scanf("%s %s",s1,s2);
		solve();
		printf("Case #%d: %s %s\n",i,s3,s4);
	}
}
