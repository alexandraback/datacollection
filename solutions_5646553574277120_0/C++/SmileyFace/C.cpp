#include <bits/stdc++.h>
using namespace std;

int tc;
int c, d, v;
set<int> myset;
int used[10000];
int coins[10000];
int last = 1;
int ans = 0;

void pc(int a){
	myset.clear();
	for (int i = 0; i <= v; i++){
		if (used[i] == -1) continue;
		if (i + a > v) continue;
		myset.insert(i + a);
	}
	for (auto it = myset.begin(); it != myset.end(); it++){
		used[*it] = 1;
	}
	myset.clear();
	
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d",&tc);
	
	for(int tcno=1;tcno<=tc;tcno++){
		scanf("%d%d%d",&c,&d,&v);
		memset(used, -1, sizeof(used));
		memset(coins, -1, sizeof(coins));
		used[0] = 1;last = 100000000;ans = 0;
		for (int j = 0; j < d; j++){
			int tp;
			scanf("%d",&tp);pc(tp);coins[tp] = 1;
		}
		for (int j = 0; j <= v; j++){
			if (used[j] == -1) {last = j;break;}
		}
		while (last <= v){
			pc(last);ans++;last = 100000000;
			for (int j = 0; j <= v; j++){
				if (used[j] == -1) {last = j;break;}
			}	
		}
		printf("Case #%d: %d\n",tcno,ans);
	}
}
