#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t;
	int cases=1;
	cin>>t;
	while(t--)
	{
		int p=0,q=0;
		char s[30];
		cin>>s;
		int i=0;
		for(i=0;s[i]!='/';i++)
		{
			p=p*10+(s[i]-'0');
		}
		i++;
		for(i;i<strlen(s);i++)
		{
			q=q*10+(s[i]-'0');
		}
		int tq=q;
		int ans=0;
		int flag=0;
		while(tq!=1)
		{
			if(tq%2!=0&&tq!=1)
			{
				flag=1;
				break;
			}
			tq=tq/2;
		}
		if(flag==1||p>q)
		{
			cout<<"Case #"<<cases<<": "<<"impossible"<<endl;
			cases++;
			continue;
		}
		while(p<q)
		{
			q=q/2;
			ans++;
		}
		cout<<"Case #"<<cases<<": "<<ans<<endl;
		cases++;
	}
}
