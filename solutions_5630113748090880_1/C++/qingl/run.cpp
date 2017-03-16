#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
const int N = 105;
int a[N*N],ret[N];
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d:",ca++);
		int n,v,k=0;
		scanf("%d",&n);
		for(int i=0;i<2*n-1;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&v);
				a[k++]=v;
			}
		}
		sort(a,a+k);
		int p=0;
		for(int i=0;i<k;)
		{
			int cnt=0,j;
			for(j=i;j<k&&a[j]==a[i];j++)
			{
				cnt++;
			}
			if(cnt%2)ret[p++]=a[i];
			i=j;
		}
		for(int i=0;i<p;i++)printf(" %d",ret[i]);
		puts("");
	}
	return 0;
}

