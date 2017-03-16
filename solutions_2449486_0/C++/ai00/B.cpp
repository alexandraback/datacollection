#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define  MAXN  100
int c[MAXN], r[MAXN];
int f[MAXN][MAXN];
bool ai00(){
	int n, m;
	scanf("%d %d ", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d ", &f[i][j]);
	for (int i = 0; i < n; ++i){
		int ans = 0;
		for (int j = 0; j < m; ++j)
			ans = max(ans, f[i][j]);
		r[i] = ans;
		//cout<<i<<' '<<r[i]<<endl;
	}
	for (int j = 0; j < m; ++j){
		int ans = 0;
		for (int i = 0; i < n; ++i)
			ans = max(ans, f[i][j]);
		c[j] = ans;
		//cout<<j<<' '<<c[j]<<endl;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (f[i][j] != min(r[i], c[j])) return false;
	return true;
}
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t, tt;
	for (scanf("%d ", &t), tt = 0; tt < t; ++tt){
		cout<<"Case #"<<tt + 1<<": "<<(ai00()?"YES":"NO")<<endl;
	}
}
