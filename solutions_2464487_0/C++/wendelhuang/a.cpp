#include <iostream>
using namespace std;

int T, r, t;

int main()
{
	cin>>T;
	int count = 0;
	while (T--)
	{
		count++;
		cin>>r>>t;
		int i = 1;
		for(; i<1000; i++)
		{
			int temp = 2*i*i + 2*i*r - i;
			if (temp>t)
			{
				break;
			}
		}
		cout<<"Case #"<<count<<": "<<i-1<<endl;
	}
	return 0;
}
