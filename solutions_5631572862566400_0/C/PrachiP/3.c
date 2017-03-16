#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	FILE *fp = fopen(argv[1], "r");
	
	if (fp == NULL){
		printf("unable to open file");
		exit(1);
	}
	
	int test, t, count, max, visited[1001], bff[1001], i, j, num, n, a, prev, next, y;
	int ac, acount, m, b[1001];
	//fscanf(fp, "%d", &test);
	fscanf(fp, "%d", &test);
	for (t = 1; t <= test; t++){
		max = count = 0;
		fscanf(fp, "%d", &n);
		for (i = 1; i <= n; i++){
			fscanf(fp, "%d", &bff[i]);
		}
		
		for (i = 1; i <= n; i++){
			//printf("i is %d\n", i);
			for (j = 0; j < 1001; j++)
				visited[j] = 0;
		
			a = i;
			visited[i] = 1;
			prev = i;
			next = bff[i];
			count = 1;
			//printf("%d ", i);
			while(visited[next] == 0){
				a = prev;
				visited[next] = 1;
				prev = next;
				next = bff[next];
				count++;
				//printf("%d ", prev);
			}
			//printf("\n");
			
			//printf("a: %d prev: %d next: %d\n", a, prev, next);
		
			if (next == i)
				if (max < count)
					max = count;
			if (a == next){
				//printf("entered loop\n");
				num = prev;
				ac = 0;
				for (j = 1; j <= n; j++){
					if (bff[j] == num && visited[j] !=1){
						b[ac] = j;
						ac++;
					}
				}
				ac--;
				if (ac >= 0)
					count++;
				
				while (ac >= 0){
					acount = m = 0;
					num = b[ac];
					y = 1;
					while (y){
						//printf("num is %d\n", num);
						y = 0;
						for (j = 1; j <= n; j++){
							if (bff[j] == num && visited[j] != 1){
								acount++;
								num = j;
								y = 1;
								break;
							}
						}
					}
					if (acount > m)
						m = acount;
					ac--;
				}
				if(count > max)
					max = count;
			}		
			
		}
		
		printf("Case #%d: %d\n", t, max);
			
	}
	
	
	
	fclose(fp);
	return 0;
}
