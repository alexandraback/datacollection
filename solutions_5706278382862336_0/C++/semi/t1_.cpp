#include <iostream>
#include <cstdio>

using namespace std;

long long that(long long n)
{
	while ((n%2)==0)
	{
		n/=2;
	}
	return n;
}


int main ()
{
	freopen("A-small-attempt3.in","r",stdin);
	freopen("t1.out","w",stdout);
	
	long long p,q,a[100];
	
	
	a[0]=1;
	
	int i;
	
	int t,tt;
	cin >> t;
	char c;
	for (tt=1; tt<=t; tt++)
	{
		cin >> p >> c >> q;
		
		cout << "Case #" << tt << ": ";
		
		if (p%that(q)==0) 
		{
			p/=that(q);
			q/=that(q);
		}
		else 
		{
			cout << "impossible" << endl;
			continue;
		}
		
		int ans=0;
		while (q!=0)
		{
			q/=2;
			ans++;
		}
		while (p!=0)
		{
			p/=2;
			ans--;
		}
		
		
		cout << ans << endl;
		
	} 

	
	return 0;
}
