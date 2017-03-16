#include<cstdio>

int T;
int R,C,M;
char map[50][50];
int nmap[50][50];

bool process(){
	int i,j;
	int r = R, c = C, m = M;

	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			map[i][j] = '.';
		}
	}

	if(m == 0){
		map[0][0] = 'c';
		return true;
	}
	if(R == 1){
		for(i=0;i<m;i++){
			map[0][i] = '*';
		}
		map[0][C-1] = 'c';
		return true;
	}
	if(C == 1){
		for(i=0;i<m;i++){
			map[i][0] = '*';
		}
		map[R-1][0] = 'c';
		return true;
	}

	while(m != 0){
		if(r > c){
			if(m >= c){
				for(i=0;i<c;i++){
					map[r-1][i] = '*';
				}
				r--;
				m = m - c;
			}
			else break;
		}
		else{
			if(m >= r){
				for(i=0;i<r;i++){
					map[i][c-1] = '*';
				}
				c--;
				m = m - r;
			}
			else break;
		}
	}

	if(r == 1 && c == 1){
		map[0][0] = 'c';
		return true;
	}

	if(r == 1 || c == 1){
		return false;
	}

	if((r == 2 || c == 2) && m == 1){
		return false;
	}

	if(r == 3 && c == 3 && m == 2){
		return false;
	}

	for(i=r-1;i>=2;i--){
		if(m != 0){
			map[i][c-1] = '*';
			m--;
		}
	}
	for(i=c-2;i>=2;i--){
		if(m != 0){
			map[r-1][i] = '*';
			m--;
		}
	}

	map[0][0] = 'c';
	return true;
}

int main(void){
	int i,j,t;
	bool rc;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d %d %d",&R,&C,&M);
		printf("Case #%d:\n", t);
		rc = process();
		if(!rc){
			printf("Impossible\n");
		}
		else{
			for(i=0;i<R;i++){
				for(j=0;j<C;j++){
					printf("%c", map[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}