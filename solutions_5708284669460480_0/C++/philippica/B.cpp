
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;

int T,K,S,L;
char key[110],tar[110];
char s[110];
int tmax,cnt,ans;

int Cal(){
	int res = 0;
	for(int i = 1; i <= S; ++i){
		if(i + L - 1 > S) break;
		int flag = 1;
		for(int j = i; j <= i + L - 1; ++j)
			if(s[j] != tar[j - i + 1]){
				flag = 0;
				break;
			}
		res += flag;
	}
	return res;
}

void Dfs(int p){
	if(p > S){
		cnt++;
		int res = Cal();
		ans += res;
		tmax = max(tmax,res);
		return;
	}
	for(int i = 1; i <= K; ++i){
		s[p] = key[i];
		Dfs(p + 1);
	}
}

int main(){
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d%d%d",&K,&L,&S);
		scanf("%s",key + 1);
		scanf("%s",tar + 1);
		ans = 0;
		cnt = 0;
		tmax = 0;
		Dfs(1);
		printf("Case #%d: %.6f\n",tt,tmax - (double)ans / cnt);
	}
	return 0;
}


