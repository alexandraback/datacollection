#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
#define LL long long
vector <LL> v;
char s1[100],s2[100];
LL n,m;
bool check(char s[]) {
	int len = strlen(s);
	int mid = len/2 -1;
	for(int i = 0; i <= mid; i++) {
		if(s[i] != s[len - 1 - i])
			return false;
	}
	return true;
}
void init() {
	for(LL i = 1; i <= 10000000; i++) {
		sprintf(s1,"%I64d",i);
		sprintf(s2,"%I64d",i*i);
		if(check(s1)&& check(s2))
			v.push_back(i*i);
	}
}
int main () {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	init();
	int T;
	scanf("%d",&T);
	for(int cas = 1; cas <= T; cas++) {	
		cin >> n >> m;
		int ans = 0;
		for(int i = 0; i < v.size(); i++) {
			if(v[i] >= n &&v[i] <= m)
				ans++;
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}