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

#define maxm 5010
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
int cnt[maxm];

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt", "r", stdin);
	freopen("b2.in","r",stdin);
	freopen("out.txt","w",stdout);

	scanf("%d", &test);

	while (test--){
		
		memset(cnt, 0, sizeof(cnt));

		scanf("%d", &n);
		
		for (i = 1; i < 2 * n; i++){
			for (j = 1; j <= n; j++){
				scanf("%d", &k);
				cnt[k]++;
			}
		}

		vector<int>ans; 

		for (i = 0; i <= 3000; i++){
			if (cnt[i] % 2){
				ans.push_back(i);
			}
		}
		sort(ans.begin(), ans.end());

		printf("Case #%d:", t++);
		for (i = 0; i < ans.size(); i++){
			printf(" %d", ans[i]);
		}
		puts("");
	}

	return 0;
}

