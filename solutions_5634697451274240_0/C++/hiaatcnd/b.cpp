#include <bits/stdc++.h>
using namespace std;

int T, n, ans;
char s[110];
bool a[110], b[110];

bool check(){
	for(int i = 0; i < n; i++) if(!a[i]) return 0;
	return 1;
}

void change(int m){
	memcpy(b, a, sizeof(a));
	for(int i = 0; i < m; i++)
		a[i] = 1 - b[m - i - 1];
}

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		printf("Case #%d: ", t);
		scanf("%s", s); n = strlen(s), ans = 0;
		for(int i = 0; i < n; i++) a[i] = s[i] == '+';
		while(!check()){
			int i = 0; for(; a[i] == a[0] && i < n; i++);
			change(i);
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
