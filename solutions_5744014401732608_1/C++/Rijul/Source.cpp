/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-09-12
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

#define maxm 55
#define maxn  60
#define inf (1<<30)
#define ii __int64

#define pi  acos(-1.0)
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)

#define pii pair<int,int>
#define mp  make_pair
#define uu first
#define vv second

ii on(ii n, ii k){ return (n | (1 << k)); }
ii off(ii n, ii k){ return (n - (n&(1 << k))); }
bool chck(ii n, ii k){ return (n&(1 << k)); }

ii mini(ii a, ii b){ if (a<b) return a;  return b; }
ii maxi(ii a, ii b){ if (a>b) return a;  return b; }

int n;
ii m;
ii cnt[30];
int mat[maxm][maxm];

bool findAns1(int row, ii rem){

	if (rem == 0) return true;
	for (int i = row-1; i >= 1; i--){
		if (rem + cnt[i] <= 0){
			mat[i][n] = 0;
			return findAns1(i, rem + cnt[i]);
		}
	}
	return false;
}

bool findAns(int row, int col, int row2, ii rem){

	if (rem == 0) return true;
	if (rem < 0){
		if (row2 >= n) return false;
		return findAns1(n, rem);
		//mat[row2][n] = 0;
		//return findAns(row, col, row2 + 1, rem + cnt[row2]);
	}
	if (row >= n){
		return false;
	}
	if (col >= n){
		return findAns(row + 1, row + 2, row2, rem);
	}
	mat[row][col] = 1;
	cnt[col]+=cnt[row];
	findAns(row, col + 1, row2, rem - cnt[row]);

}

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt", "r", stdin);
	freopen("b2.in", "r", stdin);
	freopen("outb2.txt", "w", stdout);

	scanf("%d", &test);
	
	while (test--){
				
		scanf("%d %I64d", &n, &m);

		memset(mat, 0, sizeof(mat));
		memset(cnt, 0, sizeof(cnt));

		for (int i = 1; i < n; i++){
			mat[i][n] = 1;
		}
		cnt[1] = 1;

		printf("Case #%d: ", t++);
		if (findAns(1, 2, 1, m - 1)){
			puts("POSSIBLE");
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					printf("%d", mat[i][j]);
				}
				puts("");
			}
		}
		else{
			puts("IMPOSSIBLE");
		}

	}
	

	return 0;
}