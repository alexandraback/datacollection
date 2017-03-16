#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int MAX = 2000000;
vector<int> p[MAX];
void Init()
{
	for (int n=1;n<MAX;n++)
	{
		int w=0,nn=n,t=1;
		while (nn)
		{
			w++;
			nn/=10;
			t*=10;
		}
		nn=n;
		for (int i=1;i<w;i++)
		{
			nn=(nn+t*(nn%10))/10;
			if (n<nn && nn<=MAX) p[n].push_back(nn);
		}
		sort(p[n].begin(),p[n].end());
		p[n].erase(unique(p[n].begin(),p[n].end()),p[n].end());
	}
}
int main()
{
	Init();
	int cases;
	scanf("%d",&cases);
	for (int tcase=1;tcase<=cases;tcase++)
	{		
		int a,b;
		scanf("%d%d",&a,&b);
		printf("Case #%d: ",tcase);		
		int ans=0;
		for (int n=a;n<b;n++)
			for (int i=0;i<p[n].size();i++)
				if (p[n][i]<=b)	
				{
					ans++;
				}
		printf("%d\n",ans);
	}
	return 0;
}
