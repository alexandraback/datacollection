#include <cstdio>
#include <set>

using namespace std;
int a[1500], b[1500];
struct node{
	int id, number;
};
set<node > s;

bool operator<(node a, node b)
{
	return a.number<b.number || a.number==b.number && a.id<b.id;
}
int main()
{
	int N;
	scanf("%d",&N);
	for (int I=1;I<=N;++I)
	{
		s.clear();
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;++i)
		{
			scanf("%d%d",&a[i], &b[i]);
		
		}
		int done=0, nowhave=0, tt=0;;
		while (done<n)
		{
			int tid=-1;
			for (int i=0;i<n;++i)
				if (b[i]<=nowhave && b[i]!=-1)
				{
					tid=i;
					break;
				}
			if (tid!=-1)
			{
				if (a[tid]!=-1) nowhave+=2; else nowhave++;
				b[tid]=a[tid]=-1;
				++done;
			}
			else
			{
				int t2=-1;
				for (int i=0;i<n;++i)
					if (a[i]<=nowhave && a[i]!=-1 && b[i]>t2)
					{
						t2=b[i];
						tid=i;
//						break;
					}
				if (tid!=-1)
				{
					a[tid]=-1;
					nowhave++;
				}
			}
//			printf("%d %d\n", tid, nowhave);
			if (tid==-1) break;
			++tt;
		}
		if (done==n)
			printf("Case #%d: %d\n", I, tt);
		else printf("Case #%d: Too Bad\n", I);
	}
}
