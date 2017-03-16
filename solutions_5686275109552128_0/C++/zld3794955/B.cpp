#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int V=2020;
int main()
{	
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int testcase=1;testcase<=T;++testcase)
	{
		int n,t[V]={},s[V]={},l=1,r=0,ans=1<<30;
		scanf("%d",&n);
		for(int i=1,x=0;i<=n;++i)
		{
			scanf("%d",&x);
			++t[x];
			r=max(r,x);
		}
		for(int i=1;i<=r+r;++i)
			s[i]=s[i-1]+t[i];
		for(int i=l;i<=r;++i)
		{
			int t2=0;
			for(int j=0,d=0;j<=r;j+=i,++d)
				t2+=(s[j+i]-s[j])*d;
			ans=min(ans,i+t2);
		}
		printf("Case #%d: %d\n",testcase,ans);
	}
	return 0;
}
