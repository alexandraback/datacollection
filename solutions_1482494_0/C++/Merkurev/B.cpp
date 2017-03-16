#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int a[1005];
int b[1005];
int taked[1005];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	scanf("%d",&t);
	for (int T=0;T<t;T++)
	{
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			taked[i]=0;
			scanf("%d%d",&a[i],&b[i]);
		}
		int ans=0;
		int ct=0;
		while (true)
		{
			int cur=-1;
			int tcur=-1;//0-берём 1 ; 1-добираем 2-й ; 2-берём 2;
			for (int i=0;i<n;i++)
			{
				if (taked[i]!=2)
				{
					if (cur==-1 || tcur==0)
						if (b[i]<=ct)
						{
							cur=i;
							if (taked[i]==0)
								tcur=2;
							else
								tcur=1;
						}
						else if (a[i]<=ct && taked[i]==0)
							if (tcur==-1 || b[i]>b[cur])
							{
								cur=i;
								tcur=0;
							}
				}
			}
			if (tcur==-1)
				break;
			if (tcur==0)
			{
				taked[cur]=1;
				ct++;
			}
			if (tcur==1)
			{
				taked[cur]=2;
				ct++;
			}
			if (tcur==2)
			{
				taked[cur]=2;
				ct+=2;
			}
			ans++;
		}
		if (ct==2*n)
			printf("Case #%d: %d\n",T+1,ans);
		else
			printf("Case #%d: Too Bad\n",T+1);
	}

	return 0;
}