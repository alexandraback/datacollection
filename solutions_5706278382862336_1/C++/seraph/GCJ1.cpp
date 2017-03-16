#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <stdio.h>

using namespace std;

int main()
{
	int tc;
	int count=1;
	cin>>tc;
	while (tc--)
	{
		long long a,b;
		scanf("%lld/%lld", &a, &b);
		int tot = 1;
		/*while (true)
		{
			if (b%2==1) a*=2;
			else b/=2;
			if (a>=b) 
			{
				break;
			}
			ans++;
			tot++;
		}
		
		a = b-a;*/
		int ada = 1;
		int pernah = 0;
		int ans = 1;
		//cout<<a<<" "<<b<<endl;
		while (true)
		{
			if (b%2==1) a*=2;
			else b/=2;
			if (a>=b) 
			{
				if (pernah == 0) {
					pernah=1;
					ans = tot;
				}
				if (b-a==0) break;
				a = a-b;
			}
			//cout<<a<<" "<<b<<endl;
			//system("pause");
			tot++;
			if (tot> 40) {
				ada = 0;
				break;
			}
		}
		if (ada == 1)
			cout<<"Case #"<<count++<<": "<<ans<<endl;
		else
			cout<<"Case #"<<count++<<": "<<"impossible"<<endl;
	}
	return 0;
}

