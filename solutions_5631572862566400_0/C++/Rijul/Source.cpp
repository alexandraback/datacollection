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

#define maxm 12
#define maxn ((1<<maxm)+2)
#define inf (1<<29)
#define ii int

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
int bff[maxm], col[maxm];
bool flag[maxm];

int dp[maxm][maxm][3][maxn];

int cal(int start, int curr, bool satisfy, int taken){

	int ret = 0;
	int i;

	if (dp[start][curr][satisfy][taken] != -1) return dp[start][curr][satisfy][taken];


	if (satisfy){
		ret = 1; 
		for (i = 1; i <= n; i++){
			if (chck(taken, i)) continue;
			bool n_s = (bff[i] == curr);
			int ret1 = cal(start, i, n_s, on(taken, i));
			if (ret1){
				ret = maxi(ret, ret1 + 1);
			}
		}
	}
	else{
		int nxt = bff[curr];
		bool n_s = (bff[nxt] == curr);
		if (nxt == start){
			ret = 1;
		}
		else{
			if (!chck(taken, nxt)){
				int ret1 = cal(start, nxt, n_s, on(taken, nxt));
				if (ret1){
					ret = ret1 + 1;
				}
			}
		}
	}

	return dp[start][curr][satisfy][taken] = ret;
	
}

int findAns(){

	int ret = 0;
	memset(flag, 0, sizeof(flag));
	memset(dp, -1, sizeof(dp));

	int no_of_two = 0;
	for (int i = 1; i <= n; i++){
		if (bff[bff[i]] == i) no_of_two++;
	}

	ret = maxi(ret, no_of_two);
	for (int i = 1; i <= n; i++){
		ret = maxi(ret, cal(i, i, 0, on(0,i)));
	}

	return ret;
}

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt", "r", stdin);
	freopen("c1.in","r",stdin);
	freopen("out.txt","w",stdout);

	scanf("%d", &test);

	while (test--){
		
		scanf("%d", &n);

		for (i = 1; i <= n; i++){
			scanf("%d", &bff[i]);
		}

		printf("Case #%d: %d\n", t++, findAns());
	}

	return 0;
}

