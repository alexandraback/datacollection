#include <bits/stdc++.h>
using namespace std;

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

#define mp make_pair
#define pb push_back
#define put(x) { cout << #x << " = "; cout << (x) << endl; }

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef double db;

const int M = 2e3 + 15;
const int Q = 1e9 + 7;


const int ALP = 5e3 + 100;
string a[M][2];
int pr[M];
bool used[M];
vector<int> g[M];


bool dfs(int v) {
	used[v] = true;
	for (int u : g[v]) {
		if (pr[u] == -1 || (!used[pr[u]] && dfs(pr[u]))) {
			pr[u] = v;
			return true;
		}
	}
	return false;
}	

	
int main(){
    srand(time(NULL));
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(0);
		
	int T;
	cin >> T;
	for (int TT = 0; TT < T; TT++) {
		int n;
		cin >>n;


	map<string, int> ma1, ma2;

		int C1 = 0, C2 = 0;
		for (int i =0; i < M; i++)
			g[i].resize(0);
		for (int i = 0; i < n; i++) {
			cin >> a[i][0] >> a[i][1];
			if (ma1[a[i][0]] == 0)
				ma1[a[i][0]] = ++C1;
			if (ma2[a[i][1]] == 0)
				ma2[a[i][1]] = ++C2;
		   	g[ma1[a[i][0]]].pb(ma2[a[i][1]]);
		}
		int mch = 0;
		for (int i = 1; i <= C2; i++)
			pr[i] = -1;
		for (int i = 1; i <= C1; i++) {
			for (int j =1; j <= C1; j++)
				used[j] = false;
			if (dfs(i))
				mch++;
		}

		int ans = n - ((int)ma1.size() + (int)ma2.size() - mch);
		cout << "Case #" << TT + 1 << ": " << ans << "\n";
		cerr << TT << endl;
	}
		
    return 0;
}   