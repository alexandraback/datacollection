#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<bitset>

#define PR(x) printf(#x"=%d\n",x)
#define READ2(x,y) scanf("%d %d",&x,&y)
#define REP(i,a) for(int i=0;i<a;i++)
#define READ(x) scanf("%d",&x)
#define PRARR(x,n) for(int i=0;i<n;i++)printf(#x"[%d]=\t%d\n",i,x[i])
using namespace std;
vector< vector<int> >Smmap(20*100010);

int main() { 
int t;
scanf("%d",&t);
int j=0;
while(t--)
	{
	printf("Case #%d:\n",j+1);j++;
	bool fnd=false;
	bool found[20*100001]={false};
	for(int i=0;i<20*100001;i++)
		Smmap[i].clear();
	int n;
	scanf("%d",&n);
	 
	int arr[n+1];
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	long long tr=2<<(n-1);
	bitset<21> mp;
	for(long long i=1;i<tr;i++)
		{
		mp.reset();
		int trp=i;
		int idx=0;
		while(trp)
			{
			
			if(trp&1) mp.set(idx);
			idx++;
			trp>>=1;
			}
		
		int sum=0;
		for(int k=0;k<n;k++)
			{
			
			if(mp.test(k))
				{
				
				//printf("%lld:%dth bit is set\n",i,k);
				sum+=arr[k];
				}
			}
			//printf("Sum is possible %d\n",sum);
		if(found[sum]){
				for(int k=0;k<n;k++)
					if(mp.test(k))
						printf("%d ",arr[k]);
				puts("");
				int sz=Smmap[sum].size();
				for(int k=0;k<sz;k++)
					printf("%d ",Smmap[sum][k]);
				puts("");
				
			fnd=true;
			break;
			}
	if(fnd==true) break;
	found[sum]=true;
	for(int k=0;k<n;k++)
		{
		if(mp.test(k))
		Smmap[sum].push_back(arr[k]);
		
		}
	}
	if(fnd==false) puts("Impossible");
	
	}
}
