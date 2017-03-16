#define mset(a) memset(a,0,sizeof(a))

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
#include <ctime>

using namespace std;
double p[100005];
int main()
{
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		int a,b;
		cin>>a>>b;
		for(int i=1;i<=a;i++)
			cin>>p[i];
		double ans=2+b;
		double temp=1;
		double ans2=0;
		for(int i=1;i<=a;i++)
		{
			temp*=p[i];
			ans2=(temp*(a-i+b-i+1)+(1-temp)*(a-i+b-i+1+b+1));
			ans=min(ans,ans2);
		}
		printf("Case #%d: %.6f\n",tt,ans);

	}
    return 0;
}
