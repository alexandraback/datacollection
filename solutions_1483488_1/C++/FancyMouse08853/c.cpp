#include<iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		int A, B;
		cin>>A>>B;
		int result = 0;
		int digits = 0;
		for(int t=1;t<=A;digits++,t*=10);
		int highest = 1;
		for(int i=1;i<digits;i++)
			highest *= 10;
		int store[9];
		for(int i=A;i<=B;i++)
		{
			int t = i;
			int cur = 0;
			for(int j=1;j<digits;j++)
			{
				int l = t % 10;
				t = (t/10) + (l*highest);
				if(t > i && t <= B)
				{
					int k = 0;
					for(k=0;k<cur;k++)
						if(store[k] == t)
							break;
					if(k == cur)
					{
						result++;
						store[cur++] = t;
					}
				}
			}
		}
		cout<<"Case #"<<_<<": "<<result<<endl;
	}
	return 0;
}
