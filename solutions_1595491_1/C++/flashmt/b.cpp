#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	freopen("blarge.in","r",stdin);
	freopen("blarge.out","w",stdout);
	int test;
	cin >> test;
	for (int it=1;it<=test;it++)
	{
		int n,surprise,least,total[111],ans=0;
		cin >> n >> surprise >> least;
		for (int i=0;i<n;i++) cin >> total[i];
		sort(total,total+n);
		for (int i=n-1;i>=0;i--)
			if (total[i]>=least*3-2) ans++;
			else
				if (surprise && total[i]>=least && total[i]>=least*3-4)
					ans++, surprise--;
		cout << "Case #" << it << ": " << ans << endl;
	}
}
