#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getNSteps(int x, int y)
{
	int c = abs(x) + abs(y);	
	long long n = sqrt(2*c) + 1;
	while (n*(n-1) >= 2*c)
		--n;
	while ( (c%2) != (n*(n+1)/2%2) )
		++n;
	return (int)n;
}

int main()
{
	int t;
	cin>>t;
	for (int z = 0, x, y; z < t; ++z)
	{
		cerr<<z<<endl;
		cin>>x>>y;
		int nsteps = getNSteps(x, y);
		string res = "";
		for (int i = nsteps; i >= 1; --i)
		{
			if (abs(x) >= abs(y))
			{
				if (x > 0)
				{
					x -= i;
					res += 'E';
				}
				else
				{
					x += i;
					res += 'W';
				}
			}
			else
			{
				if (y > 0)
				{
					y -= i;
					res += 'N';
				}
				else
				{
					y += i;
					res += 'S';
				}
			}
		}
		reverse(res.begin(), res.end());
		cout<<"Case #"<<(z+1)<<": "<<res<<endl;
	}
	return 0;
}

