#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;

char s[1000];
int h[2000001];

int main()
{
	int t,no=0;
	scanf("%d",&t);
	while(t--)
	{
		memset(h,0,sizeof(h));
		int a,b,cnt=0;
		scanf("%d%d",&a,&b);
		for(int i=a;i<=b;i++)
		{
			sprintf(s,"%d%d",i,i);
			int len=strlen(s);
			for(int j=0;j<len/2;j++)
			{
				int num=0;
				for(int k=0;k<len/2;k++)
					num=num*10+(s[j+k]-'0');
				if(num>i&&num<=b&&h[num]!=i)
					h[num]=i,cnt++;
			}
		}
		printf("Case #%d: %d\n",++no,cnt);
	}
	return 0;
}