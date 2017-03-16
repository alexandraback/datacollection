#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int sqr(int a[], int la, int c[]){
	int lc = la + la;
	fill(c, c + lc, 0);
	for(int i = 0;i < la; ++i){
		for(int j = 0;j < la; ++j){
			c[i + j] += a[i] * a[j];
		}
	}
	for(int i = 0;i < lc; ++i) if(c[i] >= 10){
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	while(c[lc - 1] == 0) --lc;
	return lc;
}

int x[105], y[105], z[105];
vector<pair<int, string> > ans;
void dfs(int a, int b, int rem){
	if(a > b){
		int n = sqr(y, a + b + 1, z);
		for(int i = 0, j = n - 1;i < j; ++i, -- j){
			if(z[i] != z[j]) return;
		}
		string s;
		s.reserve(n);
		for(int i = n - 1; i >= 0; --i){
			s += char(z[i] + '0');
		}
		ans.push_back(make_pair(s.length(), s));
		return;
	}
	for(int i = (a == 0 ? 1 : 0);i <= 3; ++i){
		y[a] = y[b] = i;
		int cost = i * i * (a == b ? 1 : 2);
		if(cost <= rem) dfs(a + 1, b - 1, rem - cost);
	}
}

int main(){
	for(int n = 1; n <= 51; ++n){
		dfs(0, n - 1, 9);
	}
	//printf("%d %d\n", ans.back().first, ans.back().second.length());
	
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int TT;
	scanf("%d", &TT);
	char a[105], b[105];
	for(int cas = 1;cas <= TT; ++cas){
		scanf("%s %s", a, b);
		pair<int, string> keyA = make_pair(strlen(a), string(a));
		pair<int, string> keyB = make_pair(strlen(b), string(b));
		int count = upper_bound(ans.begin(), ans.end(), keyB) - lower_bound(ans.begin(), ans.end(), keyA);
		printf("Case #%d: %d\n", cas, count);
	}
	return 0;
}