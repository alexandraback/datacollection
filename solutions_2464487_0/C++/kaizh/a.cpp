#include <iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		long long r,t;
		cin>>r>>t;
		long long cur=r+1;
		long long cnt=0;
		for(;(cur*cur-(cur-1)*(cur-1))<=t;cur+=2)
		{
			cnt++;
			t-=cur*cur-(cur-1)*(cur-1);
		}
		cout<<"Case #"<<tt<<": "<<cnt<<endl;
	}
	return 0;
}
