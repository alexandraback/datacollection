#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int t, n, noof[130], conut, in[130], out[130], used[130];
bool tt[130];
long long ans;
bool visited[130];


void dfs(int x, bool dir){
	if(visited[x]) return;
	visited[x] = true;
	if(dir){
		if(in[x] != 0){
			int nx = in[x];
			if(visited[nx]) return;
			dfs(nx, true);
		}
	}
	else{
		if(out[x] != 0){
			int nx = out[x];
			if(visited[nx]) return;
			dfs(nx, false);
		}
	}
	return;
}


void start(int x){
	//cout << "testing " << (char)x-'a' << endl;
	if(visited[x]) return;
	visited[x] = true;
	dfs(in[x], true);
	dfs(out[x], false);
	return;
}

int main(){
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	scanf("%d", &t);
	for(int a = 1; a <= t; ++a){
		ans = 1;
		memset(noof, 0, sizeof noof);
		memset(used, 0, sizeof used);
		memset(in, 0, sizeof in);
		memset(out, 0, sizeof out);
		memset(visited, false, sizeof visited);
		scanf("%d", &n);
		string i;
		bool gg = false;
		for(int b = 0; b < n; ++b){
			cin >> i;
			memset(tt, false, sizeof tt);
			char check = i[0];
			tt[check] = true;
			used[check] = true;
			bool pass = true;
			for(int c = 1; c < i.length(); ++c){
				used[i[c]] = true;
				if(check != i[c]){
					pass = false;
				}
				if(i[c-1] != i[c]){
					char j = i[c-1], k = i[c];
					if(tt[k]) gg = true;
					if(in[k] == 0) in[k] = j;
					else{
						gg = true;
					}
					if(out[j] == 0) out[j] = k;
					else{
						gg = true;
					}
				}
				tt[i[c]] = true;
			}
			if(pass){
				++noof[check];
			}
		}
		conut = 0;
		for(int b = 'a'; b <= 'z'; ++b){
			if(out[b] != 0 && in[b] == 0) ++conut;
			if(used[b] && out[b] == 0 && in[b] == 0) ++conut;
		}
		if(conut == 0) ans = 0;
		while(conut > 1){
			ans = (long long)conut * ans;
			ans %= 1000000007;
			--conut;
		}
		for(int b = 'a'; b <= 'z'; ++b){
			if(!used[b]) continue;
			while(noof[b] > 1){
				ans = (long long)noof[b] * ans;
				ans %= 1000000007;
				--noof[b];
			}
		}
		if(gg) ans = 0;
		printf("Case #%d: %lld\n", a, ans);
	}
	return 0;
}
