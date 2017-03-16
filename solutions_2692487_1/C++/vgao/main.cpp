#include <cstdlib>
#include <cstdio>
#include <cstring>

#define INF 0x7fffffff

int cmp(const void *p, const void *q)
{
	return *(int *)p-*(int *)q;
}

void dist(int c, int d, int *dis, int *size)
{
	if (c>d) {
		*dis=0;
		*size=c+d;
		return;
	}
	if (c<=1) {
		*dis=INF;
		*size=c;
		return;
	}
	int n=0;
	while(c<=d) {
		n++;
		c+=c-1;
	}
	*dis=n;
	*size=c+d;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nCaseCnt; scanf("%d", &nCaseCnt);
	for(int index=1; index<=nCaseCnt; index++) {
		int a, n; scanf("%d%d", &a, &n);
		int v[100];
		for(int i=0; i<n; i++)
			scanf("%d", &v[i]);
		qsort(v, n, sizeof(int), cmp);
		int min_cnt=INF;
		for(int i=0; i<=n; i++) {
			int m=n-i, cnt=i;
			int cur=a;
			//printf("%d, %d\n", cnt, m);
			for(int j=0; j<m; j++) {
				int dis, va; dist(cur, v[j], &dis, &va);
				if (dis==INF)
					goto label;
				//printf("%d->%d(%d)  dis: %d\n", cur, v[j], va, dis);
				cur=va;
				cnt+=dis;
			}
			if (cnt<min_cnt)
				min_cnt=cnt;
label:
			;
		}
		printf("Case #%d: %d\n", index, min_cnt);
		//printf("%d, %d\n", a, n);
		//for(int i=0; i<n; i++)
			//printf("%d ", v[i]);
		//printf("\n");
	}
	//system("pause");
	return 0;
}