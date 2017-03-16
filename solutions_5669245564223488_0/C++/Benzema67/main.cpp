#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main(){
	string str[110];
	int T;
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b.txt", "w", stdout);
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			cin >> str[i];
		}
		int a[15];
		for(int i = 0; i < n; i++) a[i] = i;
		bool vis[30];
		bool flag;
		int ans = 0;
		do{
			string tmp = "";
			for(int i = 0; i < n; i++) tmp += str[a[i]];
			memset(vis, 0, sizeof(vis));
			flag = 1;
			int len = tmp.length();
			for(int i = 0; i < len; i++) {
				if(!vis[tmp[i] - 'a'])
					vis[tmp[i] - 'a'] = 1;
				else{
					if(tmp[i - 1] != tmp[i]){
						flag = 0;
						break;
					}
				}
			}
			if(flag) ans++;
		}while(next_permutation(a, a + n));
		printf("Case #%d: %d\n", t + 1, ans);
	}
}
