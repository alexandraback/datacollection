#include <iostream>
#include<cstring>
using namespace std;
int main()
{	
	ios_base::sync_with_stdio(false);
	long long int t,i,n,j,ans,len;
	char str[110],pre;
	cin>>t;
	for(i=0;i<t;i++)
	{
		ans=0;
		cin>>str;
		n=strlen(str);
		pre=str[0];
		len=1;
		for(j=1;j<n;j++)
		{
			if(str[j]!=pre)
			{
				len++;
			}
			pre=str[j];
		}
		if(str[0]=='-')
		{
			len--;
			ans=1;
		}
		if(len%2==1)
			len--;
		ans+=len;
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}