#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long ll;

ll r,t;
 int main()
{
	//freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
	//freopen("A.in","r",stdin);freopen("A.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int testcase;
	ll ans=0;
	
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		scanf("%I64d%I64d", &r,&t);
		printf("Case #%d: ",case_id);
		
		ll low=0,high=1000000000;
		ans=0;
		ll x=0;
		while(1)
		{
			ll mid=(low+high)/2;
			unsigned long long need=(2*r-3)*mid+2*mid*(mid+1);
			if(need<t)
			{
				low=mid;
				if(((2*r-3)*(mid+1)+2*(mid+2)*(mid+1))>t)
				{
					ans=mid;
					break;
				}
			}
			else if(need>t)
			{
				high=mid;
			}
			else
			{
				ans=mid;
				break;
			}
		}
		printf("%I64d",ans);
		printf("\n");
	}
	return 0;
}

