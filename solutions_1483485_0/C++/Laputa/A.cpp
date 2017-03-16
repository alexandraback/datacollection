#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	char map[]="yhesocvxduiglbkrztnwjpfmaq";
	char ipt[120];
	int T,len,TT;
	scanf("%d%c",&T,&ipt[0]);
	TT=T;
	while(T--)
	{
		gets(ipt);
		len=strlen(ipt);
		printf("Case #%d: ",TT-T);
		for(int i=0;i<len;i++)
		{
			if(ipt[i]<='z'&&ipt[i]>='a')
				ipt[i]=map[ipt[i]-'a'];
		}
		printf("%s\n",ipt);
	}
	return 0;
}