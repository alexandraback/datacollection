#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int main()
{
	int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		int r,c,w;
		scanf("%d %d %d",&r,&c,&w);
		int ans=0;
		while(r>0)
		{
			ans += c/w;
			r--;
		}
		
		if(c%w==0)
		{
			ans--;
		}
		ans+=w;
		printf("%d\n",ans);
		
	}
}
