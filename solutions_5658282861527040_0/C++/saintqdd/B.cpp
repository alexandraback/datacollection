#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,A,B,K;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		int cnt=0;
		scanf("%d %d %d",&A,&B,&K);
		for(int i=0;i<A;i++)
		{
			for(int j=0;j<B;j++)
			{
				if( (i&j) < K)
				cnt++;
			}
		}
		printf("Case #%d: %d\n",cas,cnt);
	}
	return 0;
}
