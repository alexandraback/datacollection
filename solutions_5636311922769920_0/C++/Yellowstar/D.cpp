#include<cstdio>
using namespace std;
inline long long conve(int* arr,int l,const int& p)
{
	long long ans=0,po=1;
	while(l--)
	{
		ans+=po*arr[l];
		po*=p;
	}
	return ans;
}
int main()
{
	int T,k,c,s,cas=0,arr[201],i;
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&k,&c,&s);
		printf("Case #%d:",++cas);
		if(c*s<k)
		{
			puts(" IMPOSSIBLE");
			continue;
		}
		
		for(i=0;i<k+c;++i)
		{
			arr[i]=i%k;
		}
		for(i=0;i<k;i+=c)
		{
			printf(" %lld",conve(arr+i,c,k)+1);
		}
		putchar('\n');
	}
	return 0;
}
/*
5
2 3 2
1 1 1
2 1 1
2 1 2
3 2 3
*/

