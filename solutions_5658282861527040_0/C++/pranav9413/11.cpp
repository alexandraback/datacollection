#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int t,a,b,k,ans;
	cin>>t;
	for(int tt=1;tt<=t;tt++)
    {
	 ans=0;
	 cin>>a>>b>>k;
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			if((i&j)<k)
			{
				ans++;
            }
        }
    }
	printf("Case #%d: %d\n",tt,ans);
 }
	return 0;
}
