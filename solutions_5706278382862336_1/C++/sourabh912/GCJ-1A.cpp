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

using namespace std;

bool check(long long int j)
{
	long long int i=1;
	while(i<=j)
	{
		if(i==j) return true;
		i=i*2;
	}
	
	return false;
}

long long gcd(long long p,long long q)
{
	if(p%q==0) return q;
	else
		return gcd(q,p%q);
}

int main()
{   
	int i,k,cases=0,t,ans;
	long long int j,p,q;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	while(t!=0)
	{
		scanf("%lld/%lld",&p,&q);
		long long g = gcd(p,q);
		p = p/g;
		q = q/g;
		ans = 0;
		j=q;
		q=q/2;
		while(q>p)
		{
			ans++;
			q = q/2;
		}
		cases++;
		if(check(j))
		printf("Case #%d: %d\n",cases,ans+1);
		else
			printf("Case #%d: impossible\n",cases);
		
		t--;
		
	}
	return 0;
}