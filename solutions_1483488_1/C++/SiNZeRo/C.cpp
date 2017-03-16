#include<iostream>
#include<algorithm>
#include<functional>
#include <vector>
#include <string>
#include <cmath>
#include <hash_map>
#include <hash_set>
using namespace std;
int cn;
int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	cin>>cn;
	for(int cs=1;cs<=cn;cs++)
	{
		string sA,sB;
		int A,B,lA,ans=0;
		cin>>sA>>sB;
		lA=sA.length();
		sscanf(sA.c_str(),"%d",&A);
		sscanf(sB.c_str(),"%d",&B);

		int pow10 = static_cast<int>(pow(10.0, lA - 1));

		for (int n = A; n < B;++n )
		{
			hash_set<int> used;
			int m = n;
			for (int i = 0; i < lA - 1; ++i)
			{
				m = m / 10 + (m % 10) * pow10;
				if (n < m && m <= B && used.count(m)==0)
				{
					used.insert(m);
					ans++;
				}
			}
		}
		printf("Case #%d: %d\n",cs,ans);
	}
	return 0;
}
