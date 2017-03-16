#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main()
{
	int t;
	cin >> t;
	//printf("%d tests\n", t);
	for(int i=1;i<=t;i++)
	{
		string a;
		cin >> a;
		int n;
		cin >> n;
		
		//printf("\n\n%s (%d):\n", a.c_str(), n);
		
		set<int> endings;

		int in_row = 0;
		for(unsigned int x=0;x<a.size();x++)
		{
			if(a[x]=='a' || a[x]=='e' || a[x]=='i' || a[x]=='o' || a[x]=='u')
			{
				in_row = 0;
			}
			else
			{
				in_row++;
				if(in_row >= n)
				{
					endings.insert(x);
				}
			}
		}
		long long result = 0;
		for(unsigned int p=0;p<a.size();p++)
		{
			//printf("Position %d: ", p);
			auto it = endings.lower_bound(p+n-1);
			if(it==endings.end()) {}//printf("none\n");
			else
			{
				int add = a.size() - *it;
				result += add;
				//printf("->%d [%d options]\n", *it, add);
			}
		}
		printf("Case #%d: %lld\n", i, result);
	}
	return 0;
}
