#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <numeric>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define SIZEOF(a) (sizeof(a)/sizeof((a)[0]))

void Solve()
{
	int R, C, M; cin >> R >> C >> M;
	if(M==0){
		FOR(i,R){ FOR(j,C)
				if(i==0 && j==0) printf("c");
				else printf(".");
			printf("\n");
		}return;
	}
	if(R*C == M+1){
		FOR(i,R){ FOR(j,C)
				if(i==0 && j==0) printf("c");
				else printf("*");
			printf("\n");
		}return;
	}
	if(R==1){
		FOR(i,C)
			if(M>0){		printf("*"); --M;}
			else if(i+1==C)	printf("c");
			else			printf(".");
		printf("\n");
		return;
	}
	if(C==1){
		FOR(i,R)
			if(M>0){		printf("*\n"); --M;}
			else if(i+1==R)	printf("c\n");
			else			printf(".\n");
		return;
	}
	if(R==2 && C==2 && (M==1 || M==2)){
		printf("Impossible\n");
		return;
	}

	if(R>2 && C>2 && M<=(R-2)*(C-2)){
		FOR(i,R){
			FOR(j,C){
				if(M>0 && i+2<R && j+2<C){
					printf("*"); --M;
				}else if(i+1==R && j+1==C) printf("c");
				else printf(".");
			}
			printf("\n");
		}
		return;
	}

	if(M>0 && M%C==0 && (M/C)+2<=R){
		FOR(i,R){
			FOR(j,C){
				if(M>0){
					printf("*"); --M;
				}else if(i+1==R && j+1==C) printf("c");
				else printf(".");
			}
			printf("\n");
		}
		return;
	}

	if(M>0 && M%R==0 && (M/R)+2<=C){
		char a[R][C];
		FOR(j,C){
			FOR(i,R){
				if(M>0){
					a[i][j] = '*'; --M;
				}else if(i+1==R && j+1==C) a[i][j] = 'c';
				else a[i][j] = '.';
			}
		}
		FOR(i,R){
			FOR(j,C){
				printf("%c", a[i][j]);
			}
			printf("\n");
		}
		return;
	}

	if(R>=2 && C>=2){	
		vector<vector<int> > g(R, vector<int>(C, 2));
		queue<int> q;
		q.push(0);q.push(0);
		int zeros = 0;
		int ones = 1;
		while(!q.empty()){
			const int i = q.front(); q.pop();
			const int j = q.front(); q.pop();
			int newZeros = zeros+1;
			int newOnes = ones-1;
			for(int di=-1; di<=1; ++di)
			for(int dj=-1; dj<=1; ++dj)
			{
				if(di==0 && dj==0) continue;
				const int ii = i+di;
				const int jj = j+dj;
				if(ii<0 || ii>=R || jj<0 || jj>=C) continue;
				if(g[ii][jj]==2) ++newOnes;
			}
			if(newZeros + newOnes + M > R*C) continue;

			zeros = newZeros;
			ones = newOnes;
			g[i][j] = 0;
			for(int di=-1; di<=1; ++di)
			for(int dj=-1; dj<=1; ++dj)
			{
				if(di==0 && dj==0) continue;
				const int ii = i+di;
				const int jj = j+dj;
				if(ii<0 || ii>=R || jj<0 || jj>=C) continue;
				if(g[ii][jj]==2) g[ii][jj] = 1;
			}

			if(newZeros + newOnes + M == R*C){
				FOR(i,R){
					FOR(j,C){
						if(i==0&&j==0) printf("c");
						else if(g[i][j]==2) printf("*");
						else printf(".");
					}
					printf("\n");
				}
				return;
			}

			const int d[2][2] = {{1,0},{0,1}};
			FOR(di,2){
				const int ii = i + d[di][0];
				const int jj = j + d[di][1];
				if(ii<0 || ii>=R || jj<0 || jj>=C) continue;
				if(g[ii][jj]!=1) continue;
				q.push(ii);q.push(jj);
			}
		}
	}

	printf("Impossible\n");
}

int main()
{
	int T; cin >> T;
	FOR(t, T){
		cout << "Case #" << t+1 << ": " << endl;
		Solve();
	}
	return 0;
}
