#include <iostream>
using namespace std;
int main()
{
	int c,t;
	cin>>t;
	int i,n,s,p,a;
	int tp;
	for(c=0;c<t;c++)
	{
		cin>>n>>s>>p;
		a=0;
		for(i=0;i<n;i++)
		{
			cin>>tp;
			if(tp>=3*p && p>=0)
				a++;
			else if(tp>=p*3-2 && p-1>=0 && p<=10)
				a++;
			else if(tp>=p*3-4 && s>0 && p-2>=0 && p<=10)
			{
				a++;s--;
			}
		}
		cout<<"Case #"<<c+1<<": "<<a<<endl;
	}
}
