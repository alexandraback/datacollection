#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=100+10;
int n,tsts,a[MAXN],x;
int main()
{
	cin >> tsts;
	for (int tt=1;tt<=tsts;tt++)
	{
		cin >> x >> n;
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a,a+n);
		int ans=n;
		for(int i=0;i<n;i++)
		{
			if(ans<=n-i-1)
				continue;
			int cou=n-i-1;
			int s=x;
			for(int j=0;j<=i;j++)
			{
//				cerr << s << " " << cou << " " << a[j] << endl;
				if(s>a[j])
					s+=a[j];
				else
				{
					if(s==1)
					{
						cou=10000;
						continue;
					}
					while(s<=a[j])
					{
						cou++;
						s+=s-1;
					}
					s+=a[j];
				}
			}
//			cerr << i << " " << cou << endl;
			ans=min(ans,cou);
		}
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}
