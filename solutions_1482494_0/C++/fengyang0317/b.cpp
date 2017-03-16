#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int id;
	int a,b;
	int sc;
}da[1001],db[1001];
bool cmp1(node& x,node& y)
{
	if(x.b==y.b)return x.a>y.a;
	return x.b<y.b;
}
bool cmp2(node &x,node &y)
{
	if(x.a==y.a)return x.b>y.b;
	return x.a<y.a;
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("bout.txt","w",stdout);
	int i,j,t,n,cas,cur,ans,k;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++)
	{
		ans=0;
		cur=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&da[i].a,&da[i].b);
			da[i].id=i;
			da[i].sc=0;
			db[i]=da[i];
		}
		sort(da,da+n,cmp1);
		sort(db,db+n,cmp2);
		j=0;
		for(i=0;i<n;i++)
		{
			if(cur>=da[i].b)
			{
				//printf("%d++%d     %d\n",cur,i,da[i].sc);
				cur+=2-da[i].sc;
				ans++;
				da[i].sc=2;
				for(k=0;k<n;k++)
						if(db[k].id==da[i].id)
						{
							db[k].sc=2;
							break;
						}
			}
			else
			{
				while(db[j].a<=cur&&db[j].sc==2)
				{
					j++;
				}
				if(db[j].a<=cur)
				{
					//printf("%d--%d\n",cur,j);
					cur++;
					ans++;
					for(k=0;k<n;k++)
						if(da[k].id==db[j].id)
						{
							da[k].sc++;
							break;
						}
					j++;
				}
				else break;
				i--;
			}
		}
		printf("Case #%d: ",cas);
		if(i!=n)puts("Too Bad");
		else printf("%d\n",ans);
	}
	return 0;
}