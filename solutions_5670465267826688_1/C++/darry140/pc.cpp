#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long len,rep;
string ar;
/*
   1  i  j  k
1  1  i  j  k
i  i -1  k -j
j  j -k -1  i
k  k  j -i -1
*/
struct qua
{
	int ar[4];
	void init()
	{
		memset(ar,0,sizeof(ar));
		ar[0]=1;
	}
	void mul(char c)
	{
		int ans[]={0,0,0,0};
		int tom[]={0,0,0,0};
		tom[c-'i'+1]++;
		ans[0]=ar[0]*tom[0]-ar[1]*tom[1]-ar[2]*tom[2]-ar[3]*tom[3];
		ans[1]=ar[0]*tom[1]+ar[1]*tom[0]+ar[2]*tom[3]-ar[3]*tom[2];
		ans[2]=ar[0]*tom[2]-ar[1]*tom[3]+ar[2]*tom[0]+ar[3]*tom[1];
		ans[3]=ar[0]*tom[3]+ar[1]*tom[2]-ar[2]*tom[1]+ar[3]*tom[0];
		memcpy(ar,ans,sizeof(int)*4);
		//cout<<endl;
		//for(int i=0;i<4;i++)
		//	cout<<ar[i]<<" ";cout<<endl;
	}
};
bool sol()
{
	string all;
	all.clear();
	rep=min(rep,24+rep%4);
	for(int i=0;i<rep;i++)
		all+=ar;
	qua now;
	now.init();
	for(int i=0,md=1;i<all.size();i++)
	{
		now.mul(all[i]);
		if(now.ar[md]==1)
		{
			md++;
			now.init();
			//cout<<md<<endl;
			if(md==3)
			{
				for(int j=i+1;j<all.size();j++)
					now.mul(all[j]);
				return now.ar[md]==1;
			}
		}
	}
	return false;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		scanf("%lld%lld",&len,&rep);
		cin>>ar;
		printf("Case #%d: ",cas);
		puts(sol()?"YES":"NO");
	}
	return 0;
}
