#include <iostream>

using namespace std;
int a[10010];
int main() 
{
	freopen("B.in","r",stdin);
	freopen("B.txt","w",stdout);
	int t,m,x,c,d,ans,ret;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> d;
		m=0;
		for(int j=1;j<=d;j++)
		{
			cin >> a[j];
			m=max(m,a[j]);
		}
		ans = m;
		ret = m;
		for(int j=m-1;j>=1;j--)
		{
			c=0;
			for(int aa = 1;aa<=d;aa++)
			{
				x = a[aa];
				c+=(x-1)/j;
			}
			ret = min(j+c,ret);
		}
		cout << "Case #" << i+1 << ": " << ret << endl;
	}
}