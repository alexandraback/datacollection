/*
	By: facug91
	From: 
	Name: 
	Date: 08/05/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 1000000000ll
//#define MAXN 30015

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int c[3], k;
vector<vi> ans;

void dfs (int u, vi curr) {
	if (u == 3) {
		ans.push_back(curr);
		return;
	}
	for (int i=0; i<c[u]; i++) {
		curr[u] = i+1;
		dfs(u+1, curr);
	}
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>c[0]>>c[1]>>c[2]>>k;
		ans.clear();
		cout<<"Case #"<<it<<": ";
		if (k == 1) {
			cout<<c[1]<<endl;
			for (int i=0; i<c[1]; i++) cout<<1<<" "<<i+1<<" "<<i+1<<endl;
			continue;
		} else if (k == 2) {
			c[0] = min(c[0], 2);
			c[1] = min(c[1], 2);
			c[2] = min(c[2], 2);
		}
		dfs(0, vi(3, 0));
		
		cout<<ans.size()<<endl;
		for (int i=0; i<ans.size(); i++) {
			cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
