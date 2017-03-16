#include<iostream>
#include<conio.h>
using namespace std;
char str[101];
int n;
void main()
{
	int T;
	cin>>T;
	int a,b,c,len,con,count,j;
	for(int i=1;i<=T;++i)
	{
		cin>>str>>n;
		count=0;
		len=strlen(str);
		for(c=n;c<=len;++c)
		{
			for(a=0,b=a+c-1;b!=len;++a,++b)
			{
				con=0;
				for(j=a;j<=b;++j)
				{
					switch(str[j])
					{
					case 'a':
					case 'e':
					case 'i':
					case 'o':
					case 'u':con=0;break;
					default:++con;
					}
					if(con>=n)
					{
						++count;
						break;
					}
				}
			}
		}
		cout<<"Case #"<<i<<": "<<count<<endl;
	}
	getch();
}