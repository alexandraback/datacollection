#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>

#define lld long long
#define INF 210000000
#define eps 1e-8
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int, int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

using namespace std;
string z[51];
string ans;
string maxs;
int p[51];
int a[51][51];
int n;
int stk[200];

string cal(){
	int i, j;
	string t = z[p[0]];
	int now = p[0];
	int top = 0;
	stk[top++] = p[0];
	for(i = 1; i < n; i++){
		int ok = 0;
		if (a[p[i - 1]][p[i]] == 1) {ok = 1;} else{
			int o = stk[top - 1];
			while(top > 0) {
				if (a[o][p[i]]) {ok = 1; break;} else {top--; if (top>0)o = stk[top - 1];}
			}
		}
		if (!ok) return maxs;
		stk[top++] = p[i];
		t += z[p[i]];
	}
//	if (a[p[n - 1]][[p[0]] || a[p[0]][p[n - 1]])
	return t;
}
int main()
{
	int T, i, j, k,m,x,y ,cas = 0;
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin>>n>>m;
		ans = "";
		maxs = "";
		for(i = 1; i <= n; i++){
			cin>>z[i];
			ans += "aaaaa";
		}
		mem(a,0);
		for(i = 0; i < m; i++){
			cin>>x>>y;
			a[x][y] = 1;
			a[y][x] = 1;
		}
		maxs = ans;
		for(i = 0; i < n; i++)
			p[i] = i + 1;
		do{
			string tmp = ans.substr(0, 5);
			if (tmp < z[p[0]]) continue;
			string now =  cal();
//			cout<<now<<endl;
			if (now < ans) ans = now;
		}
		while (next_permutation(p,p + n));

		cout<<"Case #"<<++cas<<": "<<ans<<endl;

	}
	return 0;
}
