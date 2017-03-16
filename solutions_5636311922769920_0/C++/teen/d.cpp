#include <bits\stdc++.h>
using namespace std;
int main()
{
	freopen("d.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i= 1; i <= t;i++)
	{
		int k,c,s;
		cin>>k>>c>>s;
		printf("Case #%d:",i);
		for(int j = 1; j <= k; j++)
			cout<<" "<<j;
		cout<<endl;
	}
	return 0;
}