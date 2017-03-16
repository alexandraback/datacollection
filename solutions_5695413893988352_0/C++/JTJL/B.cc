#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll ans, pp, qq;

ll pw[20];
int l;

char s[100], t[100];

ll _abs(ll p){
	return p < 0 ? -p : p;
}

void dfs(int dep, ll p, ll q){
	if (dep >= l){
		if (_abs(p - q) < ans){
			ans = _abs(p - q);
			pp = p, qq = q;
		}
	}
	else{
		if (ans < (_abs(p - q) - 1) * pw[l - dep])
			return ;
		if (s[dep] == '?' && t[dep] == '?'){
			dfs(dep + 1, p * 10, q * 10);
			dfs(dep + 1, p * 10, q * 10 + 1);
			dfs(dep + 1, p * 10, q * 10 + 9);
			dfs(dep + 1, p * 10 + 1, q * 10);
			dfs(dep + 1, p * 10 + 9, q * 10);
		}
		else{
			if (s[dep] == '?'){
				int tmp = t[dep] - '0';
				if (tmp == 0){
					dfs(dep + 1, p * 10, q * 10 + tmp);
					dfs(dep + 1, p * 10 + 1, q * 10 + tmp);
					dfs(dep + 1, p * 10 + 9, q * 10 + tmp);
				}
				else if (tmp == 9){
					dfs(dep + 1, p * 10, q * 10 + tmp);
					dfs(dep + 1, p * 10 + 8, q * 10 + tmp);
					dfs(dep + 1, p * 10 + 9, q * 10 + tmp);
				}
				else{
					if (tmp != 1) dfs(dep + 1, p * 10, q * 10 + tmp);
					dfs(dep + 1, p * 10 + tmp - 1, q * 10 + tmp);
					dfs(dep + 1, p * 10 + tmp, q * 10 + tmp);
					dfs(dep + 1, p * 10 + tmp + 1, q * 10 + tmp);
					if (tmp != 8) dfs(dep + 1, p * 10 + 9, q * 10 + tmp);
				}
			}
			else if (t[dep] == '?'){
				int tmp = s[dep] - '0';
				if (tmp == 0){
					dfs(dep + 1, p * 10 + tmp, q * 10);
					dfs(dep + 1, p * 10 + tmp, q * 10 + 1);
					dfs(dep + 1, p * 10 + tmp, q * 10 + 9);
				}
				else if (tmp == 9){
					dfs(dep + 1, p * 10 + tmp, q * 10);
					dfs(dep + 1, p * 10 + tmp, q * 10 + 8);
					dfs(dep + 1, p * 10 + tmp, q * 10 + 9);
				}
				else{
					if (tmp != 1) dfs(dep + 1, p * 10 + tmp, q * 10);
					dfs(dep + 1, p * 10 + tmp, q * 10 + tmp - 1);
					dfs(dep + 1, p * 10 + tmp, q * 10 + tmp);
					dfs(dep + 1, p * 10 + tmp, q * 10 + tmp + 1);
					if (tmp != 8) dfs(dep + 1, p * 10 + tmp, q * 10 + 9);
				}
			}
			else
				dfs(dep + 1, p * 10 + s[dep] - '0', q * 10 + t[dep] - '0');
		}
	}
}

int main(){
	freopen("Bs.in", "r", stdin);
	freopen("Bs.out", "w", stdout);
	int T;
	cin>>T;
	pw[0] = 1;
	for(int i = 1; i <= 18; i++)
		pw[i] = pw[i-1] * 10;
	for(int o = 1; o <= T; o++){
		scanf("%s%s", s, t);
		l = strlen(s);
		ans = pw[18];
		pp = qq = 0;
		dfs(0, 0, 0);
		printf("Case #%d: %0*lld %0*lld\n", o, l, pp, l, qq);
	}
	return 0;
}
