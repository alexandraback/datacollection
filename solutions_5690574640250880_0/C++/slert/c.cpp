#include <stdio.h>
int m,r,c;

int b[60];
int ms = 0;

int solve(int i){
	if(i == r-1){
		if(ms+b[r-2] == m){
			b[r-1] = b[r-2];
			return 1;
		}
		else return 0;
	}
	if(ms > m)return 0;
	if(i>0 && ms+(r-i)*b[i-1] < m)return 0;
	if(ms+(r-i)*c < m)return 0;
	for(int j = 0; j <= c; j++){
		if(j==c-1)continue;
		if(i == 0 || j<=b[i-1]){
			b[i] = j;
			ms += j;
			if(solve(i+1))
				return 1;
			ms -= j;
		}
	}
	return 0;
}

int main(){
	int tc;
	scanf("%d", &tc);
	for(int ti = 1; ti <= tc; ti++)
	{
		scanf("%d%d%d", &r, &c, &m);
		printf("Case #%d:\n", ti);
		if(r == 1 || c == 1){
			if(r == 1){
				for(int i = 0; i < m; i++)printf("*");
				for(int i = m; i < c-1; i++)printf(".");
				printf("c\n");
				continue;
			}
			if(c == 1){
				for(int i = 0; i < m; i++)printf("*\n");
				for(int i = m; i < r-1; i++)printf(".\n");
				printf("c\n");
				continue;
			}
		}
		if(r*c-m == 1){
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					if(i == 0 && j == 0)printf("c");
					else printf("*");
				}
				printf("\n");
			}
			continue;
		}
		ms = 0;
		if(!solve(0)){
			printf("Impossible\n");
		}
		else{
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					if(b[i]>j)printf("*");
					else if(i == r-1 && j == c-1) printf("c");
					else printf(".");
				}
				printf("\n");
			}
		}
	}
	return 0;
}