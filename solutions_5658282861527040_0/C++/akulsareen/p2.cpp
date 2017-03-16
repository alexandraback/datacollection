#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
int main()
{
	freopen("bs.in","r",stdin);
	freopen("b_small.out","w",stdout);
	int t;
	cin>>t;
	for (int test_case = 1; test_case <= t; ++test_case)
	{
		int a,b,k,ans=0;
		cin>>a>>b>>k;
		for (int i = 0; i < a; ++i)
		{
			for (int j = 0; j < b; ++j)
			{
				if((i&j) < k)
				{
					//cout<<i<<" "<<j<<" "<<(i&j)<<"\n";
					ans++;
				}
			}
		}
		cout<<"Case #"<<test_case<<": "<<ans<<"\n";
	}
	return 0;
}