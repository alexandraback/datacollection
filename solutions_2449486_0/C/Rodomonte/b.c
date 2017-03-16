// Qualification Round
// Problem A

#include <stdio.h>
#include <stdlib.h>

int qcomp(const void *e1, const void *e2){
	int f = *((int*)e1), s = *((int*)e2);
	if(f > s) return 1;
	if(f < s) return -1;
	return 0;
}

int a[10][10],		// Desired
	b[10][10],		// Attempted
	r[10], c[10];	// Row max, col max
int main(){
	char f;
	int T,t,N,M, i,j,k, m,n;
	FILE *fi = fopen("../Google/bs.in","r"),
		*fo = fopen("../Google/bs.out","w");
	fscanf(fi,"%d\n",&T);
	for(t = 1; t <= T; t++){
		fprintf(fo,"Case #%d: ",t);
		fscanf(fi,"%d %d\n",&N,&M);
		m = 0;
		for(i = 0; i < N; i++) r[i] = 0;
		for(i = 0; i < M; i++) c[i] = 0;
		for(i = 0; i < N; i++)
			for(j = 0; j < M; j++){
				fscanf(fi,"%d",a[i]+j);
				n = a[i][j];
				if(n > r[i]) r[i] = n;
				if(n > c[j]) c[j] = n;
				if(n > m) m = n;
			}
		for(i = 0; i < N; i++)
			for(j = 0; j < M; j++)
				b[i][j] = m;
		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				n = a[i][j], f = 0;
				if(n == m){
					f = 1;
					continue;
				}
				if(n == r[i]){
					for(k = 0; k < M; k++)
						if(b[i][k] > n)
							b[i][k] = n;
					f = 1;
				}
				if(n == c[j]){
					for(k = 0; k < N; k++)
						if(b[k][j] > n)
							b[k][j] = n;
					f = 1;
				}
				if(!f) break;
			}
			if(!f) break;
		}
		if(f){
			for(i = 0; i < N; i++){
				for(j = 0; j < M; j++)
					if(a[i][j] != b[i][j]){
						f = 0;
						break;
					}
				if(!f) break;
			}
		}
		fprintf(fo,f?"YES\n":"NO\n");
	}
	fclose(fi); fclose(fo);
	return 0;
}
