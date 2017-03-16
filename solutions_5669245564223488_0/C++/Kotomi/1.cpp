#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

string str[110];
int f[110];
int vis[110];

int main()
{	 
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			string temp;
			cin >> temp;
			str[i] = "";
			str[i] += temp[0];
			for (int j = 1; j < temp.length(); j++){
				if (temp[j] != str[i][str[i].length() - 1]) 
					str[i] += temp[j];
			}
		}
		for (int i = 0; i < n; i++) f[i] = i;
		int ans = 0;
		do{
			string now = "";
			for (int i = 0; i < n; i++){
				now += str[f[i]];
			}
			memset(vis, 0, sizeof(vis));
			int tag = 1;
			vis[int(now[0] - 'a')] = 1;
			for (int i = 1; i < now.length(); i++){
				if (now[i] == now[i - 1]) continue;
				if (!vis[int(now[i] - 'a')]){
					vis[int(now[i] - 'a')] = 1;
				}
				else{
					tag = 0;
					break;
				}
			}
			if (tag) ans++;
		}while(next_permutation(f, f + n));
		printf("Case #%d: %d\n", cas, ans);
	}
    return 0;
}
