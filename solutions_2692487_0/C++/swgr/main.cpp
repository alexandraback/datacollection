#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

long long A;
int n;
int d[1000000];

int main()
{
	freopen("A-small-attempt0.in", "r",stdin);
	freopen("A-small-attempt0.out", "w",stdout);
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		cin>>A>>n;
		int ans = n;
		for(int i=0;i<n;i++)
			cin>>d[i];
		if (A>1)
		{
			sort(d,d+n);
			int k = 0, i = 0;
			while(i<n)
			{
				while(i<n&&d[i]<A)
				{
					A+=d[i];
					++i;
				}
				ans = min(ans, k+(n-i));
				if (i==n) break;
				A += A-1;
				k++;
			}
		}
		cout<< "Case #" << tt << ": " << ans << endl;
	}

	return 0;
}
