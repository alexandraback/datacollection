#include <stdio.h>
#include <string.h>
#define NN 202

int kinb[NN][NN], n, type[NN];
int tried[1024*1024+10];

bool search(int on, int keys[], int opened[], int bs[], int state)
{
	if (on == n) return true;
	if (tried[state]) return false;
	tried[state] = 1;
	int i,j;
	bool ok;
	for (i=1; i<=n; i++)
	{
		if (bs[i] || keys[type[i]]==0) continue;
		bs[i] = 1;
		opened[on] = i;
		keys[type[i]]--;
		state += (1<<(i-1));
		for (j=1; j<=kinb[i][0]; j++) keys[kinb[i][j]]++;
		ok = search(on+1, keys, opened, bs, state);
		if (ok) return ok;
		for (j=1; j<=kinb[i][0]; j++) keys[kinb[i][j]]--;
		bs[i] = 0;
		keys[type[i]]++;
		state -= (1<<(i-1));
	}
	return false;
}

int main()
{
	int t,k,m;
	int keys[NN];
	int i,j,opened[NN],boxstate[NN];

	freopen("D-small-attempt1.in", "r",stdin);
	freopen("D-small.out", "w", stdout);
	scanf("%d",&t);
	for (int cas=1; cas<=t; cas++)
	{
		scanf("%d%d",&m,&n);
		memset(keys, 0, sizeof(keys));
		for (i=0; i<m; i++) {
			scanf("%d",&k);
			keys[k]++;
		}
		for (i=1; i<=n; i++)
		{
			scanf("%d%d",&type[i],&kinb[i][0]);
			for (j=1; j<=kinb[i][0]; j++) {
				scanf("%d",&kinb[i][j]);
			}
		}
		memset(boxstate, 0, sizeof(boxstate));
		memset(tried, 0, sizeof(tried));
		bool ok = search(0,keys,opened,boxstate,0);
		printf("Case #%d:", cas);
		if (!ok) {
			printf(" IMPOSSIBLE\n");
			continue;
		}
		for (i=0; i<n; i++) printf(" %d", opened[i]);
		printf("\n");
	}
	return 0;
}

