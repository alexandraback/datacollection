#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <set>
#include <map>

using namespace std;
int d[101];
int main()
{	
	freopen("A-large.in","r",stdin);
	freopen("2.txt","w",stdout);
	int testcnt;
	cin>>testcnt;
	for (int curtest = 1; curtest<=testcnt;curtest++)
	{
		
		if (curtest==100)
		{
			int olol = 1;
		}
		cout<<"Case #"<<curtest<<": ";
		int a,n;
		cin>>a>>n;
		for (int i=0;i<n;i++)
				cin>>d[i];
		if (a==1)
		{
			cout<<n;
		}
		else
		{	
			
			sort(d,d+n);
			int res = n;
			int cur = a;
			int opcnt=0;
			for (int i=0;i<n;i++)
			{
				if (d[i]>=cur)
				{
					while (d[i]>=cur)
					{
						opcnt++;
						cur+=cur-1;
					}
				}
				cur+=d[i];
				res = min(res,opcnt + (n-i-1)); 
			}
			cout<<res;
		}
		cout<<"\n";
	}
	return 0;
}
