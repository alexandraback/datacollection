#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 75;

char cnt[MAXN][MAXN];

void gen(int x, int y, int n, int m){
	
	
	}

int main(){	
	int testcases;
	scanf("%d", &testcases);
	
	for(int test = 0; test < testcases; test++){
		printf("Case #%d:\n", test + 1);
		int n, m, mines;
		scanf("%d%d%d", &n, &m, &mines);
		
		fill((char*)cnt, (char*)cnt + MAXN*MAXN, '*');
		
		int to_fill = n*m - mines;
		
		
		int u = -1, w = -1;
		
		if(to_fill == 1){
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					cnt[i][j] = '*';
			cnt[0][0] = 'c';
					
			for(int i = 0; i < n; i++, printf("\n"))
			for(int j = 0; j < m; j++)
				printf("%c", cnt[i][j]);
			continue;
			}
		
		if(n == 1){
			for(int i = 0; i < m; i++)
				if(to_fill > 0 && cnt[0][i] == '*')
					cnt[0][i] = '.', to_fill--;
			cnt[0][0] = 'c';
			for(int i = 0; i < n; i++, printf("\n"))
			for(int j = 0; j < m; j++)
				printf("%c", cnt[i][j]);
			continue;
			}
		if(m == 1){
			for(int i = 0; i < n; i++)
				if(to_fill > 0 && cnt[i][0] == '*')
					cnt[i][0] = '.', to_fill--;
			cnt[0][0] = 'c';
			for(int i = 0; i < n; i++, printf("\n"))
			for(int j = 0; j < m; j++)
				printf("%c", cnt[i][j]);
			continue;
			}
		
		//~ cout << n << " " << m << endl;
		
		for(int i = 2; i <= n; i++)
			for(int j = 2; j <= m; j++)
				if( i*j >= to_fill && i*j - (i-2)*(j-2) <= to_fill)
					u = i, w = j, i = j = n+m;
		
		//~ cout << "OK...?" << endl;
		
		if(u == -1){
			printf("Impossible\n");
			continue;
			}
		
		for(int i = 0; i < u; i++){
			if(cnt[i][0] == '*')
					cnt[i][0] = '.', to_fill--;
			if(cnt[i][1] == '*')
					cnt[i][1] = '.', to_fill--;
				}
				
		for(int i = 0; i < w; i++){
			if(cnt[0][i] == '*')
					cnt[0][i] = '.', to_fill--;
			if(cnt[1][i] == '*')
					cnt[1][i] = '.', to_fill--;
				}
		
		for(int i = 2; i < u; i++)
			for(int j = 2; j < w; j++)
				if(to_fill > 0 && cnt[i][j] == '*')
					cnt[i][j] = '.', to_fill--;
				
		
		//~ cnt[0][0] = 'c', to_fill--;
		//~ if(n > 1) cnt[1][0] = '.', to_fill--;
		//~ if(m > 1) cnt[0][1] = '.', to_fill--;
		//~ if(m > 1 && n > 1) cnt[1][1] = '.', to_fill--;
		//~ 
		//~ if(to_fill < 0){
			//~ printf("Impossible\n");
			//~ continue;
			//~ }
		//~ 
		//~ gen(0, 0, n, m);
		
		//~ for(int k = 0; k < max(m,n); k++){
			//~ for(int i = 0; i < k; i++)
				//~ if(to_fill > 0 && i < n && k < m && cnt[i][k] == '*')
					//~ cnt[i][k] = '.', to_fill--;
			//~ for(int i = 0; i < k; i++)
				//~ if(to_fill > 0 && k < n && i < m && cnt[k][i] == '*')
					//~ cnt[k][i] = '.', to_fill--;
			//~ if(to_fill > 0 && k < n && k < m && cnt[k][k] == '*')
					//~ cnt[k][k] = '.', to_fill--;	
				//~ }
		cnt[0][0] = 'c';
		for(int i = 0; i < n; i++, printf("\n"))
			for(int j = 0; j < m; j++)
				printf("%c", cnt[i][j]);
		}
	
	return 0;
}
