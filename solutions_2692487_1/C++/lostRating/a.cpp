#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>

using namespace std;

int a[1000005];

int main()
{
	#ifdef LOCAL_TEST
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	int task;
	cin>>task;
	for (int tt=1;tt<=task;++tt)
	{
		cout<<"Case #"<<tt<<": ";
		int m,n;
		cin>>m>>n;
		for (int i=0;i<n;++i) cin>>a[i];
		sort(a,a+n);
		int ans=n;
		if (m!=1)
			for (int i=0,j=0;i<n;++i)
			{
				while (m<=a[i])
				{
					++j;
					m+=m-1;
				}
				m+=a[i];
				if (n-i-1+j<ans) ans=n-i-1+j;
			}
		cout<<ans<<endl;
	}
	return 0;
}
