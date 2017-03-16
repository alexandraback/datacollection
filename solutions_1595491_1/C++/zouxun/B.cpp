#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int x[105];
int main()
{
	int cases;
	scanf("%d",&cases);
	for (int tcase=1;tcase<=cases;tcase++)
	{
		int n,s,p;
		scanf("%d%d%d",&n,&s,&p);
		int ans=0;
		for (int i=1;i<=n;i++) scanf("%d",&x[i]);
		//  3m-4..3m-2
		//  3m-2..3m
		for (int i=1;i<=n;i++)
		{
			if (2<=x[i] && x[i]<=28) {
				if (x[i]>=3*p-2){
					ans++;
				} else if (x[i]>=3*p-4) {
					if (s){
						s--;
						ans++;
					}
				}
			}
		}
		
		for (int i=1;i<=n;i++)
		{
			if (x[i]<2 || x[i]>28){
				if (x[i]>=3*p-2)
					ans++;
			}
		}		
		printf("Case #%d: %d\n",tcase,ans);
	}
	return 0;
}
