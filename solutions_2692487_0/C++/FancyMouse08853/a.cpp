#include<iostream>
#include<algorithm>
using namespace std;

const int Max = 100;
int d[Max];
int main()
{
	int T;
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		int A, N;
		cin>>A>>N;
		for(int i=0;i<N;i++)
			cin>>d[i];
		sort(d,d+N);
		int result = 0x7fffffff;
		int cur = 0;
		for(int i=0;i<N;i++)
		{
			if(cur+(N-i) < result)
				result = cur+N-i;
			if(A == 1)
			{
				cur = 0x7fffffff;
				break;
			}
			while(A <= d[i])
			{
				cur++;
				A += A-1;
			}
			A += d[i];
		}
		if(cur < result)
			result = cur;
		cout<<"Case #"<<_<<": "<<result<<endl;
	}
	return 0;
}
