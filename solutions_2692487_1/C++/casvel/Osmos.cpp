#include <iostream>
#include <algorithm>
#define For(i, a, b) for(int i=a; i<b; ++i)
using namespace std;

int main()
{
	int T;
	cin>>T;
	For(casos, 1, T+1)
	{
		int A, N, ops = 0, best = -1;
		int motes[105];
		cin>>A>>N;
		For(i, 0, N)
			cin>>motes[i];

		sort(motes, motes+N);

		For(i, 0, N)
		{
			//cout<<ops<<endl;
			if (motes[i] < A) A += motes[i];
			else
			{
				if (ops + N-i < best or best == -1)
					best = ops + N-i;
				if (A == 1)
				{
					ops = best;
					break;
				}
				while (motes[i] >= A)
				{
					ops++;
					A += A-1;
				}
				A += motes[i];
			}
		}

		if (ops < best or best == -1) best = ops;
		cout<<"Case #"<<casos<<": "<<best<<endl;
	}
	return 0;
}