// Qualification Round
// Problem D-small

#include <stdio.h>

int a[201],			// Key : # held
	b[201],			// Chest : Key
	c[201][401],	// Chest : Keys
	d[201];			// Final path
	N;				// # of chests
char v[201];		// Chest opened
char valid(){
	int h[201], i,j;
	for(i = 1; i <= 200; i++)
		h[i] = a[i];
	for(i = 1; i <= N; i++){
		h[b[i]]--;
		for(j = 1; j <= c[i][0]; j++)
			h[c[i][j]]++;
	}
	for(i = 1; i <= 200; i++)
		if(h[i] < 0)
			return 0;
	return 1;
}
char eval(int cr){
	if(!cr) return 1;
	char f;
	int i,j;
	for(i = 1; i <= N; i++){
		if(!v[i] && a[b[i]]){
			//if(cr > 16) printf("-- ATTEMPTING i=%d cr=%d\n",i,cr);
			//printf("a: ");for(j=1;j<=5;j++)printf("%d ",a[j]);printf("\n");
			if(!c[i][0] && a[b[i]] == 1 && cr > 1){
				f = 0;
				for(j = i+1; j <= N; j++){
					if(!v[j] && b[j] == b[i] && c[j][0] == 1 && c[j][1] == b[i]){
						f = 1;
						break;
					}
				}
				if(f) continue;
			}
			a[b[i]]--;
			v[i] = 1;
			for(j = 1; j <= c[i][0]; j++)
				a[c[i][j]]++;
			if(eval(cr - 1)){
				d[++(d[0])] = i;
				return 1;
			}else{
				a[b[i]]++;
				v[i] = 0;
				for(j = 1; j <= c[i][0]; j++)
					a[c[i][j]]--;
			}
		}
	}
	return 0;
}
int main(){
	int T,t,K, i,j, n;
	FILE *fi = fopen("../ds.in","r"),
		*fo = fopen("../ds.out","w");
	fscanf(fi,"%d\n",&T);
	for(t = 1; t <= T; t++){
		fprintf(fo,"Case #%d: ",t);
		// Reset data
		fscanf(fi,"%d %d\n",&K,&N);
		for(i = 1; i <= 200; i++)
			a[i] = 0;
		for(i = 1; i <= N; i++)
			c[i][0] = 0, v[i] = 0;
		d[0] = 0;
		// Read data
		for(i = 0; i < K; i++){
			fscanf(fi,"%d",&n);
			a[n]++;
		}
		//
		//printf("a: ");for(i=1;i<=N+10;i++)printf("%d ",a[i]);printf("\n");
		for(i = 1; i <= N; i++){
			fscanf(fi,"%d %d",b+i,&n);
			for(j = 1; j <= n; j++)
				fscanf(fi,"%d",c[i]+j);
			c[i][0] = j - 1;
		}
		//
		//for(i=1;i<=N;i++){printf("b[%d]=%d: ",i,b[i]);for(j=1;j<=c[i][0];j++)printf("%d ",c[i][j]);printf("\n");}
		// Ensure enough keys exist, then DFS
		if(valid() && eval(N)){
			printf("-- d: ");
			for(i = d[0]; i > 1; i--){
				fprintf(fo,"%d ",d[i]);
				printf("%d ",d[i]);
			}
			fprintf(fo,"%d\n",d[1]);
			printf("%d\n",d[1]);
		}else
			fprintf(fo,"IMPOSSIBLE\n");
	}
	fclose(fi); fclose(fo);
	return 0;
}
