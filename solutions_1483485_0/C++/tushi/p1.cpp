#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
int t,i,k;
char str[101], mapp[27]="yhesocvxduiglbkrztnwjpfmaq", ch;


fflush(stdin);

scanf("%d", &t);

scanf("%c",&ch);


for(k=1;k<=t;k++)
{
	cout<<"Case #"<<k<<": ";
	gets(str);
	for(i=0;str[i];i++)
	{
		if(str[i]>='a' && str[i]<='z')
		cout<<mapp[str[i]-'a'];
		else
		cout<<str[i];
	}
	cout<<'\n';
}

return(0);
}
