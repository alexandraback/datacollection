#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 100;
const int MAXVAL = 2500 + 10;

int sz = 0, cc;
int cnt[MAXVAL], ans[MAXN], sec[MAXN * MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	for (int i = 1; i <= te; i++){
		memset(cnt, 0, sizeof(cnt));
		cout << "Case #" << i << ": ";
		int n;	cin >> n;
		sz = cc = 0;
		for (int j = 0; j < 2 * n - 1; j++)
			for (int w = 0; w < n; w++){
				int x;	cin >> x;
				cnt[x]++;
				sec[sz++] = x;
			}
		sort(sec, sec + sz);
		sz = unique(sec, sec + sz) - sec;
		for (int j = 0; j < sz; j++)
			if (cnt[sec[j]]%2)	ans[cc++] = sec[j];
		for (int j = 0; j < n; j++)
			cout << ans[j] << " ";
		cout << "\n";
	}
	return 0;
}	
