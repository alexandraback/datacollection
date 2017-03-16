#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int n;
		vector<int> p;
		scanf("%d",&n);
		for (int q=0;q<n;++q)
		{
			int t;
			scanf("%d",&t);
			p.push_back(t);
		}
		int ret = 987654321;
		for (int tar=1;tar<=1000;tar++)
		{
			int divTime = 0;
			for (int e : p) divTime += (e+tar-1)/tar - 1;
			//printf("tar=%d divTime=%d\n",tar,divTime);
			ret = min(ret, divTime + tar);
		}
		printf("Case #%d: %d\n",kase,ret);
	}
	return 0;
}