#include<iostream>
using namespace std;

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,n,s,p,cnt;
	int ts;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		cin>>n>>s>>p;
		cnt=0;
		for(int i=0;i<n;i++)
		{
			cin>>ts;
			if(ts>=p && ts>=3*p-2)
				cnt++;
			else if(ts>=p && ts>=3*p-4 && s>0)
			{
				s--;
				cnt++;
			}
		}
		cout<<"Case #"<<c<<": "<<cnt<<endl;
	}
}