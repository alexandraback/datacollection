#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000010
int a[N],n,w;
int main()
{
	int _;scanf("%d",&_);
	for(int __=1;__<=_;__++)
	{
		scanf("%d%d",&w,&n);
		for(int i=0;i<n;i++)scanf("%d",a+i);
		sort(a,a+n);
		int S=n,T=0;
		for(int i=0;i<n;i++)
			if(w>a[i])w+=a[i];
			else
			{
				S=min(S,T+n-i);
				if(w==1){T=1e9;break;}
				while(w<=a[i])w+=w-1,T++;
				w+=a[i];
			}
		S=min(S,T);
		printf("Case #%d: %d\n",__,S);
	}
	return 0;
}