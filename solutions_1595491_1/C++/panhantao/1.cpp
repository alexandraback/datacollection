#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int arr[105];

bool cmp(const int &a,const int &b)
{
	return a > b;
}

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("B-small-attempt0.in","r",stdin);
	freopen("B-large.in","r",stdin);
	freopen("1.out","w",stdout);
	int testcase;
	scanf("%d\n",&testcase);
	for(int t = 1; t <= testcase; t ++)
	{
		int n,s,p;
		scanf("%d%d%d",&n,&s,&p);
		for(int i = 0; i < n; i ++) scanf("%d",&arr[i]);
		
		sort(arr,arr+n,cmp);
		
		int ans = 0;
		for(int i = 0; i < n; i ++)
		{
			if(arr[i] < 2)
			{
				if(arr[i] >= p) ans ++;
				continue;
			}
			double aver = 1.0*arr[i]/3;
			if(aver > p-1.0) ans ++;
			else if(1.0<=p-aver && p-aver<=1.5)
			{
				if(s --) ans ++;
				else break;
			}
		}
		
		printf("Case #%d: %d\n",t,ans);
	}
}
