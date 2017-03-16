#include <stdio.h>

int T;

void solve(int k) {
	int r, c, m;

	char answer[99][99];
	scanf("%d %d %d", &r, &c, &m);
	m=r*c-m;

	int possible=0;

	if(c>=3) {
		if(r==1) {
			for(int i=1; i<=c; i++) {
				if(i<=m) answer[1][i]='.';
				if(i> m) answer[1][i]='*';
			}
			answer[1][1]='c';
			possible=1;
		}
		if(r==2) {
			if(m==1) {
				for(int i=1; i<=r; i++)
					for(int j=1; j<=c; j++)
						answer[i][j]='*';
				answer[1][1]='c';
				possible=1;
			}
			if(m%2==0 && m>=4) {
				for(int i=1; i<=c; i++) {
					if(i*r<=m) for(int j=1; j<=r; j++)
						answer[j][i]='.';
					if(i*r>	m) for(int j=1; j<=r; j++)
						answer[j][i]='*';
				}
				answer[1][1]='c';
				possible=1;
			}
			if(m==2 && c==1) {
				answer[1][1]='c';
				answer[2][1]='.';
				possible=1;
			}
		}
		if(r>=3) {
			if(m>=2*c+2) {
				for(int i=1; i<=r; i++)
					for(int j=1; j<=c; j++) {
						if((i-1)*c+j<=m) answer[i][j]='.';
						if((i-1)*c+j> m) answer[i][j]='*';
					}
				answer[1][1]='c';
				if(m%c==1) {
					answer[m/c][c]='*';
					answer[m/c+1][2]='.';
				}
				possible=1;
			}else{
				if(m==(2*c+1) && c>=4) {
					for(int i=1; i<=r; i++)
						for(int j=1; j<=c; j++) {
							if((i-1)*c+j<=m) answer[i][j]='.';
							if((i-1)*c+j> m) answer[i][j]='*';
						}
					answer[1][1]='c';
					answer[m/c  ][c]='*';
					answer[m/c-1][c]='*';
					answer[m/c+1][2]='.';
					answer[m/c+1][3]='.';
					possible=1;
				}
				if(m>=4 && m<=2*c && m%2==0) {
					for(int i=1; i<=r; i++)
						for(int j=1; j<=c; j++)
							answer[i][j]='*';
					for(int j=1; j<=m/2; j++)
						answer[1][j]=answer[2][j]='.';
					answer[1][1]='c';
					possible=1;
				}
				if(m>=9 && m<=2*c && m%2==1) {
					for(int i=1; i<=r; i++)
						for(int j=1; j<=c; j++)
							answer[i][j]='*';
					for(int j=1; j<=(m-3)/2; j++)
						answer[1][j]=answer[2][j]='.';
					answer[1][1]='c';
					answer[3][1]=answer[3][2]=answer[3][3]='.';
					possible=1;
				}
				if(m==1) {
					for(int i=1; i<=r; i++)
						for(int j=1; j<=c; j++)
							answer[i][j]='*';
					answer[1][1]='c';
					possible=1;

				}
			}
		}
	}else{
		if(c==1) {
			for(int i=1; i<=r; i++) {
				if(i<=m) answer[i][1]='.';
				if(i> m) answer[i][1]='*';
			}
			answer[1][1]='c';
			possible=1;
		}
		if(c==2) {
			if(m==1) {
				for(int i=1; i<=r; i++)
					for(int j=1; j<=c; j++)
						answer[i][j]='*';
				answer[1][1]='c';
				possible=1;
			}
			if(m%2==0 && m>=4) {
				for(int i=1; i<=r; i++) {
					if(i*c<=m) for(int j=1; j<=c; j++)
						answer[i][j]='.';
					if(i*c>	m) for(int j=1; j<=c; j++)
						answer[i][j]='*';
				}
				answer[1][1]='c';
				possible=1;
			}
			if(m==2 && r==1) {
				answer[1][1]='c';
				answer[1][2]='.';
				possible=1;
			}
		}
	}

	if(possible) {
//		printf("%d %d %d>\n", r, c, m);

		printf("Case #%d:\n", k);
		for(int i=1; i<=r; i++) {
			for(int j=1; j<=c; j++)
				printf("%c", answer[i][j]);
			printf("\n");

		}

	}else {
		printf("Case #%d:\n", k);
		printf("Impossible\n");
	}
}

int main() {
	freopen("input", "r", stdin);
//	freopen("output", "w", stdout);
	scanf("%d", &T);
	for(int i=1; i<=T; i++)
		solve(i);
	return 0;
}
