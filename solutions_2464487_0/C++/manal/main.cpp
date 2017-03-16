#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	long long n,r,t,x;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int count=0;
		cin>>r>>t;
		while(t-(pow((r+1),2)-pow(r,2))>=0)
		{
			t=t-(pow((r+1),2)-pow(r,2));
			r=r+2;
			count++;
		}
		cout<<"Case #"<<i+1<<": "<<count<<endl;
		
	}
	return 0;
}