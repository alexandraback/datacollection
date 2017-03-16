#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

inline int recycle(int num, int mult)
{
	int lastd = num%10;
	num/=10;
	num += mult*lastd;
	return num;
}

int main()
{
	int t, a, b;
	set <int> s;
	cin>>t;
	for(int i = 1; i<=t; i++)
	{
		s.clear();
		cin>>a>>b;
		int ans = 0;
		int mult = 1;
		while(mult <= a)
			mult*= 10;
		mult /= 10;
		for(int cur = a; cur<b;cur++)
		{
			if(s.find(cur) != s.end())
				continue;
			s.insert(cur);
			int num = 1;
			int next = recycle(cur, mult);
			while(next != cur)
			{
				if(next >= a && next <= b)
				{
					assert(next > cur);
					s.insert(next);
					num++;
				}
				next = recycle(next, mult);
			}
			ans += num*(num-1)/2;
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
