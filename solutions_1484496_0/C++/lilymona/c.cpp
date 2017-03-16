#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define N 500

int n;
int a[N];

void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
}

int flag[2000010],prev[2000010];

void print(int k)
{
	if(k==0) return;
	print(prev[k]);
	if(prev[k]) printf(" ");
	printf("%d",k-prev[k]);
}

void work()
{
	int s=0;
	memset(flag,0,sizeof(flag));
	flag[0]=1;
	for(int i=0;i<n;i++)
	{
		s+=a[i];
		for(int j=s;j>=a[i];j--) if(flag[j-a[i]])
		{
			if(flag[j])
			{
				print(j);
				printf("\n");
				prev[j]=j-a[i];
				print(j);
				printf("\n");
				return;
			}
			flag[j]++;
			prev[j]=j-a[i];
		}
	}
	printf("Impossible\n");
}

int main()
{
	int t,cnt=0;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d:\n",++cnt);
		init();
		work();
	}
	return 0;
}

