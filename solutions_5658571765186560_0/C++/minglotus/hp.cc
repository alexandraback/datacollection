#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
const int MAX = 5;
int table[MAX][MAX][MAX];
char name[2][10];
int main(){
	memset(name, 0, sizeof(name));
	strcpy(name[0],"RICHARD");
	strcpy(name[1],"GABRIEL");
	for(int i = 0; i < MAX; ++i){
		for(int j = 0; j < MAX; ++j){
			table[1][i][j] = 1;
		}
	}
	for(int i = 1; i < MAX; ++i){
		for(int j = 1; j < MAX; ++j){
			int sq = i * j;
			if(sq & 1){//odd numbers
				table[2][i][j] = 0;
			}
			else{
				table[2][i][j] = 1;
			}
		}
	}
	for(int i = 1; i < MAX; ++i){
		for(int j = 1; j < MAX; ++j){
			int sq = i * j;
			if(sq % 3 != 0){
				table[3][i][j] = 0;
				continue;
			}
			int cnt = sq / 3;
			if(cnt ==  1){//odd multiples of 3
				table[3][i][j] = 0;
			}
			else{
				table[3][i][j] = 1;
			}
		}
	}
	for(int i = 1; i < MAX; ++i){
		for(int j = 1; j < MAX; ++j){
			int sq = i * j;
			if(sq % 4 != 0){
				table[4][i][j] = 0;
				continue;
			}
			if(i < 4 &&  j < 4){
				table[4][i][j] = 0;
				continue;
			}
			if(sq == 4 || sq == 8){
				table[4][i][j] = 0;
				continue;
			}
			if(sq == 12){
				int mmin = min(i, j);
				int mmax = max(i, j);
				if(mmin == 3 && mmax == 4){
					table[4][i][j] = 1;
				}
				else{
					table[4][i][j] = 0;
				}
				continue;
			}
			if(sq == 16){
				int mmin = min(i, j);
				if(mmin == 4){
					table[4][i][j] = 1;
				}
				else{
					table[4][i][j] = 0;
				}
			}
		}
	}
	int x, r, c, t, ks = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d",&x,&r,&c);
		printf("Case #%d: %s\n", ks++, name[table[x][r][c]]);
	}
	return 0;
}
