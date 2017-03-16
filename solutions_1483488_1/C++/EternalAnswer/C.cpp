#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int sum[9];
int a[20];
int visit[2010000];
int Test,L,R,len,cnt;

void Get(int x)
{
	len=0;
	for (;x;x/=10)
		a[++len]=x % 10;
	for (int i=1,j=len;i<j;++i,--j)
		swap(a[i],a[j]);
	for (int i=1;i<=len;++i)
		a[len+i]=a[i];
}

int main()
{
	//freopen("x.in","r",stdin);
	//freopen("c.out","w",stdout);
	
	memset(visit,0,sizeof(visit));
	cnt=0;
	sum[1]=1;
	for (int i=2;i<=9;++i)
		sum[i]=sum[i-1]*10;
	scanf("%d",&Test);
	for (int ii=1;ii<=Test;++ii)
	{
		scanf("%d%d",&L,&R);
		int res=0;
		for (int i=L;i<R;++i)
		{
			++cnt;
			Get(i);
			int now=i;
			for (int j=2;j<=len;++j)
			{
				now=(now-a[j-1]*sum[len])*10+a[j+len-1];
				if (now>i && now<=R)
					if (visit[now]<cnt)
					{
						visit[now]=cnt;++res;
					}
			}
		}
		printf("Case #%d: %d\n",ii,res);
	}
	
	return 0;
}