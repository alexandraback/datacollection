#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>
#include <set>
using namespace std;

long long int MIN (long long int a, long long int b)
{
	if (a<b) return a;
	return b;
}
long long int res(long long int r, long long int t)
{
	long long int i,n,left=0, right=MIN(1000000000,t/(2*r-1ll)+1),c;
	while (right-left>1)
	{
		c=(left+right)/2;
		if (2ll*c*c + c*(2*r-1ll) > t) right=c;
		else left=c;
	}
	return left;
}

int main()
{
    freopen("A-large.in", "r", stdin); freopen("output.txt", "w", stdout);
	int i,n;
	long long int r,t;
	cin>>n;
	for (i=0; i<n; i++)
	{
		cin>>r>>t;
		cout<<"Case #"<<i+1<<": "<<res(r,t)<<endl;
	}
    return 0;
}