#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int A[10], flag[500];

int main()
{
	freopen("GL1.in","r",stdin);
	freopen("GL1.out","w",stdout);
	int T,R,N,M,K;
	scanf("%d%d%d%d%d",&T,&R,&N,&M,&K);
	printf("Case #1:\n");
	for (int t=1;t<=R;t++)
	{
		bool ok(false);
		for (int i=1;i<=K;i++) scanf("%d",&A[i]);
		for (int i=2;i<=M;i++)
		{
			for (int j=2;j<=M;j++)
			{
				for (int k=2;k<=M;k++)
				{
					memset(flag,0,sizeof flag);
					for (int p=1;p<=K;p++) flag[A[p]]++;
					int cnt(0);
					while (flag[1]) flag[1]--, cnt++;
					while (flag[i]) flag[i]--, cnt++;
					while (flag[j]) flag[j]--, cnt++;
					while (flag[k]) flag[k]--, cnt++;
					while (flag[i*j]) flag[i*j]--, cnt++;
					while (flag[i*k]) flag[i*k]--, cnt++;
					while (flag[j*k]) flag[j*k]--, cnt++;
					while (flag[i*j*k]) flag[i*j*k]--, cnt++;
					if (cnt<K) continue;
					ok=true;
					printf("%d%d%d\n",i,j,k);
					break;
				}	
				if (ok) break;
			}
			if (ok) break;
		}
	}
	return 0;
}

