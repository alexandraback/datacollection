#include <stdio.h>
#include <vector>
#define N 20
#define K 200
using namespace std;

struct Chest
{
	int t;
	vector<int> k;
	
	void clear()
	{
		t = 0;
		k.clear();
	}
};

int n;
int kinit[K];
int from[1<<N];
bool available[1<<N];
Chest chest[N];

int getTarget(int a, int b)
{
	int ans = -1;
	for (int i=0;i<n;++i)
		if (a+(1<<i)==b)
			ans = i;
	return ans;
}

bool transfer(int a, int b)
{
	int k[K];
	for (int i=0;i<K;++i)
		k[i] = kinit[i];
	for (int i=0;i<n;++i)
		if (a&(1<<i))
		{
			--k[chest[i].t];
			for (int j=0;j<chest[i].k.size();++j)
				++k[chest[i].k[j]];
		}
	return k[chest[getTarget(a, b)].t]>0;
}

int main()
{
	int t;
	int k;
	vector<int> ans;
	scanf("%d", &t);
	for (int i=1;i<=t;++i)
	{
		for (int j=0;j<K;++j)
			kinit[j] = 0;
		for (int j=0;j<(1<<n);++j)
			available[j] = false;
		ans.clear();
		scanf("%d%d", &k, &n);
		for (int j=0;j<k;++j)
		{
			int ki;
			scanf("%d", &ki);
			++kinit[ki-1];
		}
		for (int j=0;j<n;++j)
		{
			chest[j].clear();
			int ti, ki;
			scanf("%d%d", &ti, &ki);
			chest[j].t = ti-1;
			for (int l=0;l<ki;++l)
			{
				int kii;
				scanf("%d", &kii);
				chest[j].k.push_back(kii-1);
			}
		}
		available[(1<<n)-1] = true;
		for (int j=(1<<n)-1;j>=0;--j)
			if (available[j])
				for (int l=0;l<n;++l)
					if ((j&(1<<l)) && transfer(j-(1<<l), j))
						if (!available[j-(1<<l)] || j<from[j-(1<<l)])
						{
							available[j-(1<<l)] = true;
							from[j-(1<<l)] = j;
						}
		if (available[0])
		{
			int now = 0;
			while (now!=(1<<n)-1)
			{
				int target = getTarget(now, from[now]);
				ans.push_back(target);
				now |= 1<<target;
			}
		}
		printf("Case #%d:", i);
		if (ans.size())
			for (int j=0;j<n;++j)
				printf(" %d", ans[j]+1);
		else
			printf(" IMPOSSIBLE");
		printf("\n");
	}
	return 0;
}
