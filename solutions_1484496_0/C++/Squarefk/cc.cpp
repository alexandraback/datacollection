#include <cstdio>

using namespace std;

int list1[550],list2[550],hh[2002000];
int t,n,data[550],st[2002000];
bool can;

void make(int now,int before)
{
	list1[0]=0;int temp;
	temp=now;
	while (temp) {list1[++list1[0]]=hh[temp];temp-=hh[temp];}
	list2[0]=1;list2[1]=before;
	temp=now-before;
	while (temp) {list2[++list2[0]]=hh[temp];temp-=hh[temp];}
	for (int i=1;i<=list1[0];++i)
		for (int j=1;j<=list2[0];++j)
			if (list1[i]==list2[j])
				{list1[i]=1;list2[j]=0;}
	for (int i=1;i<list1[0];++i)
		if (list1[i]) printf("%d ",list1[i]);
	printf("%d\n",list1[list1[0]]);
	for (int i=1;i<list2[0];++i)
		if (list2[i]) printf("%d ",list2[i]);
	printf("%d\n",list2[list2[0]]);	
}

void insert_hash(int now,int before)
{
	if (hh[now])
	{
		make(now,before);
		can=true;
		return;
	}
	hh[now]=before;
	st[++st[0]]=now;
}

void work()
{
		for (int i=1;i<=n;++i)
		{
			int tttt=st[0];
			for (int j=1;j<=tttt;++j)
			{
				insert_hash(st[j]+data[i],data[i]);
				if (can) return;
			}
			insert_hash(data[i],data[i]);
			if (can) return;
		}
}

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&t);
	for (int tt=1;tt<=t;++tt)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i) scanf("%d",&data[i]);
		can=false;
		printf("Case #%d:\n",tt);
		work();
		for (int i=1;i<=st[0];++i) hh[st[0]]=0;
		st[0]=0;
	}
	return 0;
}
