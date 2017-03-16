#include <iostream>
#include <algorithm>
using namespace std;

int T,n,a[1010],b[1010],lev[1010];

int work()
{
	int star,num,gap;
	memset(lev,0,sizeof(lev));
	
	bool suc;
	star=num=0;
	while(true)
	{
		suc=false;
		for(int i=0;i<n;i++)
			if(lev[i]<2 && star>=b[i])
			{
				suc=true;
				if(lev[i]==0) star+=2;
				else star++;
				lev[i]=2;
				num++;
				break;
			}
		if(suc) 
			continue;
		gap=-1;
		int id=-1;
		for(int i=0;i<n;i++)
			if(lev[i]==0 && star>=a[i] && b[i]-star>gap)
			{
				gap=b[i]-star;
				id=i;
			}
		if(id==-1) break;
		lev[id]=1;
		num++;
		star++;
	}
	suc=true;
	for(int i=0;i<n;i++)
		if(lev[i]!=2)
		{
			suc=false;
			break;
		}
	if(suc) return num;
	else return -1;
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	scanf("%d",&T);
	for(int cnb=1;cnb<=T;cnb++)
	{	
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",a+i,b+i);
		int res=work();
		if(res!=-1)
			printf("Case #%d: %d\n",cnb,res);
		else printf("Case #%d: Too Bad\n",cnb);
	}
}
