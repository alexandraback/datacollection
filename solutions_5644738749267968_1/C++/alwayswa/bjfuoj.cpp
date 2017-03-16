#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
#define LL long long
int A[105][105];
double Naomi[1009],Ken[1009];
int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int T;
	scanf("%d", &T);
	int cas = 0;
	while (T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf",Naomi+i);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%lf",Ken+i);
		}
		sort(Naomi,Naomi+n);
		sort(Ken,Ken+n);
//		for(int i=0;i<n;i++)
//		{
//			printf("%lf ",Naomi[i]);
//		}
//		cout<<endl;
//		for(int i=0;i<n;i++)
//		{
//			printf("%lf ",Ken[i]);
//		}
//		cout<<endl;
		int ans1=0,ans2=0;
		int cur=0;
		for(int i=0;i<n;i++)
		{
			for(;cur<n;)
			{
				if(Naomi[i]<Ken[cur])
				{
					ans2++;
					cur++;
					break;
				}
				cur++;
			}
		}
		cur=n-1;
		for(int i=n-1;i>=0;i--)
		{
			for(;cur>=0;)
			{
				if(Naomi[i]>Ken[cur])
				{
					ans1++;
					cur--;
					break;
				}
				cur--;
			}
		}
		printf("Case #%d: %d %d\n", ++cas,ans1,n-ans2);
	}
	return 0;
}
