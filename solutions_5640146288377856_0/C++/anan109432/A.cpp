#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int main()
{
	int t,m=1;
	cin>>t;
	while (t--)
	{
		int r,c,w,count = 0;
		cin>>r>>c>>w;

		for (int i=0; i<r-1; i++)
		{
			int j=w;
			while (j<=c)
				count++,j+=w;
		}
		int j=w;
		while (j<c)
			++count,j+=w;
		count+=w;
		cout<<"Case #"<<m++<<": "<<count<<endl;
	}
	return 0;
}