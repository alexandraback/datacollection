#include<iostream>
#include<cstring>
#define N 1000001
using namespace std;
int main()
{	int t,i,nval,k,j,count,len,n;
	char str[N];
	cin>>t;
	for(i=1;i<=t;i++)
	{	cin>>str>>n;
		len=strlen(str);
		nval=0;
		for(j=0;j<=len-n;j++)
		{	count=0;
			for(k=j;k<len&&count<n;k++)
			{	if(str[k]!='a' && str[k]!='e' && str[k]!='i' && str[k]!='o' && str[k]!='u')
					count++;
				else
					count=0;
			}
			if(count==n)
				nval+=(len-k+1);
		}
		cout<<"Case #"<<i<<": "<<nval<<endl;
	}
	return 0;
}