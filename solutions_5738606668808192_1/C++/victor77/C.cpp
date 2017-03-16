#include <iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int N,J;
	cin>>N>>J;

	int number[32];
	number[0]=1;
	number[N-1]=1;
	for(int i=1;i<N-1;i++)
		number[i]=0;
	int count=0;
	long long ans[9];

	cout<<"Case #1:"<<endl;
	while(count<J) 
	{
		for(int i=N-2;i>=1;i--)
		{
			number[i]=number[i]^1;
			if(number[i])
				break;
		}
			

		bool find_all_factor=true;

		for (long long base=2;base<=10;base++)
		{
			bool find_factor=false;
			for(long long factor=3;factor<=10000;factor++)
			{
				long long temp=0;
				for(int i=0;i<N;i++)
				{
					temp=(temp*base+number[i])%factor;
				}
				if (temp==0)
				{
					ans[base-2]=factor;
					find_factor=true;
					break;
				}
			}
			if(!find_factor)
			{
				find_all_factor=false;
				break;
			}	
		}
		if(find_all_factor)
		{
			for(int i=0;i<N;i++)
				cout<<number[i];
			for (long long base=2;base<=10;base++)
				cout<<" "<<ans[base-2];
			cout<<endl;
			count++;
		}
			
	}

	return 0;	
}