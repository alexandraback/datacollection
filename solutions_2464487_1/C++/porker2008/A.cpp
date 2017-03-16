#include <iostream>
#include <cmath>
using namespace std;

namespace A
{
	int main()
	{
		long long r,t;
		int T;
		cin >> T;
		for(int c=1;c<=T;c++)
		{
			cin >> r >> t;
			double rr = r;
			double tt = t;
			cout << "Case #" << c << ": ";
			long long result = (sqrt(pow(2*rr-1,2.0) + (8*tt)) - (2*rr-1))/4;
			//cout << result << endl;
			result--;
			do
			{
				long long temp = result+1;
				long long test = temp*(2*r+2*temp-1);
				if(test <= t)
					result = temp;
				else break;
			}while(true);
			do
			{
				long long temp = result-1;
				long long test = temp*(2*r+2*temp-1);
				if(test > t)
					result = temp;
				else break;
			}while(true);
			cout << result << endl;
		}
		return 0;
	}
}

int main()
{
	A::main();
}