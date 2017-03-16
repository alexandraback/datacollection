#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("A-small-attempt2.in","r",stdin);
	freopen("A-small-attempt2.out","w",stdout);
	int T,cas=0,l,i;
	char str[1010],str1[1010],str2[1010];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",&str);
		l=strlen(str);
		str1[0]=str[0];
		str1[1]=0;
		for(i=1;i<l;++i)
		{
			memcpy(str2+1,str1,sizeof(char)*i);
			str1[i]=str2[0]=str[i];
			str1[i+1]=str2[i+1]=0;
			if(strcmp(str2,str1)>0)
			{
				memcpy(str1,str2,sizeof(char)*(i+2));
			}
		}
		printf("Case #%d: %s\n",++cas,str1);
	}
	return 0;
}
/*
7
CAB
JAM
CODE
ABAAB
CABCBBABC
ABCABCABC
ZXCASDQWE
*/

