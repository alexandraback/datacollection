#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	int ntc;
	cin>>ntc;
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		long long ans=0;
		int a,b,c;
		cin>>a>>b>>c;
		for(int i=0;i<a;i++)
		for(int j=0;j<b;j++ )
		{
			int z=i&j;
			if(z<c) ans++;
		}
		printf("%d\n",ans);
	}
	
}

