#include"header.h"

int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int N,temp,list[2501]={0};
		cin>>N;
		for(int i=0;i<((2*N*N)-N);i++)
		{
			cin>>temp;
			list[temp] += 1;
		}
		cout<<"Case #"<<t<<":";
		for(int i=1;i<2501;i++)
		{
			if((list[i]%2)!=0)
			{
				cout<<" "<<i;
			}
		}
		cout<<endl;
	}
	return 0;
}