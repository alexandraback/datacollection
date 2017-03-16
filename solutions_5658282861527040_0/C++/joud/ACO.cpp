# include <iostream>
# include <cmath>
# include <algorithm>
# include <queue>
# include <stack>
# include <algorithm>
# include <iomanip>
# include <string>
# include <cstring>
# include <cstdio>
# include <stdio.h>
using namespace std;

string a[100];
int main()
{
	freopen("1B.txt","w",stdout);
	int t;
	cin>>t;
	for (int tt=1;tt<=t;tt++)
	{
		int a,b,k;
		cin>>a>>b>>k;
		int ans=0;
		for (int i=0;i<a;i++)
		{
			for (int j=0;j<b;j++)
			{
				int y=j&i;
				if (y<k)
					ans++;
			}
		}
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
}
