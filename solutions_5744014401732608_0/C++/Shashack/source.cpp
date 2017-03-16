#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<climits>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;

#define y1 mine
#define mp make_pair

double pi = acos(-1);
ll power(ll a, ll b){ ll p_res = 1; while (b > 0){ if (b % 2 == 1) { p_res *= a; b--;} a *= a; b /= 2;} return p_res;}
ll n, m;
bool flag;
int adj[100][100];


int main(){
	//freopen("input.txt", "r", stdin);
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++){
		cin >> n >> m;
		flag = false;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				adj[i][j] = 0;
				if (i < j) adj[i][j] = 1;
				if (i == n || i == j) adj[i][j] = 0;
			}
		}

		ll ans = 1;
		for (int i = 1; i <= n - 2; i++){
			ll mid = 1;
			for (ll rm = n - 2, j = 1; j <= i; j++, rm--){
				mid *= rm;
				mid /= j;
				if (mid >= m){
					flag = true;
				}
			}
			ans += mid;
			if (ans >= m || mid >= m){
				flag = true;
				break;
			}
		}
		if (ans >= m){
			flag = true;
		}





		string tf = flag ? "POSSIBLE" : "IMPOSSIBLE";
		cout << "Case #" << t << ": " << tf << endl;
		if (flag){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					cout << adj[i][j];
				}
				cout << endl;
			}
		}
		
	}

	return 0;
}


