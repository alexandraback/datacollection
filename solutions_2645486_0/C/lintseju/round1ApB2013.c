#include <stdio.h>

int lm(int task[], int idx, int n, int win)
{
	int i = 0;
	if(win < idx)
		i = win - idx;
	for(;i < win + idx && i < n;i++){
		if(i == idx)
			continue;
		if(task[i] > task[idx])
			break;
	}
	if(i == win + idx || i == n)
		return 1;
	return 0;
}

int main()
{
	int i, j, t, n, m, c = 1, r, e, gain, enow, max = -1;
	int task[10005];
	scanf("%d", &t);
	while(t--){
		max = -1;
		scanf("%d%d%d", &e, &r, &n);
		for(i = 0;i < n;i++){
			scanf("%d", &task[i]);
			if(max < task[i])
				max = task[i];
		}
		gain = 0;
		enow = e;
		for(i = 0;i < n - 1;i++){
			if(task[i] == max){
				gain += task[i] * enow;
				enow = r;
			}else
				gain += task[i] * r;
			//printf("%d\n", gain);
		}
		gain += task[n - 1] * enow;
		printf("Case #%d: %d\n", c++, gain);
	}
	return 0;
}