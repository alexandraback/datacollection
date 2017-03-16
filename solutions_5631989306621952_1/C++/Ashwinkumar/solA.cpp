#include"header.h"

int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int str[2001];
		fflush(stdin);
		int c=getc(stdin);
		str[999]=c;
		int i=999,j=999;
		while((c=getc(stdin))!='\n')
		{
			if(str[i]>c)
			{
				j++;
				str[j]=c;
			}
			else
			{
				i--;
				str[i]=c;
			}
		}
		cout<<"Case #"<<t<<": ";
		for(;i<=j;i++)
		{
			if(str[i]!='\n')
			{
				putc(str[i],stdout);
			}
		}
		cout<<endl;
	}
	return 0;
}