#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>

const int N=2000010;
const int mod=1e9+7;

using namespace std;
typedef long long ll;

#define pb push_back

int mx[N],v[N];
int e,r,n;



int main()
{
	int ca,t=0;
	for(scanf("%d",&ca);ca--;)
	{
		
		scanf("%d%d%d",&e,&r,&n);
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		printf("Case #%d: ",++t);
		ll ret=0;
		for(int i=0,sum=e;i<n;i++)
		{
			int id=-1;
			for(int j=i+1;j<n;j++)
			{
				if(v[j]>v[i])
				{
					id=j;
					break;
				}
			}
			if(id==-1)
			{
				ret+=1ll*sum*v[i];
				sum=0;
			}
			else
			{
				ll tmp=1ll*r*(id-i);
				if(tmp+sum>e)
				{
					ret+=1ll*(min(min(tmp+sum-e,0ll+e),sum+0ll))*v[i];
					sum-=min(min(tmp+sum-e,0ll+e),sum+0ll);
				}
			}
			sum+=r;
		}
		printf("%I64d\n",ret);
	}
    return 0;
}