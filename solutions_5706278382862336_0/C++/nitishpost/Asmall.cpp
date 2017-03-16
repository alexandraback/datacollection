#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
#include<fstream>
using namespace std;
int main()
{
//	freopen("A-small-attempt0.in","r",stdin);
//	freopen("output","w",stdout);
	long long int p,q;
	int t,arr[20],search_index,presentornot;
	arr[0]=1;
	for(int i=1;i<11;i++)
	{
		arr[i]=arr[i-1]*2;
	}
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld/%lld",&p,&q);
		//tells no of bits req;
		presentornot=binary_search(arr,arr+11,q);
		if(presentornot==1)
		{
			search_index=lower_bound(arr,arr+11,q)-arr;
			int index=0;
			while(p>0)
			{
				int rem=p%2;
				p=p/2;
				index++;
			}
			printf("Case #%d: %d\n", (i+1), (search_index-index+1));
		}
		else
		{
			printf("Case #%d: impossible\n",(i+1) );
		}
	}
	return 0;
}