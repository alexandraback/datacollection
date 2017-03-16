#include <iostream>
#include <cassert>
using namespace std;

namespace B
{
	long long E,R,N,T;
	int maximum[1000][10000];
	long long v[10000];
	long long dp(long long st, long long ed, long long begin, long long end)
	{
		if(begin >= E) begin = E;
		if(end < 0) end = 0;
		if(st > ed) return 0;
		if(st == ed)
		{
			assert(begin >= end);
			if(begin >= end)
				return (begin-end) * v[st];
			else
				return 0;
		}
		else
		{
			int findmax = maximum[st][ed];
			long long minvalue = 0;
			if(R * (ed - findmax) < end)
			{
				minvalue = end - R * (ed - findmax);
			}
			long long maxvalue = E;
			if(begin + (findmax - st) < E)
			{
				maxvalue = begin + (findmax - st);
			}
			long long use = maxvalue - minvalue;
			return use * v[findmax] + dp(st,findmax-1,begin,maxvalue-R) + dp(findmax + 1, ed, minvalue + R, end);
		}
	}

	int main()
	{
		cin >> T;
		for(int c=1;c<=T;c++)
		{
			cin >> E >> R >> N;
			for(int i=0;i<N;i++)
				cin >> v[i];
			for(int i=0;i<N;i++)
			{
				maximum[i][i] = i;
			}
			for(int i=0;i<N;i++)
			{
				for(int j=1;i+j<N;j++)
				{
					if(v[maximum[i][i+j-1]] < v[i+j])
						maximum[i][i+j] = i+j;
					else
						maximum[i][i+j] = maximum[i][i+j-1];
				}
			}
			cout << "Case #" << c << ": " << dp(0,N-1,E,0) << endl;
		}
		return 0;
	}
}

int main()
{
	B::main();
}