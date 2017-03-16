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

map<pii, int>mapp1,mapp2,mapp3;
int J, P, S, K;
int arr[10];
int curr[5];
vector<int>v[100000];
int cnt=0;

void backTrack(int ind,int curr[]){
	
	if (ind == 3){
		pii p1 = mp(curr[0], curr[1]);
		mapp1[p1]++;
		if (mapp1[p1] > K){
			mapp1[p1]--;
			return;
		}

		pii p2 = mp(curr[0], curr[2]);
		mapp2[p2]++;
		if (mapp2[p2] > K){
			mapp1[p1]--;
			mapp2[p2]--;
			return;
		}

		pii p3 = mp(curr[1], curr[2]);
		mapp3[p3]++;
		if (mapp3[p3] > K){
			mapp1[p1]--;
			mapp2[p2]--;
			mapp3[p3]--;
			return;
		}
		v[cnt].push_back(curr[0]);
		v[cnt].push_back(curr[1]);
		v[cnt].push_back(curr[2]);
		cnt++;
		return;
	}

	for (int i = 1; i <= arr[ind]; i++){
		curr[ind] = i;
		backTrack(ind + 1, curr);
	}
}

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt", "r", stdin);
	freopen("c1.in", "r", stdin);
	freopen("outc1.txt", "w", stdout);

	scanf("%d", &test);
	
	while (test--){
				
		scanf("%d %d %d %d", &J, &P, &S, &K);

		for (int i = 0; i <= cnt; i++){
			v[i].clear();
		}

		arr[0] = J;
		arr[1] = P;
		arr[2] = S;

		mapp1.clear();
		mapp2.clear();
		mapp3.clear();
		
		cnt = 0;
		backTrack(0, curr);

		printf("Case #%d: %d\n", t++, cnt);
		for (int i = 0; i < cnt; i++){
			printf("%d %d %d\n", v[i][0], v[i][1], v[i][2]);
		}
	}
	

	return 0;
}