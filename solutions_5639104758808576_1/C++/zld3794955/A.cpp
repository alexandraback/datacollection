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
const int L=1010;
int main()
{	
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T,n;
	char ch[L]={};
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%d%s",&n,ch);
		int ans=0,s=0;
		for(int i=0;i<=n;++i)
		{
			if(s<i)
				++ans,++s;
			s+=ch[i]-'0';
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
