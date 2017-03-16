#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<climits>
#include<cassert>
#include<time.h>
using namespace std;

#define f(i,a,b) for(i=a;i<b;i++)

int main()
{
	int k = 0, i, ans, t, n, count;
	string s;
	cin>>t;
	
	while(t--)
	{
		k++;
		cin>>n;
		cin>>s;
		
		count = s[0] - '0';
		ans = 0;
		
		for(i=1;i<=n;i++)
		{
			if(s[i] != '0')
			{
				if(count < i)
				{
					ans = ans + i - count;
					count = i;
				}
				
				count = count + (s[i] - '0');
			}
		}
		
		cout<<"Case #"<<k<<": "<<ans<<"\n";
	}
}
