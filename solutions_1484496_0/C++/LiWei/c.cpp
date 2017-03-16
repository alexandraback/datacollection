#include <iostream>
using namespace std;
int s[22];
int r[22];
int n;
bool search(int a,int b,int i)
{
	if(a==b && a!=0) return true;
	if(i==n) return false;
	r[i]=0;
	if(search(a,b,i+1))
		return true;
	r[i]=1;
	if(search(a+s[i],b,i+1))
		return true;
	r[i]=2;
	if(search(a,b+s[i],i+1))
		return true;
	r[i]=0;
	return false;
}
int main()
{
	int c,t,i;

	cin>>t;
	int a[22],b[22],ta,tb;
	for(c=0;c<t;c++)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>s[i];
		}
		cout<<"Case #"<<c+1<<":\n";
		if(search(0,0,0))
		{
			ta=tb=0;
			for(i=0;i<n;i++)
				if(r[i]==1) a[ta++]=s[i];
			else if(r[i]==2) b[tb++]=s[i];
			cout<<a[0];
			for(i=1;i<ta;i++)
				cout<<' '<<a[i];
			cout<<endl<<b[0];
			for(i=1;i<tb;i++)
				cout<<' '<<b[i];
			cout<<endl;
		}else cout<<"Impossible";
	}
}
