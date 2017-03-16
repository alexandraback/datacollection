#include<stdio.h>
int T, t, N;
int lq[30], ltop, lsum;
int rq[30], rtop, rsum;
int pt[30];
int bt(int n)
{
	if(n == N+1){
		if(ltop && rtop && lsum == rsum){
			int i;
			for(i = 0; i < ltop; i++) printf("%d ",lq[i]);
			printf("\n");
			for(i = 0; i < rtop; i++) printf("%d ",rq[i]);
			printf("\n");
			return true;
		}
		return false;
	}
	lq[ltop++] = pt[n]; lsum += pt[n];
	if(bt(n+1)) return true;
	lsum -= pt[n]; ltop--;

	rq[rtop++] = pt[n]; rsum += pt[n];
	if(bt(n+1)) return true;
	rsum -= pt[n]; rtop--;

	if(bt(n+1)) return true;

	return false;

}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i;
	scanf("%d", &T);
	for(t = 1; t <= T; t++){
		ltop = lsum = rtop = rsum = 0;
		printf("Case #%d: \n", t);
		scanf("%d", &N);
		for(i = 1; i <= N; i++) scanf("%d", &pt[i]);
		if(!bt(1)) printf("Impossible\n");
	}
	return 0;
}
