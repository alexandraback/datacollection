#include <stdio.h>
#include <stdlib.h>

#if 0
#define DEBUG
#endif

/* small only */

/* can have [-10000,10000] */
int wall_height[20001];

int get_wall_height(int pos) {
	return wall_height[pos+10000];
}

void build_wall(int pos,int height) {
	if(wall_height[pos+10000]<height)wall_height[pos+10000]=height;
}

typedef struct {
	int day;
	int start,end,height;
} attack_t;

attack_t attack_list[1000];

int qsort_comp(const void* x,const void* y) {
	const attack_t* a=(const attack_t*)x;
	const attack_t* b=(const attack_t*)y;
	if((a->day)>(b->day))return 1;
	if((a->day)<(b->day))return -1;
	return 0;
}

int main(void) {
	int caseNum,caseCount;
	scanf("%d",&caseNum);
	for(caseCount=1;caseCount<=caseNum;caseCount++) {
		int d,n,w,e,s,delta_d,delta_p,delta_s;
		int N,i,j,k;
		int attack_count=0;
		int success_count=0;
		scanf("%d",&N);
		for(i=0;i<N;i++) {
			scanf("%d%d%d%d%d%d%d%d",
				&d,&n,&w,&e,&s,&delta_d,&delta_p,&delta_s);
			for(j=0;j<n;j++) {
				attack_list[attack_count].day=d+delta_d*j;
				attack_list[attack_count].start=w+delta_p*j;
				attack_list[attack_count].end=e+delta_p*j;
				attack_list[attack_count].height=s+delta_s*j;
				attack_count++;
			}
		}
		qsort(attack_list,attack_count,sizeof(attack_t),qsort_comp);
		for(i=0;i<=20000;i++)wall_height[i]=0;
		for(i=0;i<attack_count;i=j) {
			for(j=i;j<attack_count && attack_list[j].day==attack_list[i].day;j++) {
#ifdef DEBUG
				printf("attack %d [%d,%d] %d\n",attack_list[j].day,attack_list[j].start,attack_list[j].end,attack_list[j].height);
#endif
				for(k=attack_list[j].start-1;k<=attack_list[j].end;k++) {
					if(get_wall_height(k)<attack_list[j].height) {
						if(k==attack_list[j].start-1 && get_wall_height(k+1)>=attack_list[j].height)continue;
						if(k==attack_list[j].end && get_wall_height(k-1)>=attack_list[j].height)continue;
						success_count++;
#ifdef DEBUG
						printf("hit [%d,%d] %d\n",attack_list[j].start,attack_list[j].end,attack_list[j].height);
#endif
						break;
					}
				}
			}
			for(j=i;j<attack_count && attack_list[j].day==attack_list[i].day;j++) {
				for(k=attack_list[j].start;k<attack_list[j].end;k++) {
					build_wall(k,attack_list[j].height);
				}
			}
		}
		printf("Case #%d: %d\n",caseCount,success_count);
	}
	return 0;
}
