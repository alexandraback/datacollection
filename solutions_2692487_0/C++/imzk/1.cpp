#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int _min(int a,int b)
{
	return a<b?a:b;
}
long long v[105];
int main()
{
	freopen("T.txt", "w", stdout);
	long long total;
	int now,step;
	int size,t,i;
	int ca=1;
	int a,n;
	cin>>t;
	while(t--)
	{
		cin>>a>>n;
		for(i=0;i<n;i++)
		{
			cin>>v[i];
		}
		sort(v,v+n);
		total=a;
		step=999;
		now=0;
		for(i=0;i<n;i++)
		{
			if(total>v[i])
			{
				total+=v[i];
				continue;
			}
			else
			{
				step=_min(step,now+n-i);
				size=total-1;
				if(size<=0)
					break;
				else
				{
					while(total<=v[i])
					{
						now++;
						total+=size;
						size=total-1;
					}
					total+=v[i];
				}
			}
		}
		step=_min(step,now);
		if(i<n)
			step=n;
		if(step==999)
			step=0;
		printf("Case #%d: %d\n",ca++,step);
	}
	return 0;
}
