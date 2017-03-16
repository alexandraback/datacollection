#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define lowbit(x) (x & (-x))
typedef long long LL;
int a[10];
bool vis[11];
int n, ans;
int cases = 1;
char c[10000];
string A, B, s[11];
bool tt[26];

void gao(){
	int i = 0;
	B = "";
	for(int i = 0; i < n; ++i){
   		B += s[a[i]];
	}
	memset(tt, 0, sizeof(tt));
	int len = B.size();

	for(int i = 0; i < len;){
		int j = i;
		if(tt[B[i] - 'a'] == 1) return ;
		tt[B[i] - 'a'] = 1;
		while(B[i] == B[j]){
			++i;
		}
		if(i == len) break;
	}
	++ans;
}

void dfs(int k){
	if(k == n){
		gao();
		return ;
	}

	for(int i = 0; i < n; ++i){
		if(!vis[i]){
			a[k] = i;
			vis[i] = 1;
			dfs(k + 1);
			vis[i] = 0;
		}
	}
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
	//	string s;
		scanf("%d", &n);
		int tmp = n, j = 0, t = 0;
		while(tmp--){
			cin >> s[t];
			++t;
		}
		ans = 0;
		memset(vis, 0, sizeof(vis));
		dfs(0);
		printf("Case #%d: %d\n", cases++, ans);
	}
	return 0;
}
