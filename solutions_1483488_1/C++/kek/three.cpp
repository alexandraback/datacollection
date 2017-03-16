#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;;

typedef long long int lli;
lli solve(lli a, lli b);
lli recycle(lli n, lli c, lli d);

int main()
{
	std::ifstream f("C-large.in");
	std::ofstream o("result3-2.txt");

	lli size;
	f >> size;
	for(lli i = 0; i < size; i++)
	{
		lli a, b;
		f >> a >> b;
		
		lli result = solve(a,b);
		std::cout << "Case #" << i+1 << ": " << result << std::endl;
		o << "Case #" << i+1 << ": " << result << std::endl;
	}
	return 0;
}
lli solve(lli a, lli b)
{
	stringstream ss;//create a stringstream
	ss << a;	
	lli size = ss.str().size();
	lli cnt = 0;
	lli p[7] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
	for(lli i = a; i <= b; i++)
	{
		vector<lli> already;
		for(lli j = 0; j < size - 1; j++)
		{
 			lli r = recycle(i, p[j], p[size - 2 - j]);
			
			if( i < r && r <= b && find(already.begin(),already.end(),r) == already.end())
			{
				cnt++;
				already.push_back(r);
			}
		}
	}
	return cnt;
}

lli recycle(lli n, lli c, lli d)
{	
	return (n % c) * d + n / c;
}