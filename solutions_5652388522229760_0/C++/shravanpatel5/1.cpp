#include <iostream>
using namespace std;
int digit[10];
int markdigit(int n)
{
	while(n!=0)
	{
		digit[n%10]=1;
		n=n/10;
	}
	int ans=1;
	for(int i=0;i<10;i++)
		if(digit[i]==0)
			ans=0;
	return ans;
}
int main()
{	
	ios_base::sync_with_stdio(false);
	int t,i,n,j;
	cin>>t;
	//t=1000001;
	for(i=0;i<t;i++)
	{
		for(j=0;j<10;j++)
			digit[j]=0;
		cin>>n;
		//n=i;
		if(n==0)
		{
			cout<<"Case #"<<i+1<<": INSOMNIA"<<endl;
			continue;
		}
		for(j=n;;j+=n)
		{
			if(markdigit(j))
			{
				cout<<"Case #"<<i+1<<": "<<j<<endl;
				break;
			}
		}
	}
	return 0;
}