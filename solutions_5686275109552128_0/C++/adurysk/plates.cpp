#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long int LL;
typedef vector<int> VI;

#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 2000000000
#define MOD 1000000007
#define D double
#define LD long double

#define N 112345

int p[N];

inline int solve(){
	int d, i, T, t, ans, tans;
	sd(d);
	T = 1;
	for(i = 0; i < d; i++){
		sd(p[i]);
		T = max(T, p[i]);
	}
	ans = INF;
	for(t = 1; t <= T; t++){
		tans = t;
		for(i = 0; i < d; i++){
			tans += (p[i] + t - 1) / t - 1;
		}
		ans = min(ans, tans);
	}
	return ans;
}

int main(){
	freopen("inp.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	sd(t);
	for(int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		cout<<solve()<<"\n";
	}
	return 0;
}
