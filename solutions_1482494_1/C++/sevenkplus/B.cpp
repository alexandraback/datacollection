#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1010
int a[N],b[N],c[N],n;
int main()
{
	int _;scanf("%d",&_);
	for(int __=1;__<=_;__++)
	{
		scanf("%d",&n);int S=0,T=0;
		for(int i=0;i<n;i++)scanf("%d%d",a+i,b+i);
		memset(c,0,sizeof c);
		bool G=1;
		while(T!=n*2)
		{
			bool F=0;
			for(int i=0;i<n;i++)
				if(b[i]<=T&&c[i]!=2)for(F=1,S++;c[i]!=2;c[i]++,T++);
			if(F)continue;
			int p=-1;
			for(int i=0;i<n;i++)
				if(!c[i]&&a[i]<=T)if(p==-1||b[i]>b[p])p=i;
			if(p==-1){if(T!=n*2)G=0;break;}
			S++,T++,c[p]++;
		}
		if(G)printf("Case #%d: %d\n",__,S);
		else printf("Case #%d: Too Bad\n",__);
	}
	return 0;
}
