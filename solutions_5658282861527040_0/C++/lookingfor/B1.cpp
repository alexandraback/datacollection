#include <iostream>

using namespace std;

int solve(int A, int B, int K)
{
	int res = 0;
	for (int i = 0; i < A; ++i)
		for (int j = 0; j < B; ++j)
			if ((i&j) < K)
				++res;
	return res;
}

int main()
{
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		int A, B, K;
		cin>>A>>B>>K;
		cout<<"Case #"<<i+1<<": "<<solve(A, B, K)<<endl;
	}
	return 0;
}

