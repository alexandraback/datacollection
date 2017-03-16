#include <stdio.h>
#include <string.h>
int a[1000], b[1000];
typedef struct {
	int a;
	int b;
	int flag;
} Level;
Level l[1000];
int comp(void * x, void * y)
{
	if ( ((Level*) x)->b > ((Level *)y)->b ) 
		return 1;
	else if ( ((Level*) x)->b == ((Level *)y)->b  && ((Level *)x)->a > ((Level *)y)->a) 
		return 1;
	return 0;
}
int main()
{
	int t , tind, n;
	int i, j, k, now, res;
	scanf("%d", &t);
	for(tind = 1; tind <= t; tind++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d%d",&l[i].a, &l[i].b);
			l[i].flag = 0;
		}
		qsort(l, n, sizeof(Level), comp);
		//for(i = 0; i < n; i++) printf("%d %d\n", l[i].a, l[i].b);
		//printf("--------------\n");
		now =0; res = 0;
		for(i = 0; i < n; i++) {	
			if(l[i].b > now ) {
				int need = l[i].b - now , done = 0;
				while(!done) {
					for(j = n -1, done = 1 ; j >= i && need > 0; j--){
						if(l[j].flag == 0 && l[j].a <= now) {
							need--;
							l[j].flag = 1;
							now++;
							done = 0;
							res++;
							//printf("play level%d rating 1\n",j );
						}
					}
					if(need == 0) done = 1; 
				}
				if(need > 0) goto TOO_BAD;
			}
			now += (2 - l[i].flag);
			l[i].flag = 2;
			res++;
		}
		printf("Case #%d: %d\n", tind , res);
		continue;
TOO_BAD:
		printf("Case #%d: Too Bad\n", tind );
	}
}
